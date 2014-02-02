#include <api/c++/FileDialog.hpp>
#include <api/c++/Table.hpp>
#include <api/c++/TableItem.hpp>
#include <api/c++/TableColumn.hpp>
#include <api/c++/Button.hpp>
#include <api/c++/Shell.hpp>
#include <api/c++/Group.hpp>
#include <boost/filesystem.hpp>
#include <boost/date_time.hpp>
#include <curses.h>
#include <sstream>

namespace bf = boost::filesystem;
namespace bd = boost::posix_time;

namespace terminal {
  namespace toolkit {
    class FileDialog::FileDialogImpl {
    public:
      FileDialogImpl(shell_ptr parent) : 
        window_(parent),
        group_(&window_),
        table_(&group_),
        ok_(&group_),
        cancel_(&group_)
      { 
        table_.createColumn()->setText("Name");
        table_.createColumn()->setText("Date");
        table_.createColumn()->setText("Size");
      }

      ~FileDialogImpl() { 
      }

      void set_directory(const std::string &directory) {
        bf::path p(directory);
        bf::directory_iterator di(p);
        bf::directory_iterator end;

        table_.clearAll();

        for(di; di != end; di++) {
          TableItem *ti(table_.createItem());
          std::string filename(di->path().filename().generic_string());
          std::time_t time(bf::last_write_time(di->path()));
          boost::posix_time::ptime pt(boost::posix_time::from_time_t(bf::last_write_time(di->path())));
         
          ti->setText(0, di->path().filename().generic_string());
          ti->setText(1, boost::lexical_cast<std::string>(pt));
          ti->setText(2, boost::lexical_cast<std::string>(bf::file_size(di->path())));
        }
      }

      Shell window_;
      Table table_;
      Button ok_;
      Button cancel_;
      Group group_;
    };

    FileDialog::FileDialog(shell_ptr parent, Dialog::style_t style) :
      Dialog(parent, style),
      impl_(new FileDialogImpl(parent))
    {
    }

    FileDialog::FileDialog(shell_ptr parent) :
      Dialog(parent),
      impl_(new FileDialogImpl(parent))
    {
    }

    FileDialog::~FileDialog() {
      delete impl_;
    }

    void FileDialog::open() {
      impl_->set_directory("/");
      impl_->window_.paint();
    }
  }
}

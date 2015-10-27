#include <terminal/toolkit/MessageBox.hpp>
#include <terminal/toolkit/Shell.hpp>
#include <terminal/toolkit/Display.hpp>
#include <terminal/toolkit/Group.hpp>
#include <terminal/toolkit/Button.hpp>
#include <terminal/toolkit/ttcurses.h>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>

namespace terminal {
  namespace toolkit {
    struct xxx {
      xxx() {
        labels_[Dialog::MSG_OK] = L"Ok";
        labels_[Dialog::MSG_CANCEL] = L"Cancel";
        labels_[Dialog::MSG_YES] = L"Yes";
        labels_[Dialog::MSG_NO] = L"No";
        labels_[Dialog::MSG_IGNORE] = L"Ignore";
        labels_[Dialog::MSG_ABORT] = L"Abort";
        labels_[Dialog::MSG_RETRY] = L"Retry";
      }

      static xxx &instance() { return(instance_); }

      std::map<Dialog::button_t, std::wstring> labels_;
      static xxx instance_;
    };

    xxx xxx::instance_;

    static void getPreferredSize(std::wstring const &s, uint32_t &width, uint32_t &height) {
      width = 10;
      height = 5;

      std::wstring::size_type pos = 0;
      std::wstring::size_type lpos = 0;

      while((pos = s.find(L'\n', pos)) != std::wstring::npos) {
        width = std::max(width, static_cast<uint32_t>(pos - lpos));
        lpos = pos++;
        height++;
      }
    }

    struct MessageBox::MessageBoxImpl {
      MessageBoxImpl(Shell *parent, Dialog::button_t button, Dialog::icon_t icon) :
        button_(button),
        icon_(icon),
        shell_(parent, Shell::BORDER)
      {
      }

      Dialog::button_t button_;
      Dialog::icon_t icon_;
      std::wstring message_;
      std::vector<std::unique_ptr<Button> > buttons_;
      Shell shell_;
    };

    MessageBox::MessageBox(Shell *parent, Dialog::button_t button, Dialog::icon_t icon) :
      Dialog(parent),
      pimpl_(new MessageBoxImpl(parent, button, icon))
    {
    }

    MessageBox::~MessageBox() {
    }

    int MessageBox::open() {
      getParent()->open();
      uint32_t width;
      uint32_t height;

      getPreferredSize(pimpl_->message_, width, height);

      pimpl_->shell_.setBounds(0, 0, width, height);
      pimpl_->shell_.open();

      for(auto i = xxx::instance_.labels_.begin(); i != xxx::instance_.labels_.end(); i++) {
        if(pimpl_->button_ & i->first) {
          Button *b = new Button(&pimpl_->shell_);

          b->setText(i->second);
          b->setBounds(1, 1, 5, 1);
          pimpl_->buttons_.push_back(std::unique_ptr<Button>(b));
        }
      }

      pimpl_->shell_.paint();
      pimpl_->shell_.getDisplay()->readAndDispatch();

      return(0);
    }

    std::wstring const &MessageBox::getMessage() const {
      return(pimpl_->message_);
    }

    void MessageBox::setMessage(std::wstring const &message) {
      pimpl_->message_ = message;
    }
  }
}

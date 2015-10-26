#include <terminal/toolkit/FileDialog.hpp>

namespace terminal {
  namespace toolkit {
    struct FileDialog::FileDialogImpl {
      FileDialogImpl(FileDialog::style_t style) :
        style_(style),
        overwrite_(false)
      {
      }

      FileDialog::style_t style_;
      bool overwrite_;
      std::wstring file_;
      std::wstring directory_;
    };

    FileDialog::~FileDialog() {

    }

    FileDialog::FileDialog(Shell *parent, style_t style) :
      Dialog(parent),
      pimpl_(new FileDialogImpl(style))
    {
    }

    void FileDialog::setFileName(const std::wstring &file) {
      pimpl_->file_ = file;
    }

    void FileDialog::setFilterExtenstions(const std::wstring &) {

    }

    void FileDialog::setFilterIndex(uint32_t) {

    }

    void FileDialog::setFilterNames(const std::wstring &) {

    }

    void FileDialog::setFilterPath(const std::wstring &directory) {
      pimpl_->directory_ = directory;
    }

    void FileDialog::setOverwrite(bool overwrite) {
      pimpl_->overwrite_ = overwrite;
    }
  }
}


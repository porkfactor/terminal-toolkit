#ifndef TERMINAL_TOOLKIT_FILEDIALOG_HPP_
#define TERMINAL_TOOLKIT_FILEDIALOG_HPP_

#include <terminal/toolkit/Dialog.hpp>
#include <vector>

namespace terminal {
  namespace toolkit {
    class FileDialog : public Dialog {
    public:
      typedef enum {
        OPEN,
        SAVE,
        MULTI
      } style_t;

      FileDialog(Shell *, style_t style = OPEN);
      virtual ~FileDialog();

      const std::wstring &getFileName() const;
      const std::vector<std::wstring> &getFileNames() const;
      const std::vector<std::wstring> &getFilterExtensions() const;
      const std::vector<std::wstring> &getFilterNames() const;
      const std::wstring &getFilterPath() const;


      void setFileName(const std::wstring &);
      void setFilterExtenstions(const std::wstring &);
      void setFilterIndex(uint32_t);
      void setFilterNames(const std::wstring &);
      void setFilterPath(const std::wstring &);
      void setOverwrite(bool);

    private:
      struct FileDialogImpl;
      std::unique_ptr<struct FileDialogImpl> pimpl_;
    };
  }
}

#endif

#ifndef TERMINAL_TOOLKIT_FILEDIALOG_HPP_
#define TERMINAL_TOOLKIT_FILEDIALOG_HPP_

#include <terminal/toolkit/Dialog.hpp>
#include <vector>

namespace terminal
{
    namespace toolkit
    {
        class FileDialog: public Dialog
        {
        public:
            typedef enum
            {
                OPEN,
                SAVE,
                MULTI
            } style_t;

            FileDialog(Shell *, style_t style = OPEN);
            virtual ~FileDialog();

            string const &getFileName() const;
            std::vector<string> const &getFileNames() const;
            std::vector<string> const &getFilterExtensions() const;
            std::vector<string> const &getFilterNames() const;
            string const &getFilterPath() const;

            void setFileName(string const &);
            void setFilterExtenstions(string const &);
            void setFilterIndex(uint32_t);
            void setFilterNames(string const &);
            void setFilterPath(string const &);
            void setOverwrite(bool);

        private:
            FileDialog::style_t style_;
            bool overwrite_;
            string file_;
            string directory_;
        };
    }
}

#endif

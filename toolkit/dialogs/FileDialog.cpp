#include <terminal/toolkit/FileDialog.hpp>

namespace terminal
{
    namespace toolkit
    {
        struct FileDialog::impl
        {
            impl(FileDialog::style_t style) :
                        style_(style),
                        overwrite_(false)
            {
            }

            FileDialog::style_t style_;
            bool overwrite_;
            string file_;
            string directory_;
        };

        FileDialog::~FileDialog()
        {

        }

        FileDialog::FileDialog(Shell *parent, style_t style) :
            Dialog(parent),
            pimpl_(new impl(style))
        {
        }

        void FileDialog::setFileName(string const &file)
        {
            pimpl_->file_ = file;
        }

        void FileDialog::setFilterExtenstions(string const &)
        {

        }

        void FileDialog::setFilterIndex(uint32_t)
        {

        }

        void FileDialog::setFilterNames(string const &)
        {

        }

        void FileDialog::setFilterPath(string const &directory)
        {
            pimpl_->directory_ = directory;
        }

        void FileDialog::setOverwrite(bool overwrite)
        {
            pimpl_->overwrite_ = overwrite;
        }
    }
}


#include <terminal/toolkit/FileDialog.hpp>

namespace terminal
{
    namespace toolkit
    {
        FileDialog::FileDialog(Shell *parent, style_t style) :
            Dialog(parent),
            style_(style),
            overwrite_(false)
        {
        }

        FileDialog::~FileDialog()
        {

        }

        void FileDialog::setFileName(string const &file)
        {
            file_ = file;
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
            directory_ = directory;
        }

        void FileDialog::setOverwrite(bool overwrite)
        {
            overwrite_ = overwrite;
        }
    }
}


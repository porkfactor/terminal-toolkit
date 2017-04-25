#ifndef TERMINAL_TOOLKIT_MESSAGEBOX_HPP_
#define TERMINAL_TOOLKIT_MESSAGEBOX_HPP_

#include <terminal/toolkit/Dialog.hpp>
#include <terminal/toolkit/Shell.hpp>

namespace terminal
{
    namespace toolkit
    {
        class Button;
        class Shell;

        class MessageBox: public Dialog
        {
        public:
            MessageBox(Shell *, button_t = MSG_OK, icon_t = ICON_INFORMATION);
            virtual ~MessageBox();

            virtual int open();
            virtual string const &getMessage() const;
            virtual void setMessage(string const &);

        private:
            Dialog::button_t button_;
            Dialog::icon_t icon_;
            string message_;
            std::vector<std::unique_ptr<Button> > buttons_;
            Shell shell_;
        };
    }
}

#endif

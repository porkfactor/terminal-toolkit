#ifndef TERMINAL_TOOLKIT_MESSAGEBOX_HPP_
#define TERMINAL_TOOLKIT_MESSAGEBOX_HPP_

#include <terminal/toolkit/Dialog.hpp>

namespace terminal
{
    namespace toolkit
    {
        class MessageBox: public Dialog
        {
        public:
            MessageBox(Shell *, button_t = MSG_OK, icon_t = ICON_INFORMATION);
            virtual ~MessageBox();

            virtual int open();
            virtual string const &getMessage() const;
            virtual void setMessage(string const &);

        private:
            struct impl;
            impl *pimpl_;
        };
    }
}

#endif

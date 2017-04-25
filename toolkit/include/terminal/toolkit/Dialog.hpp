#ifndef TERMINAL_TOOLKIT_DIALOG_HPP_
#define TERMINAL_TOOLKIT_DIALOG_HPP_

#include "Types.hpp"

namespace terminal
{
    namespace toolkit
    {
        class Shell;

        class Dialog
        {
        public:
            typedef enum
            {
                MSG_OK = 0x1,
                MSG_CANCEL = 0x2,
                MSG_YES = 0x4,
                MSG_NO = 0x8,
                MSG_ABORT = 0x10,
                MSG_RETRY = 0x20,
                MSG_IGNORE = 0x40
            } button_t;

            typedef enum
            {
                ICON_ERROR = 0x1,
                ICON_INFORMATION = 0x2,
                ICON_QUESTION = 0x4,
                ICON_WARNING = 0x8,
                ICON_WORKING = 0x10
            } icon_t;

            Dialog(Shell *);
            virtual ~Dialog();

            Shell *getParent() const;
            string const &getText() const;
            void setText(string const &);

        private:
            string text_;
            Shell *parent_;
        };

        inline Dialog::button_t operator |(const Dialog::button_t &l, const Dialog::button_t &r)
        {
            return (static_cast<Dialog::button_t>(static_cast<uint32_t>(l) | static_cast<uint32_t>(r)));
        }

        inline Dialog::button_t operator &(const Dialog::button_t &l, const Dialog::button_t &r)
        {
            return (static_cast<Dialog::button_t>(static_cast<uint32_t>(l) & static_cast<uint32_t>(r)));
        }
    }
}

#endif

#ifndef TERMINAL_TOOLKIT_KEYS_HPP_
#define TERMINAL_TOOLKIT_KEYS_HPP_

#include "Types.hpp"

namespace terminal
{
    namespace toolkit
    {

        class Key
        {
        public:
            typedef string::value_type character_type;

            typedef enum
            {
                INVALID,
                BACKSPACE,
                DELETE,
                DELETE_LINE,
                DOWN,
                ENTER,
                ESCAPE,
                HOME,
                INSERT,
                INSERT_LINE,
                KEYPAD_0,
                KEYPAD_1,
                KEYPAD_2,
                KEYPAD_3,
                KEYPAD_4,
                KEYPAD_5,
                KEYPAD_6,
                KEYPAD_7,
                KEYPAD_8,
                KEYPAD_9,
                LEFT,
                NEXT_PAGE,
                PREVIOUS_PAGE,
                PRINT,
                RIGHT,
                TAB,
                UP,
                F1,
                F2,
                F3,
                F4,
                F5,
                F6,
                F7,
                F8,
                F9,
                F10,
                F11,
                F12,
            } virtual_key;

            explicit Key(int key);
            explicit Key(character_type character);

            virtual_key vk() const { return virtual_key_; };
            character_type code() const { return character_; };

        private:
            virtual_key virtual_key_;
            character_type character_;
        };
    }
}

#endif

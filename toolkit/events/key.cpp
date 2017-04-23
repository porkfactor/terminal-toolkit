#include <map>
#include <curses.h>
#include <terminal/toolkit/Keys.hpp>


namespace terminal
{
    namespace toolkit
    {
        static auto translate_character(int key) -> Key::character_type
        {
            return static_cast<Key::character_type>(key);
        }

        static auto translate_virtual_key(int key) -> Key::virtual_key
        {
            static std::map<int, Key::virtual_key> keys {
                { KEY_DOWN,      Key::DOWN, },
                { KEY_UP,        Key::UP, },
                { KEY_LEFT,      Key::LEFT, },
                { KEY_RIGHT,     Key::RIGHT, },
                { KEY_HOME,      Key::HOME, },
                { 0177,          Key::BACKSPACE, },
                { KEY_BACKSPACE, Key::BACKSPACE, },
                { KEY_DL,        Key::DELETE_LINE, },
                { KEY_IL,        Key::INSERT_LINE, },
                { KEY_DC,        Key::DELETE, },
                { KEY_IC,        Key::INSERT, },
                { KEY_NPAGE,     Key::NEXT_PAGE, },
                { KEY_PPAGE,     Key::PREVIOUS_PAGE, },
                { KEY_ENTER,     Key::ENTER, },
                { KEY_PRINT,     Key::PRINT, },
                { KEY_LL,        Key::KEYPAD_0, },
                { KEY_A1,        Key::KEYPAD_7, },
                { KEY_A3,        Key::KEYPAD_9, },
                { KEY_B2,        Key::KEYPAD_6, },
                { KEY_C1,        Key::KEYPAD_1, },
                { KEY_C3,        Key::KEYPAD_3, },
                { KEY_F(1),      Key::F1, },
                { KEY_F(2),      Key::F2, },
                { KEY_F(3),      Key::F3, },
                { KEY_F(4),      Key::F4, },
                { KEY_F(5),      Key::F5, },
                { KEY_F(6),      Key::F6, },
                { KEY_F(7),      Key::F7, },
                { KEY_F(8),      Key::F8, },
                { KEY_F(9),      Key::F9, },
                { KEY_F(10),     Key::F10, },
                { KEY_F(11),     Key::F11, },
                { KEY_F(12),     Key::F12, },
            };

            for(auto i = keys.find(key); i != keys.end();)
            {
                return i->second;
            }

            return Key::INVALID;
        }

        Key::Key(int key) :
            character_(translate_character(key)),
            virtual_key_(translate_virtual_key(key))
        {

        }
    }
}

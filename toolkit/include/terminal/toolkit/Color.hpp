#ifndef TERMINAL_TOOLKIT_COLOR_HPP_
#define TERMINAL_TOOLKIT_COLOR_HPP_

namespace terminal
{
    namespace toolkit
    {
        class Color
        {
        public:
            typedef enum
            {
                DEFAULT = 0,
                WHITE,
                BLACK,
                RED,
                GREEN,
                BLUE,
                YELLOW,
                MAGENTA,
                CYAN
            } color_t;

            typedef enum
            {
                NORMAL,
                BOLD,
                REVERSE,
                BLINK,
                DIM,
            } attribute_t;

            Color(
                color_t = DEFAULT,
                color_t = DEFAULT,
                attribute_t = NORMAL);

            int native() const;

        private:
            color_t foreground_;
            color_t background_;
            attribute_t attribute_;
        };
    }
}

#endif

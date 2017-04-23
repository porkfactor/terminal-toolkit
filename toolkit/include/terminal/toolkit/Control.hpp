#ifndef TERMINAL_TOOLKIT_ICONTROL_HPP_
#define TERMINAL_TOOLKIT_ICONTROL_HPP_

#include <terminal/toolkit/Widget.hpp>

namespace terminal
{
    namespace toolkit
    {
        class Color;
        class Composite;
        class Display;
        class Point;
        class Rectangle;
        class Shell;
        class FocusListener;
        class HelpListener;
        class KeyListener;
        class Key;

        class Control: public Widget
        {
            friend class Display;
        public:
            typedef enum
            {
                RIGHT_TO_LEFT,
                LEFT_TO_RIGHT
            } order_t;

            typedef enum
            {
                HORIZONTAL,
                VERITCAL
            } orientation_t;

            typedef enum
            {
                LEFT,
                RIGHT,
                CENTER
            } alignment_t;

            typedef enum
            {
                NO_BACKGROUND,
                NO_FOCUS,
                NO_MERGE_PAINTS,
                NO_REDRAW_RESIZE,
                NO_RADIO_GROUP,
                EMBEDDED,
                DOUBLE_BUFFERED
            } style_t;

            typedef uint32_t index_t;

            static index_t const npos = ~0;

            Control(Composite *parent);
            virtual ~Control();

            virtual void pack(bool = true);
            virtual void redraw();
            virtual void redraw(uint32_t, uint32_t, uint32_t, uint32_t, bool = false);
            virtual void update();

            /* State and Behaviour */
            virtual bool forceFocus();
            virtual bool isEnabled() const;
            virtual bool isVisible() const;
            virtual void setEnabled(bool = true);
            virtual bool setFocus();

            /* Appearance */
            Color getBackground() const;
            Color getForeground() const;
            void setBackgrund(Color);
            void setForeground(Color);

            /* Size and Location */
            virtual Point computeSize(uint32_t, uint32_t, bool = false) const;
            virtual Rectangle getBounds() const;
            virtual Point getLocation() const;
            virtual void setBounds(uint32_t, uint32_t, uint32_t, uint32_t, bool = true);
            virtual void setBounds(const Rectangle &);
            virtual void setLocation(uint32_t, uint32_t);
            virtual void setLocation(const Point &);
            virtual void setSize(uint32_t, uint32_t);
            virtual void setSize(const Point &);

            /* Listeners */
            virtual void addFocusListener(FocusListener *);
            virtual void addHelpListener(HelpListener *);
            virtual void addKeyListener(KeyListener *);
            virtual void removeFocusListener(FocusListener *);
            virtual void removeHelpListener(HelpListener *);
            virtual void removeKeyListener(KeyListener *);

            virtual Shell *getShell() const;
            virtual Composite *getParent() const;

            virtual uintptr_t window() const;
            virtual int color() const;

        protected:
            virtual bool handleKey(Key const &) = 0;

        private:
            struct impl;
            impl *pimpl_;
        };
    }
}

#endif

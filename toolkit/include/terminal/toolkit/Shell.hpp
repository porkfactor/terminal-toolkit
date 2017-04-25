#ifndef TERMINAL_TOOLKIT_SHELL_HPP_
#define TERMINAL_TOOLKIT_SHELL_HPP_

#include <terminal/toolkit/Composite.hpp>
#include <terminal/toolkit/ttcurses.h>

namespace terminal
{
    namespace toolkit
    {
        class cwindow;
        class Display;

        class Shell: public Composite
        {
        public:
            typedef enum
            {
                NORMAL,
                BORDER
            } style_t;

            Shell(Display *, style_t = NORMAL);
            Shell(Shell *, style_t = NORMAL);
            virtual ~Shell();

            virtual Shell *getShell() const override;
            virtual Display *getDisplay() const override;

            virtual bool getEnabled() const;
            virtual bool getFullScreen() const;
            virtual bool getModified() const;
            virtual void setEnabled(bool = true) override;
            virtual void setFullScreen(bool = true);
            virtual void setVisible(bool = true);

            virtual Rectangle getBounds() const override;
            virtual Point getLocation() const override;
            virtual Point getMinimumSize() const;
            virtual Point getSize() const;
            virtual void setMinimumSize(uint32_t, uint32_t);
            virtual void setMinimumSize(const Point &);

            virtual Control *getFocusControl() const;

            virtual bool post(Event *event);
            virtual void open();
            virtual cwindow &window() const override;

        protected:
            virtual bool handleKeyEvent(Key const &) override;

        private:
            Display *display_;
            Shell::style_t style_;
            mutable cwindow window_;
        };
    }
}

#endif

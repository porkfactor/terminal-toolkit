#include <terminal/toolkit/Display.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/Shell.hpp>
#include <terminal/toolkit/Event.hpp>
#include <terminal/toolkit/KeyEvent.hpp>
#include <terminal/toolkit/ttcurses.h>
#include <sys/select.h>

namespace terminal
{
    namespace toolkit
    {
        static Display *current_ = 0;
        static Display *default_ = 0;

        Display::Display() :
            active_(nullptr)
        {
            cwindow::initialize();
        }

        Display::~Display()
        {
            cwindow::terminate();
        }

        bool Display::sleep()
        {
            bool rv = false;
            int fd = ::fileno(stdin);
            struct timeval tv { 0, 0, };
            fd_set rfd;

            FD_ZERO(&rfd);
            FD_SET(fd, &rfd);

            switch(::select(fd + 1, &rfd, 0, 0, &tv))
            {
            case -1:
                rv = false;
                break;

            default:
                if(FD_ISSET(fd, &rfd))
                {
                    rv = true;
                }
            }

            return rv;
        }

        bool Display::readAndDispatch()
        {
            bool rv { true };

            int key;
            Shell *shell { getActiveShell() };

            shell->redraw();

            Control *control {};
            shell->paint();

            if((control = shell->getFocusControl()) != nullptr)
            {
                if(control->handleKeyEvent(Key { shell->window().getKey() }))
                {

                }
            }

            return rv;
        }

        Rectangle Display::getBounds() const
        {
            return Rectangle(0, 0, 0, 0);
        }

        Rectangle Display::getClientArea() const
        {
            return Rectangle(0, 0, 0, 0);
        }

        Shell *Display::getActiveShell() const
        {
            return active_;
        }

        void Display::setActiveShell(Shell *active)
        {
            active_ = active;
        }

        Control *Display::getFocusControl() const
        {
            return getActiveShell()->getFocusControl();
        }

        void Display::beep() const
        {

        }

        Display *Display::getCurrent()
        {
            return current_;
        }

        Display *Display::getDefault()
        {
            return default_ ? default_ : (default_ = new Display());
        }
    }
}


#include <terminal/toolkit/Shell.hpp>
#include <terminal/toolkit/Display.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/ttcurses.h>

namespace terminal
{
    namespace toolkit
    {
        Shell::Shell(Display *display, Shell::style_t style) :
                Composite(nullptr),
                display_(display),
                style_(style),
                window_(Rectangle { 0, 0, 0, 0 })
        {
        }

        Shell::Shell(Shell *parent, Shell::style_t style) :
                Composite(parent),
                display_(nullptr),
                style_(style),
                window_(parent->window(), Rectangle { 0, 0, 0, 0 })
        {

        }

        Shell::~Shell()
        {

        }

        Display *Shell::getDisplay() const
        {
            return display_;
        }

        Shell *Shell::getShell() const
        {
            return const_cast<Shell *>(this);
        }

        bool Shell::getEnabled() const
        {
            return false;
        }

        bool Shell::getFullScreen() const
        {
            return false;
        }

        bool Shell::getModified() const
        {
            return false;
        }

        void Shell::setEnabled(bool)
        {

        }

        void Shell::setFullScreen(bool)
        {

        }

        void Shell::setVisible(bool)
        {

        }

        Rectangle Shell::getBounds() const
        {
            return (Control::getBounds());
        }

        Point Shell::getLocation() const
        {
            return (Point(0, 0));
        }

        Point Shell::getMinimumSize() const
        {
            return (Point(0, 0));
        }

        Point Shell::getSize() const
        {
            return (Point(0, 0));
        }

        void Shell::setMinimumSize(uint32_t, uint32_t)
        {

        }

        void Shell::setMinimumSize(const Point &)
        {

        }

        bool Shell::handleKeyEvent(Key const &)
        {
            return false;
        }

        bool Shell::post(Event *event)
        {
            return false;
        }

        Control *Shell::getFocusControl() const
        {
            // TODO : temp bodge
            return getChildren().front();
        }

        void Shell::open()
        {
            display_->setActiveShell(this);
            Rectangle r(getBounds());

            window_.resize(r);
            window_.refresh();
        }

        cwindow &Shell::window() const
        {
            return window_;
        }
    }
}


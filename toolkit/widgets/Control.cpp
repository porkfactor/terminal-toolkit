#include <terminal/toolkit/Control.hpp>
#include <terminal/toolkit/Composite.hpp>
#include <terminal/toolkit/Shell.hpp>
#include <terminal/toolkit/Rectangle.hpp>
#include <terminal/toolkit/Point.hpp>
#include <terminal/toolkit/Color.hpp>
#include <terminal/toolkit/ttcurses.h>

namespace terminal
{
    namespace toolkit
    {
        Control::Control(Composite *parent) :
            Widget(parent),
            parent_(parent),
            bounds_(0, 0, 0, 0)
        {
            if(parent)
            {
                parent->addChild(this);
            }
        }

        Control::~Control()
        {
        }

        Color Control::getBackground() const
        {
            return (background_);
        }

        Color Control::getForeground() const
        {
            return (foreground_);
        }

        void Control::setForeground(Color fg)
        {
            foreground_ = fg;
        }

        void Control::setBackgrund(Color bg)
        {
            background_ = bg;
        }

        void Control::pack(bool)
        {

        }

        void Control::redraw()
        {
            Rectangle r(getBounds());

            redraw(r.x(), r.y(), r.width(), r.height());
        }

        void Control::redraw(uint32_t, uint32_t, uint32_t, uint32_t, bool)
        {
            paint();
        }

        void Control::update()
        {

        }

        bool Control::isEnabled() const
        {
            return (false);
        }

        bool Control::isVisible() const
        {
            return (false);
        }

        void Control::setEnabled(bool)
        {

        }

        bool Control::forceFocus()
        {
            // getShell()->setFocusControl(this);

            return (false);
        }

        bool Control::setFocus()
        {
            return (forceFocus());
        }

        /* Size and Location */
        Point Control::computeSize(uint32_t, uint32_t, bool) const
        {
            return (Point(0, 0));
        }

        Rectangle Control::getBounds() const
        {
            return (bounds_);
        }

        Point Control::getLocation() const
        {
            return (Point(bounds_.x(), bounds_.y()));
        }

        void Control::setBounds(uint32_t x, uint32_t y, uint32_t width, uint32_t height, bool)
        {
            setBounds(Rectangle(x, y, width, height));
        }

        void Control::setBounds(const Rectangle &r)
        {
            bounds_ = r;
        }

        void Control::setLocation(uint32_t, uint32_t)
        {

        }

        void Control::setLocation(const Point &p)
        {
            setLocation(p.x(), p.y());
        }

        void Control::setSize(uint32_t, uint32_t)
        {

        }

        void Control::setSize(const Point &p)
        {
            setSize(p.x(), p.y());
        }

        Shell *Control::getShell() const
        {
            return getParent()->getShell();
        }

        Composite *Control::getParent() const
        {
            return parent_;
        }

        cwindow &Control::window() const
        {
            return getParent()->window();
        }

        int Control::color() const
        {
            return 0;
        }

        void Control::addFocusListener(FocusListener *listener)
        {

        }

        void Control::addHelpListener(HelpListener *listener)
        {

        }

        void Control::addKeyListener(KeyListener *listener)
        {

        }

        void Control::removeFocusListener(FocusListener *listener)
        {

        }

        void Control::removeKeyListener(KeyListener *listener)
        {

        }

        void Control::removeHelpListener(HelpListener *listener)
        {

        }
    }
}


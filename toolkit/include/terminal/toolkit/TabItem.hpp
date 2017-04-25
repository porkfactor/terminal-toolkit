#ifndef TERMINAL_TOOLKIT_TABITEM_HPP_
#define TERMINAL_TOOLKIT_TABITEM_HPP_

#include <terminal/toolkit/Item.hpp>
#include <string>

namespace terminal
{
    namespace toolkit
    {
        class Control;
        class Image;
        class Item;
        class Rectangle;
        class TabFolder;

        class TabItem: public Item
        {
        public:
            TabItem(TabFolder *);
            virtual ~TabItem();

            Rectangle getBounds() const;
            Control *getControl() const;
            TabFolder *getParent() const;
            string const &getToolTipText() const;
            void setControl(Control *control);
            void setImage(Image *image);
            void setText(string const &string);
            void setToolTipText(string const &string);

        private:
            string text_;
            string tooltip_;
        };
    }
}

#endif

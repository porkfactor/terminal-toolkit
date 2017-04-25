#ifndef TERMINAL_TOOLKIT_SCROLLBAR_HPP_
#define TERMINAL_TOOLKIT_SCROLLBAR_HPP_

#include <terminal/toolkit/Widget.hpp>

namespace terminal
{
    namespace toolkit
    {
        class Point;
        class Scrollable;
        class SelectionListener;

        class ScrollBar: public Widget
        {
        public:
            ScrollBar(Scrollable *);
            virtual ~ScrollBar();

            Scrollable *getParent() const;

            bool getEnabled() const;
            bool isEnabled() const;

            uint32_t getIncrement() const;
            uint32_t getMaximum() const;
            uint32_t getMinimum() const;
            uint32_t getPageIncrement() const;
            uint32_t getSelection() const;

            void setIncrement(uint32_t);
            void setMaximum(uint32_t);
            void setMinimum(uint32_t);
            void setPageIncrement(uint32_t);
            void setSelection(uint32_t);

            Point getSize() const;

            void addSelectionListener(SelectionListener *);
            void removeSelectionListener(SelectionListener *);

            void paint(void) const;

        private:
            Scrollable *parent_;
            uint32_t increment_;
            uint32_t maximum_;
            uint32_t minimum_;
            uint32_t page_increment_;
            uint32_t selection_;
        };
    }
}

#endif

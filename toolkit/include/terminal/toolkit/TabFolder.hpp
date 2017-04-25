#ifndef TERMINAL_TOOLKIT_TABFOLDER_HPP_
#define TERMINAL_TOOLKIT_TABFOLDER_HPP_

#include <terminal/toolkit/Composite.hpp>

namespace terminal
{
    namespace toolkit
    {
        class SelectionListener;
        class TabItem;

        class TabFolder: public Composite
        {
        public:
            TabFolder(Composite *);
            virtual ~TabFolder();

            void addSelectionListener(SelectionListener *listener);
            Point computeSize(int wHint, int hHint, bool changed) const;
            Rectangle computeTrim(int x, int y, int width, int height) const;
            Rectangle getClientArea() const;
            TabItem *getItem(Control::index_t index) const;
            TabItem *getItem(const Point &point) const;
            uint32_t getItemCount() const;
            std::vector<TabItem *> getItems() const;
            std::vector<TabItem *> getSelection() const;
            Control::index_t getSelectionIndex() const;
            Control::index_t indexOf(const TabItem *item) const;
            void removeSelectionListener(SelectionListener *listener);
            void setSelection(Control::index_t index);
            void setSelection(TabItem *item);
            void setSelection(std::vector<TabItem *> items);

            virtual void paint() const;

        private:
            std::vector<TabItem *> items_;
        };
    }
}

#endif

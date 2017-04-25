#ifndef TERMINAL_TOOLKIT_LIST_HPP_
#define TERMINAL_TOOLKIT_LIST_HPP_

#include <terminal/toolkit/Scrollable.hpp>
#include <string>
#include <vector>

namespace terminal
{
    namespace toolkit
    {
        class SelectionListener;

        class List: public Scrollable
        {
        public:
            List(Composite *);

            void add(string const &);
            void add(string const &, Control::index_t index);
            void addSelectionListener(SelectionListener *listener);

            Point computeSize(int wHint, int hHint, bool changed) const;

            void deselect(Control::index_t index);
            void deselect(std::vector<Control::index_t> const &indices);
            void deselect(Control::index_t start, Control::index_t end);
            void deselectAll();

            Control::index_t getFocusIndex() const;
            string getItem(Control::index_t index) const;
            uint32_t getItemCount() const;
            uint32_t getItemHeight() const;
            std::vector<string> getItems() const;
            std::vector<string> getSelection() const;
            uint32_t getSelectionCount() const;
            Control::index_t getSelectionIndex() const;
            std::vector<Control::index_t> getSelectionIndices() const;
            Control::index_t getTopIndex() const;
            Control::index_t indexOf(string const &string) const;
            Control::index_t indexOf(string const &string, uint32_t start) const;
            bool isSelected(Control::index_t index) const;
            void remove(Control::index_t index);
            void remove(std::vector<Control::index_t> const &indices);
            void remove(Control::index_t start, Control::index_t end);
            void remove(string string);
            void removeAll();
            void removeSelectionListener(SelectionListener *listener);
            void select(Control::index_t index);
            void select(std::vector<Control::index_t> const &indices);
            void select(Control::index_t start, Control::index_t end);
            void selectAll();
            void setItem(Control::index_t index, string const &string);
            void setItems(std::vector<string> const &);
            void setSelection(Control::index_t index);
            void setSelection(std::vector<Control::index_t> const &indices);
            void setSelection(Control::index_t start, Control::index_t end);
            void setSelection(std::vector<string> const &);
            void setTopIndex(Control::index_t index);
            void showSelection();

        private:
            std::vector<string> items_;
        };
    }
}

#endif

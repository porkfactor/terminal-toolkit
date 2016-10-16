#ifndef TERMINAL_TOOLKIT_COMBO_HPP_
#define TERMINAL_TOOLKIT_COMBO_HPP_

#include <terminal/toolkit/Composite.hpp>
#include <string>

namespace terminal
{
    namespace toolkit
    {
        class ModifyListener;
        class SelectionListener;
        class VerifyListener;

        class Combo: public Composite
        {
        public:
            Combo(Composite *);

            void add(string const &);
            void add(string const &, uint32_t index);

            /* clipboard */
            void copy();
            void cut();
            void paste();

            /* listeners */
            void addModifyListener(ModifyListener *listener);
            void addSelectionListener(SelectionListener *listener);
            void addVerifyListener(VerifyListener *listener);
            void removeModifyListener(ModifyListener *listener);
            void removeSelectionListener(SelectionListener *listener);
            void removeVerifyListener(VerifyListener *listener);

            /* list */
            string getItem(uint32_t index) const;
            uint32_t getItemCount() const;
            uint32_t getItemHeight() const;
            std::vector<string> getItems() const;
            uint32_t indexOf(string const &string) const;
            uint32_t indexOf(string const &string, uint32_t start) const;
            void remove(uint32_t index);
            void remove(uint32_t start, uint32_t end);
            void remove(string const &string);
            void removeAll();

            /* selection */
            void clearSelection();
            void deselect(int index);
            void deselectAll();
            Point getSelection();
            int getSelectionIndex();
            void setSelection(Point selection);

            Point computeSize(int wHint, int hHint, bool changed);
            bool getListVisible();
            int getOrientation();
            string getText();
            int getTextHeight();
            int getTextLimit();
            int getVisibleItemCount();
            void select(int index);
            void setItem(int index, string string);
            void setItems(std::vector<string> &items);
            void setListVisible(bool visible);
            void setOrientation(int orientation);
            void setText(string const &string);
            void setTextLimit(int limit);
            void setVisibleItemCount(int count);

        private:
            struct impl;
            std::unique_ptr<impl> pimpl_;
        };
    }
}

#endif

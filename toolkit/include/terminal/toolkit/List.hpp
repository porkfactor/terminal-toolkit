#ifndef TERMINAL_TOOLKIT_LIST_HPP_
#define TERMINAL_TOOLKIT_LIST_HPP_

#include <terminal/toolkit/Scrollable.hpp>
#include <string>
#include <vector>

namespace terminal {
  namespace toolkit {
    class SelectionListener;

    class List : public Scrollable {
    public:
      List(Composite *);

      void add(const std::wstring &);
      void add(const std::wstring &, Control::index_t index);
      void addSelectionListener(SelectionListener *listener);

      Point computeSize(int wHint, int hHint, bool changed) const;

      void deselect(Control::index_t index);
      void deselect(const std::vector<Control::index_t> &indices);
      void deselect(Control::index_t start, Control::index_t end);
      void deselectAll();

      Control::index_t getFocusIndex() const;
      std::wstring getItem(Control::index_t index) const;
      uint32_t getItemCount() const;
      uint32_t getItemHeight() const;
      std::vector<std::wstring> getItems() const;
      std::vector<std::wstring> getSelection() const;
      uint32_t getSelectionCount() const;
      Control::index_t getSelectionIndex() const;
      std::vector<Control::index_t> getSelectionIndices() const;
      Control::index_t getTopIndex() const;
      Control::index_t indexOf(const std::wstring &string) const;
      Control::index_t indexOf(const std::wstring &string, uint32_t start) const;
      bool isSelected(Control::index_t index) const;
      void remove(Control::index_t index);
      void remove(std::vector<Control::index_t> indices);
      void remove(Control::index_t start, Control::index_t end);
      void remove(std::wstring string);
      void removeAll();
      void removeSelectionListener(SelectionListener *listener);
      void select(Control::index_t index);
      void select(std::vector<Control::index_t> indices);
      void select(Control::index_t start, Control::index_t end);
      void selectAll();
      void setItem(Control::index_t index, std::wstring string);
      void setItems(const std::vector<std::wstring> &);
      void setSelection(Control::index_t index);
      void setSelection(const std::vector<Control::index_t> &indices);
      void setSelection(Control::index_t start, Control::index_t end);
      void setSelection(const std::vector<std::wstring> &);
      void setTopIndex(Control::index_t index);
      void showSelection();

    private:
      struct impl;
      std::unique_ptr<struct impl> pimpl_;
    };
  }
}

#endif

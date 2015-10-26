#ifndef TERMINAL_TOOLKIT_COMBO_HPP_
#define TERMINAL_TOOLKIT_COMBO_HPP_

#include <terminal/toolkit/Composite.hpp>
#include <string>

namespace terminal {
  namespace toolkit {
    class ModifyListener;
    class SelectionListener;
    class VerifyListener;

    class Combo : public Composite {
    public:
      Combo(Composite *);

      void add(const std::wstring &);
      void add(const std::wstring &, uint32_t index);

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
      std::wstring getItem(uint32_t index) const;
      uint32_t getItemCount() const;
      uint32_t getItemHeight() const;
      std::vector<std::wstring> getItems() const;
      uint32_t indexOf(const std::wstring &string) const;
      uint32_t indexOf(const std::wstring &string, uint32_t start) const;
      void remove(uint32_t index);
      void remove(uint32_t start, uint32_t end);
      void remove(const std::wstring &string);
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
      std::wstring getText();
      int getTextHeight();
      int getTextLimit();
      int getVisibleItemCount();
      void select(int index);
      void setItem(int index, std::wstring string);
      void setItems(std::vector<std::wstring> &items);
      void setListVisible(bool visible);
      void setOrientation(int orientation);
      void setText(const std::wstring &string);
      void setTextLimit(int limit);
      void setVisibleItemCount(int count);

    private:
      struct impl;
      std::unique_ptr<impl> pimpl_;
    };
  }
}

#endif

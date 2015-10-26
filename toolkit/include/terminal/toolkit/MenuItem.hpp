#ifndef TERMINAL_TOOLKIT_MENUITEM_HPP_
#define TERMINAL_TOOLKIT_MENUITEM_HPP_

#include <terminal/toolkit/Item.hpp>
#include <string>

namespace terminal {
  namespace toolkit {
    class ArmListener;
    class HelpListener;
    class Image;
    class Menu;
    class SelectionListener;

    class MenuItem : public Item {
    public:
      MenuItem(Menu *);
      virtual ~MenuItem();

      void addArmListener(ArmListener *listener);
      void addHelpListener(HelpListener *listener);
      void addSelectionListener(SelectionListener *listener);
      void removeArmListener(ArmListener *listener);
      void removeHelpListener(HelpListener *listener);
      void removeSelectionListener(SelectionListener *listener);

      int getAccelerator() const;
      bool getEnabled() const;
      int getID() const;
      Menu *getMenu() const;
      Menu *getParent() const;
      bool getSelection() const;
      bool isEnabled() const;
      void setAccelerator(int accelerator);
      void setEnabled(bool enabled);
      void setID(int id);
      void setImage(Image *image);
      void setMenu(Menu *menu);
      void setSelection(bool selected);
      void setText(const std::wstring &string);

    private:
      struct impl;
      std::unique_ptr<impl> pimpl_;
    };
  }
}

#endif /* MENUITEM_HPP_ */

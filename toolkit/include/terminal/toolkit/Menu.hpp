#ifndef TERMINAL_TOOLKIT_MENU_HPP_
#define TERMINAL_TOOLKIT_MENU_HPP_

#include <terminal/toolkit/Widget.hpp>
#include <vector>

namespace terminal {
  namespace toolkit {
    class Control;
    class Decorations;
    class HelpListener;
    class Menu;
    class MenuItem;
    class MenuListener;
    class Point;
    class Shell;

    class Menu : public Widget {
      Menu(Control *);
      Menu(Menu *);
      Menu(MenuItem *);
      virtual ~Menu();

      void addHelpListener(HelpListener *listener);
      void addMenuListener(MenuListener *listener);
      void removeHelpListener(HelpListener *listener);
      void removeMenuListener(MenuListener *listener);

      MenuItem *getDefaultItem() const;
      bool getEnabled() const;
      MenuItem *getItem(uint32_t index) const;
      uint32_t getItemCount() const;
      std::vector<MenuItem *> getItems() const;
      int getOrientation() const;
      Decorations *getParent() const;
      MenuItem *getParentItem() const;
      Menu *getParentMenu() const;
      Shell *getShell() const;
      bool getVisible() const;
      int32_t indexOf(const MenuItem *item) const;
      bool isEnabled() const;
      bool isVisible() const;

      void setDefaultItem(MenuItem *item);
      void setEnabled(bool enabled);
      void setLocation(uint32_t x, uint32_t y);
      void setLocation(const Point &location);
      void setOrientation(int orientation);
      void setVisible(bool visible);

      virtual void paint() const;

    private:
      struct impl;
      std::unique_ptr<impl> pimpl_;
    };
  }
}

#endif

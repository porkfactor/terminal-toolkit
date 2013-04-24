#ifndef TERMINAL_TOOLKIT_TABLE_ITEM_HPP
#define TERMINAL_TOOLKIT_TABLE_ITEM_HPP

#include <platform/platform.hpp>
#include <api/c++/Declarations.hpp>
#include <api/c++/Item.hpp>
#include <stdint.h>

namespace terminal {
  namespace toolkit {
    class Color;

    class DLLEXPORT TableItem : public Item {
      friend class Table;
    public:
      TableItem(table_ptr table);
      virtual ~TableItem();

      Color getBackground() const;
      Color getBackground(uint32_t index) const;
      Color getForeground() const;
      Color getForeground(uint32_t index) const;

      void setBackground(Color &);
      void setBackground(uint32_t index, Color &);
      void setForeground(Color &);
      void setForeground(uint32_t index, Color &);

      const std::string &getText() const;
      const std::string &getText(uint32_t index) const;

      void setText(const std::string &);
      void setText(uint32_t index, const std::string &);

      bool getChecked() const;
      void setChecked(bool);

      bool getGreyed() const;
      void setGreyed(bool);

    protected:
      virtual void paint() const;

    private:
      class TableItemImpl;
      TableItemImpl *impl_;
    };
  }
}

#endif


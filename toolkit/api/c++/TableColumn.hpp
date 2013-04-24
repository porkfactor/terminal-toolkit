#ifndef TERMINAL_TOOLKIT_TABLE_COLUMN_HPP_
#define TERMINAL_TOOLKIT_TABLE_COLUMN_HPP_

#include <platform/platform.hpp>
#include <api/c++/Declarations.hpp>
#include <api/c++/Item.hpp>
#include <stdint.h>
#include <string>

namespace terminal {
  namespace toolkit {
    class Table;
    class ControlListener;
    class SelectionListener;

    typedef enum {
      CENTER,
      LEFT,
      RIGHT
    } alignment_t;

    class DLLEXPORT TableColumn : public Item {
      friend class Table;
    public:
      TableColumn(table_ptr parent);
      virtual ~TableColumn();

      void addSelectionListener(SelectionListener *);
      void addControlListener(ControlListener *);

      void removeSelectionListener(SelectionListener *);
      void removeControlListener(ControlListener *);

      alignment_t getAlignment() const;
      table_ptr getParent() const;
      uint16_t getWidth() const;
      bool getMoveable() const;
      bool getResizeable() const;
      const std::string &getText() const;

      void setAlignment(alignment_t a);
      void setText(const std::string &text);
      void setMoveable(bool);
      void setResizeable(bool);
      void setWidth(uint16_t width);

    protected:
      virtual void paint() const;

    private:
      class TableColumnImpl;
      TableColumnImpl *impl_;
    };
  }
}

#endif


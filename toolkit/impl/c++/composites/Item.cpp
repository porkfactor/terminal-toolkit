#include <api/c++/Item.hpp>

namespace terminal {
  namespace toolkit {
    Item::Item(widget_ptr parent) :
      Widget(parent)
    {
    }

    Item::~Item() {
    }
  }
}


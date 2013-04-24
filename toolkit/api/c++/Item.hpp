#ifndef TERMINAL_TOOLKIT_ITEM_HPP_
#define TERMINAL_TOOLKIT_ITEM_HPP_

#include <platform/platform.hpp>
#include <api/c++/Declarations.hpp>
#include <api/c++/Widget.hpp>
#include <string>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Item : public Widget {
    public:
      Item(widget_ptr parent);
      virtual ~Item();

    private:
    };
  }
}

#endif


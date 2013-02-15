#ifndef TERMINAL_TOOLKIT_IMPL_GROUP_BOX_IMPL_H_
#define TERMINAL_TOOLKIT_IMPL_GROUP_BOX_IMPL_H_

#include <impl/c++/containers/ContainerImpl.h>
#include <api/c++/Declarations.h>
#include <string>

// TODO: move crap decls like this to a common 'shit-decls.h'
struct panel;

namespace terminal {
  namespace toolkit {
    namespace impl {
      class GroupBoxImpl : public ContainerImpl {
      public:
        GroupBoxImpl(terminal::toolkit::container_ptr container);
        virtual ~GroupBoxImpl();

        const std::string &getText() const;
        void setText(const std::string &text);

        virtual void redraw();
        virtual void update();

      private:
        std::string text_;
        struct ::panel *panel_;
      };
    }
  }
}

#endif

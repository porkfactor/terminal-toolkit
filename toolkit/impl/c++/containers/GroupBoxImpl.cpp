#include <impl/c++/containers/GroupBoxImpl.h>
#include <curses.h>
#include <panel.h>

namespace terminal {
  namespace toolkit {
    namespace impl {
      GroupBoxImpl::GroupBoxImpl(terminal::toolkit::container_ptr container) :
        ContainerImpl(container)
      {
        panel_ = new_panel(0);
      }

      GroupBoxImpl::~GroupBoxImpl() {
        del_panel(panel_);
      }

      const std::string &GroupBoxImpl::getText() const {
        return(text_);
      }

      void GroupBoxImpl::setText(const std::string &text) {
        text_ = text;
      }

      void GroupBoxImpl::redraw() {
      }

      void GroupBoxImpl::update() {
        ::box(panel_->win, 0, 0);
      }
    }
  }
}


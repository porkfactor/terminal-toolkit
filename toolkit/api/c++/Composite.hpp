#ifndef TERMINAL_TOOLKIT_COMPOSITE_H_
#define TERMINAL_TOOLKIT_COMPOSITE_H_

#include <api/c++/Declarations.h>
#include <api/c++/Scrollable.h>
#include <platform/platform.h>
#include <vector>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Composite : public Scrollable {
    public:
      Composite(composite_ptr parent);
      virtual ~Composite();

      virtual std::vector<control_ptr> getChildren() const;
      virtual void layout(bool changed = true, bool all = false);
      virtual void layout(const std::vector<control_ptr> &changed);

      virtual void setLayout(layout_ptr layout);
      virtual layout_ptr getLayout() const;

    private:
      class CompositeImpl;
      CompositeImpl *impl_;
    };
  }
}

#endif


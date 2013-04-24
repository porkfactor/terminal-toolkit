#ifndef TERMINAL_TOOLKIT_COMPOSITE_H_
#define TERMINAL_TOOLKIT_COMPOSITE_H_

#include <api/c++/Declarations.hpp>
#include <api/c++/Scrollable.hpp>
#include <platform/platform.hpp>
#include <vector>

namespace terminal {
  namespace toolkit {
    class DLLEXPORT Composite : public Scrollable {
      friend class Control;
    public:
      Composite(composite_ptr parent);
      virtual ~Composite();

      virtual void getChildren(std::vector<control_ptr> &list) const;
      virtual void getTabList(std::vector<control_ptr> &list) const;
      virtual void layout(bool changed = true, bool all = false);
      virtual void layout(const std::vector<control_ptr> &changed);

      virtual void setLayout(layout_ptr layout);
      virtual layout_ptr getLayout() const;

    protected:
      virtual void paint() const;
      virtual void addChild(control_ptr);
      virtual bool handleKey(int key, Event &event);

    private:
      class CompositeImpl;
      CompositeImpl *impl_;
    };
  }
}

#endif


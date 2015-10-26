#ifndef TERMINAL_TOOLKIT_COMPOSITE_HPP_
#define TERMINAL_TOOLKIT_COMPOSITE_HPP_

#include <terminal/toolkit/Scrollable.hpp>
#include <vector>

namespace terminal {
  namespace toolkit {
    class Layout;

    class Composite : public Scrollable {
      friend class Control;
    public:
      Composite(Composite *);
      virtual ~Composite();

      virtual Point computeSize(uint32_t, uint32_t, bool = false) const;
      virtual void layout(bool = true, bool = true);

      virtual Layout *getLayout() const;
      virtual bool setFocus();
      virtual void setLayout(Layout *);
      virtual void setLayoutDeferred(bool);

      virtual void paint() const;

      const std::vector<Control *> &getChildren() const;
      const std::vector<Control *> &getTabList() const;

    protected:
      virtual void addChild(Control *child);
      bool handleKeyEvent(int, Event &);

    private:
      struct CompositeImpl;
      std::unique_ptr<CompositeImpl> pimpl_;
    };
  }
}

#endif

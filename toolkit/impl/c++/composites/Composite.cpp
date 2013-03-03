#include <api/c++/Composite.h>

namespace terminal {
  namespace toolkit {
    class Composite::CompositeImpl {
    public:
      CompositeImpl(composite_ptr parent) {
      }

      ~CompositeImpl() {
      }

    private:
    };

    Composite::Composite(terminal::toolkit::composite_ptr parent) :
      Scrollable(parent),
      impl_(new CompositeImpl(parent))
    {
    }

    Composite::~Composite() {
      delete impl_;
    }

    std::vector<control_ptr> Composite::getChildren() const {
      return(std::vector<control_ptr>());
    }

    layout_ptr Composite::getLayout() const {
      return(layout_ptr());
    }

    void Composite::setLayout(layout_ptr layout) {
    }

    void Composite::layout(bool changed, bool all) {
    }

    void Composite::layout(const std::vector<control_ptr> &changed) {
    }
  }
}

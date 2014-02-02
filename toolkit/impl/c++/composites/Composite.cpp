#include <api/c++/Composite.hpp>

namespace terminal {
  namespace toolkit {
    class Composite::CompositeImpl {
    public:
      CompositeImpl(composite_ptr parent) :
        focus_(0)
      {
      }

      ~CompositeImpl() {
      }

      control_ptr focus_;
      std::vector<control_ptr> children_;
    };

    Composite::Composite(terminal::toolkit::composite_ptr parent) :
      Scrollable(parent),
      impl_(new CompositeImpl(parent))
    {
    }

    Composite::~Composite() {
      delete impl_;
    }

    void Composite::getChildren(std::vector<control_ptr> &list) const {
      list.resize(impl_->children_.size());
      std::copy(impl_->children_.begin(), impl_->children_.end(), list.begin());
    }

    void Composite::getTabList(std::vector<control_ptr> &list) const {
      list.resize(impl_->children_.size());
      std::copy(impl_->children_.begin(), impl_->children_.end(), list.begin());
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

    void Composite::addChild(control_ptr child) {
      if(child) {
        impl_->children_.push_back(child);
        impl_->focus_ = child;
      }
    }

    void Composite::paint() const {
      std::vector<control_ptr>::const_iterator i;

      for(i = impl_->children_.begin(); i != impl_->children_.end(); i++) {
        (*i)->paint();
      }
    }

    bool Composite::handleKey(int key, Event &event) {
      bool rv = false;

      if(impl_->focus_) {
        rv = impl_->focus_->handleKey(key, event);
      }

      return(rv);
    }
  }
}

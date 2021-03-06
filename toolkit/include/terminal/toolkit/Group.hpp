#ifndef TERMINAL_TOOLKIT_GROUP_HPP_
#define TERMINAL_TOOLKIT_GROUP_HPP_

#include <terminal/toolkit/Composite.hpp>
#include <string>

namespace terminal {
  namespace toolkit {
    class Group : public Composite {
    public:
      Group(Composite *);
      virtual ~Group();

      virtual Point computeSize(uint32_t, uint32_t, bool = false) const;
      virtual Rectangle computeTrim(uint32_t, uint32_t, uint32_t, uint32_t) const;
      virtual Rectangle getClientArea() const;

      void setText(const std::wstring &);
      const std::wstring &getText() const;

    protected:
      virtual void paint() const;

    private:
      struct GroupImpl;
      std::unique_ptr<GroupImpl> pimpl_;
    };
  }
}



#endif

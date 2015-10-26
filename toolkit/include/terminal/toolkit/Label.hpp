#ifndef TERMINAL_TOOLKIT_LABEL_HPP_
#define TERMINAL_TOOLKIT_LABEL_HPP_

#include <terminal/toolkit/Control.hpp>
#include <string>

namespace terminal {
  namespace toolkit {
    class Image;

    class Label : public Control {
    public:
      Label(Composite *parent);
      virtual ~Label();

      Point computeSize(uint32_t, uint32_t, bool) const;
      Control::alignment_t getAlignment() const;
      const Image *getImage() const;
      const std::wstring &getText() const;
      void setAlignment(Control::alignment_t);
      void setImage(const Image *);
      void setText(const std::wstring &);

      virtual void paint(void) const;

    private:
      struct impl;
      std::unique_ptr<impl> pimpl_;
    };
  }
}

#endif

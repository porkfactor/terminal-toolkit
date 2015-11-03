#ifndef TERMINAL_TOOLKIT_BUTTON_HPP_
#define TERMINAL_TOOLKIT_BUTTON_HPP_

#include <terminal/toolkit/Control.hpp>
#include <string>

namespace terminal {
  namespace toolkit {
  	class SelectionListener;

    class Button : public Control {
    public:
      Button(Composite *parent);
      virtual ~Button();

      virtual Point computeSize(uint32_t, uint32_t, bool) const;

      Control::alignment_t getAlignment() const;
      virtual bool getGreyed() const;
      virtual bool getSelection() const;

      virtual void setGreyed(bool);
      virtual void setSelection(bool);
      void setAlignment(Control::alignment_t);
      virtual bool setFocus();

      virtual const std::wstring &getText() const;
      virtual void setText(const std::wstring &);

      void addSelectionListener(SelectionListener *);
      void removeSelectionListener(SelectionListener *);

    protected:
      virtual bool handleKeyEvent(int, Event const &);
      void paint() const;

    private:
      struct ButtonImpl;
      std::unique_ptr<ButtonImpl> pimpl_;
    };
  }
}

#endif

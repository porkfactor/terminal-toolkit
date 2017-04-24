#ifndef TERMINAL_TOOLKIT_PROGRESS_HPP_
#define TERMINAL_TOOLKIT_PROGRESS_HPP_

#include <terminal/toolkit/Control.hpp>
#include <memory>

namespace terminal {
  namespace toolkit {
    class ProgressBar : public Control {
    public:
      typedef enum {
        SMOOTH,
        HORIZONTAL,
        VERTICAL,
        INDETERMINATE
      } style_t;

      ProgressBar(Composite *parent, style_t = HORIZONTAL);
      virtual ~ProgressBar();

      Point computeSize(uint32_t, uint32_t, bool = false) const override;
      uint32_t getMaximum() const;
      uint32_t getMinimum() const;
      uint32_t getSelection() const;

      void setMaximum(uint32_t);
      void setMinimum(uint32_t);
      void setSelection(uint32_t);

    protected:
      virtual bool handleKeyEvent(Key const &key) override;
      virtual void paint() const override;

    private:
      struct impl;
      std::unique_ptr<impl> pimpl_;
    };
  }
}



#endif

#ifndef TERMINAL_TOOLKIT_PROGRESS_HPP_
#define TERMINAL_TOOLKIT_PROGRESS_HPP_

#include <terminal/toolkit/Control.hpp>
#include <memory>

namespace terminal {
  namespace toolkit {
    class ProgressBar : public Control {
    public:
      enum ProgressBarStyle {
        SMOOTH,
        HORIZONTAL,
        VERTICAL,
        INDETERMINATE
      };

      ProgressBar(Composite *parent, enum ProgressBarStyle);
      virtual ~ProgressBar();

      Point computeSize(uint32_t, uint32_t, bool = false) const;
      uint32_t getMaximum() const;
      uint32_t getMinimum() const;
      uint32_t getSelection() const;

      void setMaximum(uint32_t);
      void setMinimum(uint32_t);
      void setSelection(uint32_t);

    protected:
      virtual void paint() const;

    private:
      struct ProgressBarImpl;
      std::unique_ptr<ProgressBarImpl> pimpl_;
    };
  }
}



#endif

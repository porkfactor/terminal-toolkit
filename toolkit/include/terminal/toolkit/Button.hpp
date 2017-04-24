#ifndef TERMINAL_TOOLKIT_BUTTON_HPP_
#define TERMINAL_TOOLKIT_BUTTON_HPP_

#include "Control.hpp"

namespace terminal
{
    namespace toolkit
    {
        class SelectionListener;

        class Button: public Control
        {
        public:
            Button(Composite *parent);
            virtual ~Button();

            virtual Point computeSize(uint32_t, uint32_t, bool) const override;

            Control::alignment_t getAlignment() const;
            virtual bool getGreyed() const;
            virtual bool getSelection() const;

            virtual void setGreyed(bool);
            virtual void setSelection(bool);
            void setAlignment(Control::alignment_t);
            virtual bool setFocus() override;

            virtual const string &getText() const;
            virtual void setText(string const &);

            void addSelectionListener(SelectionListener *);
            void removeSelectionListener(SelectionListener *);

        protected:
            virtual bool handleKeyEvent(Key const &) override;
            void paint() const override;

        private:
            struct impl;
            impl *pimpl_;
        };
    }
}

#endif

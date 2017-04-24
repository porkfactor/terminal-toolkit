#ifndef TERMINAL_TOOLKIT_TEXT_HPP_
#define TERMINAL_TOOLKIT_TEXT_HPP_

#include <terminal/toolkit/Scrollable.hpp>
#include <string>

namespace terminal
{
    namespace toolkit
    {
        class Event;
        class ModifyListener;
        class SelectionListener;
        class VerifyListener;

        class Text: public Scrollable
        {
        public:
            Text(Composite *);
            virtual ~Text();

            /* Clipboard */
            void cut();
            void copy();
            void paste();

            /* Control-specific behaviour */
            uint32_t getLineCount() const;
            string const &getText() const;
            size_t getTextLimit() const;
            void setText(string const &);
            void setTextLimit(size_t);

            /* caret */
            uint32_t getCaretLineNumber() const;
            Point getCaretLocation() const;
            uint32_t getCaretPosition() const;

            /* selection */
            void clearSelection();
            Point getSelection() const;
            uint32_t getSelectionCount() const;
            string getSelectionText() const;
            void setSelection(uint32_t, uint32_t = ~0U);
            void setSelection(Point const &);

            /* listeners */
            void addModifyListener(ModifyListener *);
            void addSelectionListener(SelectionListener *);
            void addVerifyListener(VerifyListener *);
            void removeModifyListener(ModifyListener *);
            void removeSelectionListener(SelectionListener *);
            void removeVerifyListener(VerifyListener *);

        protected:
            virtual void paint() const override;
            bool handleKeyEvent(Key const &) override;

        private:
            struct impl;
            impl *pimpl_;
        };
    }
}

#endif /* TEXT_HPP_ */

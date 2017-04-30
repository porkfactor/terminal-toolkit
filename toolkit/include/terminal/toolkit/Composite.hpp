#ifndef TERMINAL_TOOLKIT_COMPOSITE_HPP_
#define TERMINAL_TOOLKIT_COMPOSITE_HPP_

#include <terminal/toolkit/Scrollable.hpp>
#include <vector>

namespace terminal
{
    namespace toolkit
    {
        class Layout;

        class Composite: public Scrollable
        {
            friend class Control;
        public:
            Composite(Composite *);
            virtual ~Composite();

            virtual Point computeSize(uint32_t, uint32_t, bool = false) const override;
            virtual void layout(bool = true, bool = true);

            virtual Control *getFocusControl() const;
            virtual Layout *getLayout() const;
            virtual bool setFocus() override;
            virtual void setLayout(Layout *);
            virtual void setLayoutDeferred(bool);

            virtual void paint() const override;

            std::vector<Control *> const &getChildren() const;
            std::vector<Control *> const &getTabList() const;


        protected:
            virtual void addChild(Control *child);
            bool handleKeyEvent(Key const &) override;

            bool focusFirst();
            bool focusLast();
            bool focusNext();
            bool focusPrevious();

        private:
            std::vector<Control *> children_;
            std::vector<Control *> tab_list_;
            Control *focus_;
        };
    }
}

#endif

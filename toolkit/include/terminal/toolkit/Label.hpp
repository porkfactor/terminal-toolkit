#ifndef TERMINAL_TOOLKIT_LABEL_HPP_
#define TERMINAL_TOOLKIT_LABEL_HPP_

#include <terminal/toolkit/Control.hpp>
#include <string>

namespace terminal
{
    namespace toolkit
    {
        class Image;

        class Label: public Control
        {
        public:
            Label(Composite *parent);
            virtual ~Label();

            Point computeSize(uint32_t, uint32_t, bool) const;
            Control::alignment_t getAlignment() const;
            const Image *getImage() const;
            string const &getText() const;
            void setAlignment(Control::alignment_t);
            void setImage(const Image *);
            void setText(string const &);

            virtual void paint(void) const;

        private:
            struct impl;
            impl *pimpl_;
        };
    }
}

#endif

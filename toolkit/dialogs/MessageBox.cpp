#include <terminal/toolkit/MessageBox.hpp>
#include <terminal/toolkit/Shell.hpp>
#include <terminal/toolkit/Display.hpp>
#include <terminal/toolkit/Group.hpp>
#include <terminal/toolkit/Button.hpp>
#include <terminal/toolkit/SelectionListener.hpp>
#include <terminal/toolkit/ttcurses.h>
#include <vector>
#include <algorithm>
#include <map>

namespace terminal
{
    namespace toolkit
    {
        class MessageBoxSelectionListener: public SelectionListener
        {
        public:
            MessageBoxSelectionListener() :
                    complete_(false)
            {

            }

            virtual void handleEvent(Event const &)
            {

            }

            virtual void widgetDefaultSelected(SelectionEvent const &)
            {

            }

            virtual void widgetSelected(SelectionEvent const &)
            {
                complete_ = true;
            }

            bool complete() const
            {
                return complete_;
            }

        private:
            bool complete_;
        };

        struct xxx
        {
            xxx()
            {
                labels_[Dialog::MSG_OK] = L"Ok";
                labels_[Dialog::MSG_CANCEL] = L"Cancel";
                labels_[Dialog::MSG_YES] = L"Yes";
                labels_[Dialog::MSG_NO] = L"No";
                labels_[Dialog::MSG_IGNORE] = L"Ignore";
                labels_[Dialog::MSG_ABORT] = L"Abort";
                labels_[Dialog::MSG_RETRY] = L"Retry";
            }

            static xxx &instance()
            {
                return (instance_);
            }

            std::map<Dialog::button_t, string> labels_;
            static xxx instance_;
        };

        xxx xxx::instance_;

        static void getPreferredSize(string const &s, uint32_t &width, uint32_t &height)
        {
            width = 10;
            height = 5;

            string::size_type pos{ 0 };
            string::size_type lpos{ 0 };

            while((pos = s.find(L'\n', pos)) != string::npos)
            {
                width = std::max(width, static_cast<uint32_t>(pos - lpos));
                lpos = pos++;
                height++;
            }
        }

        MessageBox::MessageBox(Shell *parent, Dialog::button_t button, Dialog::icon_t icon) :
            Dialog(parent),
            button_(button),
            icon_(icon),
            shell_(parent, Shell::BORDER)
        {
        }

        MessageBox::~MessageBox()
        {
        }

        int MessageBox::open()
        {
            getParent()->open();
            uint32_t width;
            uint32_t height;

            MessageBoxSelectionListener selectionListener;

            getPreferredSize(message_, width, height);

            shell_.setBounds(0, 0, width, height);
            shell_.open();

            for(auto i = xxx::instance_.labels_.begin(); i != xxx::instance_.labels_.end(); i++)
            {
                if(button_ & i->first)
                {
                    std::unique_ptr<Button> b(new Button(&shell_));

                    b->setText(i->second);
                    b->setBounds(1, 1, 5, 1);
                    b->addSelectionListener(&selectionListener);

                    buttons_.emplace_back(std::move(b));
                }
            }

            shell_.paint();

            while(!selectionListener.complete())
            {
                if(!shell_.getDisplay()->readAndDispatch())
                {
                    shell_.getDisplay()->sleep();
                }
            }

            return 0;
        }

        string const &MessageBox::getMessage() const
        {
            return message_;
        }

        void MessageBox::setMessage(string const &message)
        {
            message_ = message;
        }
    }
}

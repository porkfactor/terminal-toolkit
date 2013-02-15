#ifndef _TERMINAL_TOOLKIT_MESSAGE_BOX_H
#define _TERMINAL_TOOLKIT_MESSAGE_BOX_H

namespace terminal {
  namespace toolkit {
    class MessageBox {
    public:
      virtual ~MessageBox();

    private:
      struct pimpl;
      pimpl *impl_;
    };
  }
}

#endif


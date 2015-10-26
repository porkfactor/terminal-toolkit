#ifndef TERMINAL_TOOLKIT_EVENT_HPP_
#define TERMINAL_TOOLKIT_EVENT_HPP_

#include <cstdint>
#include <string>

namespace terminal {
  namespace toolkit {
    class Display;
    class Widget;

    class Event {
    public:

      int button;
      char character;
      int count;
      int detail;
      Display *display;
      bool doit;
      int end;
      uint32_t height;
      uint32_t index;
      Widget *item;
      int keyCode;
      int keyLocation;
      double magnification;
      double rotation;
      int start;
      int stateMask;
      std::wstring text;
      int time;
      int type;
      Widget *widget;
      uint32_t width;
      uint32_t x;
      int32_t xDirection;
      uint32_t y;
      int32_t yDirection;
    };
  }
}

#endif

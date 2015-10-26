#ifndef TERMINAL_TOOLKIT_KEYEVENT_HPP_
#define TERMINAL_TOOLKIT_KEYEVENT_HPP_

#include <terminal/toolkit/TypedEvent.hpp>
#include <stdint.h>

namespace terminal {
  namespace toolkit {
    class KeyEvent : public TypedEvent {
    public:
      static uint32_t const VK_CANCEL = 3;
      static uint32_t const VK_BACK_SLASH = 8;
      static uint32_t const VK_ENTER = 10;
      static uint32_t const VK_CONTROL = 17;
      static uint32_t const VK_ALT = 18;
      static uint32_t const VK_ESCAPE = 27;
      static uint32_t const VK_ACCEPT = 30;

      static uint32_t const VK_HOME = 36;
      static uint32_t const VK_LEFT = 37;
      static uint32_t const VK_UP = 38;
      static uint32_t const VK_RIGHT = 39;
      static uint32_t const VK_DOWN = 40;

      static uint32_t const VK_COMMA = 44;
      static uint32_t const VK_MINUS = 45;
      static uint32_t const VK_PERIOD = 46;
      static uint32_t const VK_SLASH = 47;
      static uint32_t const VK_0 = 48;
      static uint32_t const VK_1 = 49;
      static uint32_t const VK_2 = 50;
      static uint32_t const VK_3 = 51;
      static uint32_t const VK_4 = 52;
      static uint32_t const VK_5 = 53;
      static uint32_t const VK_6 = 54;
      static uint32_t const VK_7 = 55;
      static uint32_t const VK_8 = 56;
      static uint32_t const VK_9 = 57;

      static uint32_t const VK_A = 65;
      static uint32_t const VK_B = 66;
      static uint32_t const VK_C = 67;
      static uint32_t const VK_D = 68;
      static uint32_t const VK_E = 69;
      static uint32_t const VK_F = 70;
      static uint32_t const VK_G = 71;
      static uint32_t const VK_H = 72;
      static uint32_t const VK_I = 73;
      static uint32_t const VK_J = 74;
      static uint32_t const VK_K = 75;
      static uint32_t const VK_L = 76;
      static uint32_t const VK_M = 77;
      static uint32_t const VK_N = 78;
      static uint32_t const VK_O = 79;
      static uint32_t const VK_P = 80;
      static uint32_t const VK_Q = 81;
      static uint32_t const VK_R = 82;
      static uint32_t const VK_S = 83;
      static uint32_t const VK_T = 84;
      static uint32_t const VK_U = 85;
      static uint32_t const VK_V = 86;
      static uint32_t const VK_W = 87;
      static uint32_t const VK_X = 88;
      static uint32_t const VK_Y = 89;
      static uint32_t const VK_Z = 90;
      static uint32_t const VK_OPEN_BRACKET = 91;
      static uint32_t const VK_CLOSE_BRACKET = 92;

      static uint32_t const VK_NUMPAD0 = 96;
      static uint32_t const VK_NUMPAD1 = 97;
      static uint32_t const VK_NUMPAD2 = 98;
      static uint32_t const VK_NUMPAD3 = 99;
      static uint32_t const VK_NUMPAD4 = 100;
      static uint32_t const VK_NUMPAD5 = 101;
      static uint32_t const VK_NUMPAD6 = 102;
      static uint32_t const VK_NUMPAD7 = 103;
      static uint32_t const VK_NUMPAD8 = 104;
      static uint32_t const VK_NUMPAD9 = 105;
      static uint32_t const VK_MULTIPLY = 106;
      static uint32_t const VK_ADD = 107;
      static uint32_t const VK_SEPARATOR = 108;
      static uint32_t const VK_SUBTRACT = 109;
      static uint32_t const VK_DECIMAL = 110;
      static uint32_t const VK_DIVIDE = 111;
      static uint32_t const VK_F1 = 112;
      static uint32_t const VK_F2 = 113;
      static uint32_t const VK_F3 = 114;
      static uint32_t const VK_F4 = 115;
      static uint32_t const VK_F5 = 116;
      static uint32_t const VK_F6 = 117;
      static uint32_t const VK_F7 = 118;
      static uint32_t const VK_F8 = 119;
      static uint32_t const VK_F9 = 120;
      static uint32_t const VK_F10 = 121;
      static uint32_t const VK_F11 = 122;
      static uint32_t const VK_F12 = 123;

      KeyEvent(Event const &);

      char character;
      bool doit;
      int keyCode;
      int keyLocation;
      int stateMask;
    };
  }
}

#endif

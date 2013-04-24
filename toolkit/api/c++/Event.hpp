#ifndef TERMINAL_TOOLKIT_EVENT_HPP_
#define TERMINAL_TOOLKIT_EVENT_HPP_

#include <platform/platform.hpp>
#include <stdint.h>

namespace terminal {
  namespace toolkit {
    typedef enum {
      None = 0,
      KeyDown = 1,
      KeyUp = 2,
      MouseDown = 3,
      MouseUp = 4,
      MouseMove = 5,
      MouseEnter = 6,		
      MouseExit = 7,
      MouseDoubleClick = 8,	
      Paint = 9,	
      Move = 10,
      Resize = 11,
      Dispose = 12,
      Selection = 13,
      DefaultSelection = 14,
      FocusIn = 15,
      FocusOut = 16,
      Expand = 17,
      Collapse = 18,
      Iconify = 19,
      Deiconify = 20,
      Close = 21,
      Show = 22,
      Hide = 23,
      Modify = 24,
      Verify = 25,
      Activate = 26,
      Deactivate = 27,	
      Help = 28,
      DragDetect = 29,
      Arm = 30,
      Traverse = 31,
      MouseHover = 32,
      HardKeyDown = 33,
      HardKeyUp = 34,
      MenuDetect = 35,
      SetData = 36,
      MouseVerticalWheel = 37,
      MouseHorizontalWheel = 38,
      MouseWheel = MouseVerticalWheel,
      Settings = 39,
      EraseItem = 40,
      MeasureItem = 41,
      PaintItem = 42,	
      ImeComposition = 43,
      OrientationChange = 44,
      Skin = 45,
      OpenDocument = 46,
      Touch = 47,
      Gesture = 48,
      Segments = 49
    } EventType;


    class DLLEXPORT Event {
    public:
      virtual ~Event();

      uint16_t x() const;
      uint16_t y() const;
      uint16_t width() const;
      uint16_t height() const;
      uint32_t keycode() const;

    private:
      uint16_t x_;
      uint16_t y_;
      uint16_t width_;
      uint16_t height_;
      uint32_t keycode_;
      EventType type_;
    };
  }
}

#endif

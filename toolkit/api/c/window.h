#ifndef _TERMINAL_API_C_WINDOW_H
#define _TERMINAL_API_C_WINDOW_H

#include <stdlib.h>
#include <stdint.h>

typedef struct terminal_window_s {
  void (*refresh)(struct terminal_window_s *);
  void (*write)(uint16_t x, uint16_t y, const char *format, ...);

  intptr_t handle;
} terminal_window_t;

#endif


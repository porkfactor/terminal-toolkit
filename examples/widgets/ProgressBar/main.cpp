#include <terminal/toolkit/ProgressBar.hpp>
#include <terminal/toolkit/Shell.hpp>
#include <terminal/toolkit/Display.hpp>

namespace tt = terminal::toolkit;

int main(int argc, char **argv) {
  tt::Display display;
  tt::Shell shell(&display);
  tt::ProgressBar transitive(&shell);
  uint32_t i = 0;

  transitive.setBounds(4, 4, 20, 1);
  transitive.setMinimum(0);
  transitive.setMaximum(100);
  transitive.setSelection(50);

  shell.open();

  while(true) {
    if(display.readAndDispatch()) {
      i = (i + 1) % 100;
      display.sleep();
      transitive.setSelection(i);
    }
  }

  return 0;
}

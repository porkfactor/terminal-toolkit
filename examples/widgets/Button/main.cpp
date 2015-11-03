#include <terminal/toolkit/Button.hpp>
#include <terminal/toolkit/Shell.hpp>
#include <terminal/toolkit/Display.hpp>

namespace tt = terminal::toolkit;

int main(int argc, char **argv) {
  tt::Display display;
  tt::Shell shell(&display);
  tt::Button b(&shell);

  b.setText(L"Test");

  shell.open();

  while(true) {
    if(!display.readAndDispatch()) {
      display.sleep();
    }
  }

  return 0;
}


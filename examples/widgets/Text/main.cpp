#include <terminal/toolkit/Text.hpp>
#include <terminal/toolkit/Shell.hpp>
#include <terminal/toolkit/Display.hpp>

namespace tt = terminal::toolkit;

int main(int argc, char **argv) {
  tt::Display display;
  tt::Shell shell(&display);
  tt::Text t1(&shell);
  tt::Text t2(&shell);

  t1.setBounds(4, 4, 40, 1);
  t2.setBounds(4, 6, 40, 1);

  shell.open();

  while(true) {
    if(!shell.getDisplay()->readAndDispatch()) {
      shell.getDisplay()->sleep();
    }
  }

  return 0;
}

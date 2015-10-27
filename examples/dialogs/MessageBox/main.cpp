#include <terminal/toolkit/MessageBox.hpp>
#include <terminal/toolkit/Display.hpp>
#include <terminal/toolkit/Shell.hpp>

namespace tt = terminal::toolkit;

int main(int argc, char **argv) {
  tt::Display d;
  tt::Shell s(&d);
  tt::MessageBox mb(&s);

  mb.open();

  return 0;
}

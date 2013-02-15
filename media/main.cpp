#include <stdint.h>
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>

#include <api/c++/windows/Window.h>
#include <api/c++/containers/GroupBox.h>
#include <api/c++/controls/Text.h>
#include <api/c++/controls/Label.h>
#include <api/c++/controls/Button.h>

namespace tt = terminal::toolkit;

int main(int argc, char **argv) {
  ::setlocale(LC_ALL, "");

  tt::Window win(0, 0, 80, 24);
#if 1
  tt::GroupBox box(&win);
  tt::GroupBox box2(&box);
  tt::Text t1(&box);
  tt::Label l1(&box);
  tt::Button b1(&box);

  box.setText("cocks");
  box2.setText("tits");
#endif

  getch();

  win.setBounds(0, 0, 80, 24);
  win.update();


  Sleep(3000);

  return(0);
}

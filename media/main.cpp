#include <stdint.h>
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>

#include <api/c++/Shell.h>
#include <api/c++/Group.h>
#include <api/c++/Text.h>
#include <api/c++/Label.h>
#include <api/c++/Button.h>
#include <api/c++/Display.h>

namespace tt = terminal::toolkit;

int main(int argc, char **argv) {
  ::setlocale(LC_ALL, "");

  tt::Display display;
  tt::Shell shell;

  tt::Group box(&shell);
  tt::Group box2(&box);
  tt::Text t1(&box);
  tt::Label l1(&box);
  tt::Button b1(&box);

  box.setText("cocks");
  box2.setText("tits");

  shell.setSize(80, 24);
  box.setBounds(0, 0, 80, 24);
  box2.setBounds(1, 1, 78, 22);
  shell.redraw();


  Sleep(3000);

  return(0);
}

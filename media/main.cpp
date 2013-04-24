#include <stdint.h>
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>
#include <wincon.h>

#include <api/c++/Shell.hpp>
#include <api/c++/Group.hpp>
#include <api/c++/Text.hpp>
#include <api/c++/Label.hpp>
#include <api/c++/Button.hpp>
#include <api/c++/Terminal.hpp>
#include <api/c++/FileDialog.hpp>

namespace tt = terminal::toolkit;

int main(int argc, char **argv) {
  ::setlocale(LC_ALL, "");

  tt::Terminal terminal;
  tt::Shell shell(&terminal);
  tt::FileDialog fd(&shell);
  
#if 0
  tt::Group box(&shell);
  tt::Group box2(&box);
  tt::Text t1(&box2);
  tt::Text t2(&box2);
  tt::Label l1(&box2);
  tt::Button b1(&box2);

  box.setText("cocks");
  box2.setText("tits");
#endif

  shell.setSize(80, 24);

  fd.open();

  /* temp : PD Curses doesn't set sensible console modes in raw raw raw */
  if(::SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_WINDOW_INPUT | ENABLE_INSERT_MODE) == 0) {
    exit(1);
  }

  //   ::Sleep(3000);

  while(true || !shell.isDisposed())
    terminal.readAndDispatch();

  return(0);
}

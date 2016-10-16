#include <terminal/toolkit/MessageBox.hpp>
#include <terminal/toolkit/Display.hpp>
#include <terminal/toolkit/Shell.hpp>

namespace tt = terminal::toolkit;

static void message_box_ok(tt::Display const &d, tt::string const &s) {
  tt::MessageBox mb(d.getActiveShell(), tt::Dialog::MSG_OK);

  mb.setMessage(s);
  mb.open();
}

static void message_box_ok_cancel(tt::Display const &d, tt::string const &s) {
  tt::MessageBox mb(d.getActiveShell(), tt::Dialog::MSG_OK | tt::Dialog::MSG_CANCEL);

  mb.setMessage(s);
  mb.open();
}

int main(int argc, char **argv) {
  tt::Display d;
  tt::Shell s(&d);

  // TODO: shouldn't require this!
  d.setActiveShell(&s);

  message_box_ok(d, L"Select Me!");
  message_box_ok_cancel(d, L"Select Me!");


  return 0;
}

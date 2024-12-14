#include <FL/Fl.H>

#include <cstdio>

#include "wnd.hpp"

int main(int argc, char **argv) {
  wnd *app_wnd = new wnd(240, 170, "Server App");
  app_wnd->show(argc, argv);

  app_wnd->setIPAddr("127.0.0.1");
  app_wnd->setPort("8080");
  app_wnd->addLog("test msg");

  return Fl::run();
}
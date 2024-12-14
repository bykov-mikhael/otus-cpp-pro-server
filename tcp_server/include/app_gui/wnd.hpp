#pragma once

#include <FL/Enumerations.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>

#include <memory>

#include "definition.hpp"

class wnd : public Fl_Window {
 public:
  wnd(int W, int H, const char *L);

  void setIPAddr(const char *IPAddr);
  void setPort(const char *Port);
  void setStatus(ServerStatus &ServerStatus);
  void addLog(const char *Message);

 private:
  // Group: Server App
  std::unique_ptr<Fl_Group> m_grp;
  // Server param label:
  std::unique_ptr<Fl_Box> m_Param_label;
  // IPaddr label:
  std::unique_ptr<Fl_Box> m_IPAddr_label;
  // IPaddr value:
  std::unique_ptr<Fl_Box> m_IPAddr_value;
  // Port label:
  std::unique_ptr<Fl_Box> m_Port_label;
  // Port value:
  std::unique_ptr<Fl_Box> m_Port_value;
  // Status label:
  std::unique_ptr<Fl_Box> m_Status_label;
  // Status value:
  std::unique_ptr<Fl_Box> m_Status_value;
  // Server log:
  std::unique_ptr<Fl_Box> m_Server_log;
  // Button: on server
  std::unique_ptr<Fl_Button> m_on_button;
  // Button: off server
  std::unique_ptr<Fl_Button> m_off_button;

  // Window app
  Fl_Window *m_windows;
};

/**
 * @brief
 *
 */
// Fl_Window *window = new Fl_Window(340,180);
//   Fl_Box *box = new Fl_Box(20,40,300,100,"Hello, World!");
//   box->box(FL_UP_BOX);
//   box->labelfont(FL_BOLD+FL_ITALIC);
//   box->labelsize(36);
//   box->labeltype(FL_SHADOW_LABEL);
//   window->end();
//   window->show(argc, argv);
//   return Fl::run();
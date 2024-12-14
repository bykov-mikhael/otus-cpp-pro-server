#include "wnd.hpp"

#include <FL/Enumerations.H>

wnd::wnd(int W, int H, const char *L) : Fl_Window(W, H, L) {
  // Server param label:
  m_Param_label = std::make_unique<Fl_Box>(m_Param_label_x, m_Param_label_y,
                                           m_Param_label_W, m_Param_label_H,
                                           m_Param_label_L);

  m_Param_label->align(FL_ALIGN_CENTER);
  m_Param_label->box(FL_UP_BOX);

  // IPaddr label:
  m_IPAddr_label = std::make_unique<Fl_Box>(m_IPAddr_label_x, m_IPAddr_label_y,
                                            m_IPAddr_label_W, m_IPAddr_label_H,
                                            m_IPAddr_label_L);

  m_IPAddr_label->align(FL_ALIGN_CENTER);
  m_IPAddr_label->box(FL_UP_BOX);

  // IPaddr value:
  m_IPAddr_value = std::make_unique<Fl_Box>(m_IPAddr_value_x, m_IPAddr_value_y,
                                            m_IPAddr_value_W, m_IPAddr_value_H,
                                            m_IPAddr_value_L);
  m_IPAddr_value->align(FL_ALIGN_CENTER);
  m_IPAddr_value->box(FL_UP_BOX);

  // Port label:
  m_Port_label =
      std::make_unique<Fl_Box>(m_Port_label_x, m_Port_label_y, m_Port_label_W,
                               m_Port_label_H, m_Port_label_L);

  m_Port_label->align(FL_ALIGN_CENTER);
  m_Port_label->box(FL_UP_BOX);

  // Port value:
  m_Port_value =
      std::make_unique<Fl_Box>(m_Port_value_x, m_Port_value_y, m_Port_value_W,
                               m_Port_value_H, m_Port_value_L);

  m_Port_value->align(FL_ALIGN_CENTER);
  m_Port_value->box(FL_UP_BOX);

  // Status label:
  m_Status_label = std::make_unique<Fl_Box>(m_Status_label_x, m_Status_label_y,
                                            m_Status_label_W, m_Status_label_H,
                                            m_Status_label_L);

  m_Status_label->align(FL_ALIGN_CENTER);
  m_Status_label->box(FL_UP_BOX);

  // Status value:
  m_Status_value = std::make_unique<Fl_Box>(m_Status_value_x, m_Status_value_y,
                                            m_Status_value_W, m_Status_value_H,
                                            m_Status_value_L);
  m_Status_value->align(FL_ALIGN_CENTER);
  m_Status_value->box(FL_UP_BOX);

  // Server log:
  m_Server_log =
      std::make_unique<Fl_Box>(m_Server_log_x, m_Server_log_y, m_Server_log_W,
                               m_Server_log_H, m_Server_log_L);

  m_Server_log->align(FL_ALIGN_CENTER);
  m_Server_log->box(FL_UP_BOX);

  // m_Test_button = std::make_unique<Fl_Button>(0, 10, 50, 20, "Button 001");
  // m_Test_button->show();

  // m_Test_button->callback();

  // Fl_Light_Button *lbutton = new Fl_Light_Button(20, 20, 50, 20);
  // lbutton->show();

  // Fl_Input *input = new Fl_Input(50, 50, 100, 50, "label");
  // input->value("Now is the time for all good men...");

  end();
}

// Fl_Window *window = new Fl_Window(340,180);
//   Fl_Box *box = new Fl_Box(20,40,300,100,"Hello, World!");
//   box->box(FL_UP_BOX);
//   box->labelfont(FL_BOLD+FL_ITALIC);
//   box->labelsize(36);
//   box->labeltype(FL_SHADOW_LABEL);
//   window->end();
//   window->show(argc, argv);
//   return Fl::run();
/*
void button_cb(Fl_Widget *widget, void *data) {
  Fl_Button *button = (Fl_Button *)widget;
  button->label("Thank you");
}
Intmain(intargc, char **argv) {
  ... Fl_Button *button = new Fl_Button(50, 70, 200, 40, "Click Me");
  button->callback(button_cb);
  ...
}
*/

void wnd::setIPAddr(const char *IPAddr) { m_IPAddr_value->label(IPAddr); }

void wnd::setPort(const char *Port) { m_Port_value->label(Port); }

void wnd::setStatus(ServerStatus &ServerStatus) {
  switch (ServerStatus) {
    case 0:
      m_Status_value->label("On");
      m_Status_value->labelcolor(FL_GREEN);
      break;
    case 1:
      m_Status_value->label("Off");
      m_Status_value->labelcolor(FL_RED);
      break;
    default:
      m_Status_value->label("Unknown status");
      m_Status_value->labelcolor(FL_RED);
  }
}

void wnd::addLog(const char *Message) { m_Server_log->label(Message); }
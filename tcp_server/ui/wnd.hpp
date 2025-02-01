#pragma once

#include <gtkmm-3.0/gtkmm.h>

class FrmMain : public Gtk::Window {
 protected:
  Glib::RefPtr<Gtk::Builder> builder;
  Gtk::Button *btnOk;
  Gtk::Button *btnCancel;
  Gtk::Button *btnClose;
  Gtk::Label *lblNotice;
  Gtk::Entry *entLog;

 public:
  FrmMain(BaseObjectType *cobject,
          const Glib::RefPtr<Gtk::Builder> &refGlade);  // constructor

 protected:
  // signal handlers
  void on_ok_button_clicked();
  void on_cancel_button_clicked();
  void on_btn_Close_clicked();
  void on_ent_Log_changed();
};

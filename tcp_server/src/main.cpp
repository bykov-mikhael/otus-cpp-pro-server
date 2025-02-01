#include "main.hpp"

#include <gtkmm.h>

void thGUI() { std::cout << "thread gui" << std::endl; }

void task2() { std::cout << "task 2" << std::endl; }

/**
 * TODO использовать MVC паттерн
 */

int main(int argc, char* argv[]) {
  // Get the current time as a time_point
  auto now = std::chrono::system_clock::now();

  // Convert time_point to time_t
  std::time_t now_c = std::chrono::system_clock::to_time_t(now);

  // Convert time_t to local time
  std::tm* local_time = std::localtime(&now_c);

  // Output the local time in a readable format
  std::cout << "Current local time: "
            << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << std::endl;

  prm* app_prm = new prm("./prm/app_prm.json");
  app_prm->set_ipaddr("127.0.0.1");
  app_prm->set_port("8081");
  app_prm->save();

  app_prm->put("test", "name", "mikhail");
  app_prm->put("test", "sname", "bykov");

  std::string ipaddr = app_prm->get("settings", "ipaddr");
  std::string port = app_prm->get("settings", "port");

  std::cout << ipaddr << std::endl;

  std::cout << port << std::endl;

  /*
   * TCP Server
   *
   */

  // TODO перенести код сервера

  /*
   * std::thread
   */

  // TODO выделить в отдельную секуцию обработку подключения клиентов
  // ? coroutines
  // ? thread

  std::thread GUI(thGUI);
  std::thread t2(task2);

  GUI.join();
  t2.join();

  std::cout << "Started" << std::endl;

  Gtk::Main kit(argc, argv);

  Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
  try {
    builder->add_from_file(
        //"/home/usr/Documents/git/cpp-gtkmm/ui/gui.glade");
        "../ui/gui.glade");
  } catch (const Glib::FileError& ex) {
    std::cerr << "Ошибка файла: " << ex.what() << std::endl;
    return 1;
  } catch (const Gtk::BuilderError& ex) {
    std::cerr << "Ошибка сборщика: " << ex.what() << std::endl;
    return 1;
  }

  FrmMain* frm = 0;
  builder->get_widget_derived("frmMain", frm);
  kit.run(*frm);

  std::cout << "End" << std::endl;
}
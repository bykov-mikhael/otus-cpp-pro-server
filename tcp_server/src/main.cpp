#include "main.hpp"

int thGUI() {
  std::cout << "thread gui" << std::endl;

  return Fl::run();
}

void task2() { std::cout << "task 2" << std::endl; }

int main() {
  // Get the current time as a time_point
  auto now = std::chrono::system_clock::now();

  // Convert time_point to time_t
  std::time_t now_c = std::chrono::system_clock::to_time_t(now);

  // Convert time_t to local time
  std::tm *local_time = std::localtime(&now_c);

  // Output the local time in a readable format
  std::cout << "Current local time: "
            << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << std::endl;

  prm *app_prm = new prm("./prm/app_prm.json");
  app_prm->set_ipaddr("127.0.0.1");
  app_prm->set_port("8081");
  app_prm->save();

  app_prm->put("test", "name", "mikhail");
  app_prm->put("test", "sname", "bykov");

  std::string ipaddr = app_prm->get("settings", "ipaddr");
  std::string port = app_prm->get("settings", "port");

  std::cout << ipaddr << std::endl;

  std::cout << port << std::endl;

  wnd *app_wnd = new wnd(240, 170, "Server App");

  app_wnd->setIPAddr(ipaddr.c_str());
  app_wnd->setPort(port.c_str());
  app_wnd->addLog("test msg");

  app_wnd->show();

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
}
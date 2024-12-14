#include "View.hpp"

#include <iostream>

void View::add_listner(std::shared_ptr<IController> controller) {
  m_controller = controller;
}

void View::showObject() { ; }

void View::addObject() { ; }

void View::createDocument() {
  m_controller->createDocument();
  std::cout << "view -> createDocument" << std::endl;
}

void View::exportDocument() {
  m_controller->exportDocument();
  std::cout << "view -> exportDocument" << std::endl;
}

void View::importDocument() {
  m_controller->createDocument();
  std::cout << "view -> importDocument" << std::endl;
}

void View::addGraphObject() {
  m_controller->addGraphObject();
  std::cout << "view -> addGraphObject" << std::endl;
}

void View::removeGraphObject() {
  m_controller->removeGraphObject();
  std::cout << "view -> removeGraphObject" << std::endl;
}
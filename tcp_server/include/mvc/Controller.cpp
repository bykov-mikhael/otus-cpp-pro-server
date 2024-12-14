#include "Controller.hpp"

#include <iostream>
#include <memory>

Controller::Controller(std::shared_ptr<IModel> model,
                       std::shared_ptr<IView> view)
    : m_model{model}, m_view{view} {}

void Controller::createDocument() {
  std::cout << "controller -> createDocument" << std::endl;
  m_model->createDocument();
}

void Controller::exportDocument() {
  std::cout << "controller -> exportDocument" << std::endl;
  m_model->exportDocument();
}

void Controller::importDocument() {
  std::cout << "controller -> importDocument" << std::endl;
  m_model->importDocument();
}

void Controller::addGraphObject() {
  std::cout << "controller -> addGraphObject" << std::endl;
  m_model->addGraphObject();
}

void Controller::removeGraphObject() {
  std::cout << "controller -> removeGraphObject" << std::endl;
  m_model->removeGraphObject();
}
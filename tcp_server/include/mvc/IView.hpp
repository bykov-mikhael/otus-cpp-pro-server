#pragma once

#include <memory>

#include "IController.hpp"

class IView {
 public:
  virtual void add_listner(std::shared_ptr<IController>) = 0;
  virtual void showObject() = 0;
  virtual void addObject() = 0;
  virtual void createDocument() = 0;
  virtual void exportDocument() = 0;
  virtual void importDocument() = 0;
  virtual void addGraphObject() = 0;
  virtual void removeGraphObject() = 0;
};
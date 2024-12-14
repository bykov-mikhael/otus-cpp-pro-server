#pragma once

#include <memory>

class IController {
 public:
  virtual void createDocument() = 0;
  virtual void exportDocument() = 0;
  virtual void importDocument() = 0;
  virtual void addGraphObject() = 0;
  virtual void removeGraphObject() = 0;
};
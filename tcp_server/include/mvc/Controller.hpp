#pragma once

#include <memory>

#include "IController.hpp"
#include "IModel.hpp"
#include "IView.hpp"

class Controller : public IController {
 public:
  Controller(std::shared_ptr<IModel>, std::shared_ptr<IView>);

  void createDocument() override;
  void exportDocument() override;
  void importDocument() override;
  void addGraphObject() override;
  void removeGraphObject() override;

 private:
  std::shared_ptr<IModel> m_model;
  std::shared_ptr<IView> m_view;
};
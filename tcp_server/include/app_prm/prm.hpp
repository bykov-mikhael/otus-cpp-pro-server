#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ptree_fwd.hpp>
#include <cstdio>
#include <filesystem>
#include <string>

class prm {
 public:
  prm(std::filesystem::path filepath);

  void save();
  void load();
  // TODO сделать шаблонную функцию для гибкости добавления любых параметров
  void put(const std::string &parent, const std::string &child,
           const std::string &value);
  // TODO сделать шаблонную функцию для гибкости добавления любых параметров
  std::string get(const std::string &parent, const std::string &child);

  void set_filepath(std::filesystem::path &filepath);
  auto get_filepath() const;
  void set_ipaddr(const std::string &ipaddr);
  auto get_ipaddr() const;
  void set_port(const std::string port);
  auto get_port() const;

 private:
  std::filesystem::path _filepath;
  std::string _ipaddr;
  int _port;
  boost::property_tree::ptree _pt;
};
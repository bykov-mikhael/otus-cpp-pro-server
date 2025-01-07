#include "prm.hpp"

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <iostream>
#include <string>

prm::prm(std::filesystem::path filepath) : _filepath(filepath) {}

void prm::put(const std::string &parent, const std::string &child,
              const std::string &value) {
  std::string sprm = parent;
  sprm.append(".");
  sprm.append(child);
  _pt.put(sprm, value);

  try {
    boost::property_tree::write_json(_filepath, _pt);
  } catch (const std::exception &e) {
    std::cerr << "Error wrsiting JSON: " << e.what() << std::endl;
  }
}

std::string prm::get(const std::string &parent, const std::string &child) {
  try {
    boost::property_tree::write_json(_filepath, _pt);
  } catch (const std::exception &e) {
    std::cerr << "Error reading JSON: " << e.what() << std::endl;
  }

  std::string sprm = parent;
  sprm.append(".");
  sprm.append(child);

  return _pt.get<std::string>(sprm);
}

void prm::save() {
  _pt.put("settings.ipaddr", _ipaddr);
  _pt.put("settings.port", _port);

  try {
    boost::property_tree::write_json(_filepath, _pt);
  } catch (const std::exception &e) {
    std::cerr << "Error wrsiting JSON: " << e.what() << std::endl;
  }
}

void prm::set_filepath(std::filesystem::path &filepath) {
  _filepath = filepath;
}

auto prm::get_filepath() const { return _filepath; }

void prm::set_ipaddr(const std::string &ipaddr) { _ipaddr = ipaddr; }

auto prm::get_ipaddr() const { return _ipaddr; }

void prm::set_port(std::string port) { _port = std::stoi(port); }

auto prm::get_port() const { return _port; }
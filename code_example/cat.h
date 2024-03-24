#pragma once
#include <iostream>
#include <string>

class Cat {
 private:
  /* data */
  std::string name;

 public:
  Cat(/* args */) = delete;
  Cat(std::string name);
  ~Cat();

  void get_info() const {
    std::cout << "this is :" + name << " cat, miao miao" << std::endl;
  }
};

Cat::Cat(std::string _name) : name(_name) {
  std::cout << "construct cat" << name << std::endl;
}

Cat::~Cat() { std::cout << "desconstruct cat: " << name << std::endl; }

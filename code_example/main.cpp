#include <iostream>
#include <memory>
#include <string>

#include "cat.h"

int main(int argc, char *argv[]) {
  Cat *cat_1 = new Cat("xiao hei");
  // unique_ptr构造函数,传递指针
  // std::unique_ptr<Cat> up_1{cat_1};
  // std::unique_ptr<Cat> up_1{new Cat("xiao hong")};
  // 推荐使用std::make_unique对指针进行初始化
  // 在调用 std::make_unique 时，通过 Args 包传入构造函数的参数会被转发给类型 T 的构造函数，以生成相应的对象实例。
  std::unique_ptr<Cat> up_1 = std::make_unique<Cat>("xiao hui");
  // 为防止再使用原始制作，需要置空再delete
  cat_1 = nullptr;
  delete cat_1;
  up_1.get()->get_info();
  // 可以用std::move把一个unique_ptr管理的内存给到另一个，原来的unique_ptr不能再使用，否则段错误
  std::unique_ptr<Cat> up_2{std::move(up_1)};
  up_2.get()->get_info();
  return 0;
}
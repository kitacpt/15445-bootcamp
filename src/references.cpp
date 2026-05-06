/**
 * @file references.cpp
 * @author Abigale Kim (abigalek)
 * @brief Tutorial code for references.
 */

// A reference in C++ is a method of creating an alias to a variable, where
// these aliases refer to the same data in memory. References are useful for
// keeping track of state, passing arguments into functions, and for general
// performance improvements. In general, it is important to understand
// references to do well in this class.

// Includes std::cout (printing) for demo purposes.
#include <iostream>

// A function that takes an int reference and adds 3 to it.
void add_three(int &a) { a = a + 3; }

int main() {
  // Take this expression. Note that b has type int& (int reference),
  // since it is a reference to a. This means that a and b both refer to the
  // same data. You can declare references by setting your variables type via
  // the single ampersand syntax.
  int a = 10;
  int &b = a;

  // As stated, if we try to print b, we will get 10.
  std::cout << "b is " << b << std::endl;

  // References can also be passed into functions. Take the function add_three,
  // which takes in an int reference and adds 3 to it. If we call this function,
  // on a, since a is being taken as a reference, then a's value in the caller
  // context will change value.
  add_three(a);
  std::cout << "a is " << a << std::endl;

  add_three(b);
  std::cout << "b is " << b << std::endl;
  std::cout << "a is " << a << std::endl;

  return 0;
}

// 引用的本质：
// 引用（reference）本质上是一个已存在变量的"别名"（alias），编译器通常将其
// 实现为一个被自动解引用的 const 指针。它在创建时必须绑定到一个对象，且一旦
// 绑定就不能再改绑到其他对象，因此引用本身没有独立的内存地址语义——它和被引
// 用的变量共享同一块内存。
//
// 两个典型用途：
// 1. 作为函数参数，避免拷贝并允许函数修改调用方的变量（pass-by-reference）。
//    例如上面的 add_three(int &a)，既省去了大对象的拷贝开销，也能直接改写实参。
// 2. 作为返回值或别名，给复杂表达式或容器元素起一个简短的名字，便于读写。
//    例如 `int &x = matrix[i][j];` 之后对 x 的读写就等同于对 matrix[i][j]
//    的读写，既提升可读性，也避免重复求值。

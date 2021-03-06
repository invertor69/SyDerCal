#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

#include "../include/nullary/Const.h"
#include "../include/nullary/X.h"
#include "../include/unary/Exp.h"
#include "../include/unary/Sin.h"

using namespace std;

int main() {
  // first set of functions
  auto &func1 = *new Exp(*new X()) * *new X() - *new Sin(*new X());
  // another way how to write it
  // auto &func2 = (*new Exp(*new X())).Mul(*new X()).Sub(*new Sin(*new X()));
  auto &func2 = *new Exp(*new X()) * *new X() * *new Sin(*new X());
  cout << "f(x) = " << func1.ToString() << endl;
  cout << "g(x) = " << (string) func2 << endl;
  cout << "f(0) = " << func1.Evaluate(0) << endl;
  cout << "f(1) = " << func1(1) << endl;
  cout << "g(0) = " << func2.Evaluate(0) << endl;
  cout << "g(1) = " << func2(1) << endl;

  // their derivations
  auto &d_func = func1.Derive();
  auto &d_alt_func = func2.Derive();
  cout << "f'(x) = " << (string) d_func << endl;
  cout << "g'(x) = " << (string) d_alt_func << endl;
  cout << "f'(0) = " << d_func(0) << endl;
  cout << "f'(1) = " << d_func(1) << endl;
  cout << "g'(0) = " << d_alt_func(0) << endl;
  cout << "g'(1) = " << d_alt_func(1) << endl;
  cout << endl;

  // sin(x) operation test
  auto &func3 = (*new Sin(*new X())) / (*new X());
  cout << "h(x) = " << (string) func3 << endl;
  cout << "h(0) = " << func3(0) << endl;
  cout << "h(x->0) = " << func3.Limit(0) << endl;
  cout << "h(pi/2) = " << func3(M_PI_2) << endl;
  auto &d_func3 = func3.Derive();
  cout << "h'(x) = " << (string) d_func3 << " = " << (string) d_func3.Simplify() << endl;
  cout << "h'(0) = " << d_func3(0) << endl;
  cout << "h'(pi/2) = " << d_func3(M_PI_2) << endl;
  cout << endl;

  // pow() operation test
  auto &func4 = (*new X()) ^(*new Const(3));
  cout << "k(x) = " << (string) func4 << endl;
  cout << "k(0) = " << func4(0) << endl;
  cout << "k(pi/2) = " << func4(M_PI_2) << endl;
  auto &d_func4 = func4.Derive();
  cout << "k'(x) = " << (string) d_func4 << endl;
  cout << "k'(0) = " << d_func4(0) << endl;
  cout << "k'(pi/2) = " << d_func4(M_PI_2) << endl;
  cout << endl;

  // simplify test 1
  auto &func5 = (*new Const(1)) * (*new X()) * (*new Const(1));
  cout << "s1(x) = " << (string) func5 << " = " << (string) func5.Simplify() << endl;

  auto &func6 = (*new Const(1)) + ((*new Const(1)) * (*new X()) * (*new Const(1))) - (*new Const(0));
  cout << "s2(x) = " << (string) func6 << " = " << (string) func6.Simplify() << endl;

  // simplify test 2
  auto &func7 = (*new Const(0)) * (*new X()) * (*new Const(1)) / (*new Const(1));
  cout << "s3(x) = " << (string) func7 << " = " << (string) func7.Simplify() << endl;

  auto &func8 = (*new Const(1)) + ((*new Const(1)) * (*new X()) * (*new Const(0)));
  cout << "s4(x) = " << (string) func8 << " = " << (string) func8.Simplify() << endl;

  return 0;
}
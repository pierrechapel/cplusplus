#include<iostream>
#include "calculette.h"
#include "test.h"


int main (int argc, char* argv []) {
  std::cout << rpn_eval(argc-1, argv+1);
  test();
  return 0;
}
#include<iostream>
#include "calculette.h"


int main (int argc, char* argv []) {
  std::cout << rpn_eval(argc-1, argv+1);
  return 0;
}
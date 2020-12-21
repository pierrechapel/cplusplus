#include "int_stack.h"
#include <iostream>

int main(){
    int_stack st1 (100);
    int_stack& rst = st1;
    int_stack st2 (rst);
    st1.push(10);
    st2.push(20);
    st1.print_stack();
    st2.print_stack();
    return 0;
}
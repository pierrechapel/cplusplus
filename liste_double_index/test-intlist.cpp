#include <iostream>
#include "intlist.h"

int main(){
    Intlist l;
    l.add_front(5);
    l.add_front(5);
    
    //std::cout<<l.is_empty()<<'\n';
    l.print_list();
    return 0;
}
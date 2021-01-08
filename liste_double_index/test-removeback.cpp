#include <iostream>
#include "intlist.h"

int main(){
    Intlist l;
    
    l.add_back(6);
    l.add_back(7);
    l.remove_back();
    
    
    //std::cout<<l.is_empty()<<'\n';
    l.print_list();
    return 0;
}
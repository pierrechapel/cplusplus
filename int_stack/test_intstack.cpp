#include <iostream>
#include "int_stack.h"

int main(){
    try{ 
    int_stack stack(5);
    stack.pop();
    for(int i=0; i=6;i++){
        stack.push(5);
    }
    stack.print_stack();
    std::cout<<"le dernier élément de la pile est " << stack.pop()<<'\n';
    
    } catch(const char* msg){
        std::cerr<<msg<<'\n';
    }


    




    return 0;
}
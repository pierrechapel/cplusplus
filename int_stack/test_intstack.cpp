#include <iostream>
#include "int_stack.h"

int main(){
    try{
    int_stack stack(-5);
    } catch(const char* msg){
        std::cerr<<msg<<'\n';
    }

    try{
        stack.pop();
    }catch(const char* msg){
        std::cerr<<msg<<std::endl;
    }
    
    try{
        for(int i=0; i=6;i++){
            stack.push(5);
        }
    }catch(const char* msg){
        std::cerr<<msg<<std::endl;
    }

    stack.print_stack();
    std::cout<<"le dernier élément de la pile est " << stack.pop()<<'\n';

    stack.delete_stack();

    return 0;
}
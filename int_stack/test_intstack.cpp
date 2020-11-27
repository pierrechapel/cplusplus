#include <iostream>
#include "int_stack.h"

int main(){
  // vr: mettez les tests dans une fonction de test et appelez la
  // fonction dans votre main, comme cela vous pourrez ré-utiliser
  // cette fonction dans d'autres occasionsq
    try{
    int_stack stack(-5);
    } catch(const char* msg){
        std::cerr<<msg<<'\n';
    }

    // vr: le bloc dans lequel vous avez défini la variable stack est
    // fermé et de toutes les manières vous ne pourriez pas
    // ré-utiliser la pile stack puisqu'elle a une taille négative

    // Ainsi, si vous voulez continuer à tester votre code vous devez,
    // dans chaque try, redéfinir une variable stack lui appliquer
    // d'autres tests

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

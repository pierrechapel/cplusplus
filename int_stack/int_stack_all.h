#include <iostream>
class int_stack{



public:

int_stack (int size ): top(0), size(size){
    if (size > 0){
        tab = new int [size];
    }
    else{
        throw "une pile de longueur négative, vraiment?";
    }
}
  
int_stack (const int_stack& rst) : size(rst.size), top(rst.top), tab(new int [size]) {
    
    for(int i=0; i<top;i++){
        tab[i]=rst.tab[i];
    }
}



bool is_empty(){
    return top==0;
}
bool is_full(){
    return top==size;
}


void push (int token) {
    if(not is_full()){
        tab[top] = token; 
        top = top + 1;
    }
    else{
        
        throw "la pile est pleine, poussez pas!";
    }
    
}
int pop () {
    if(not is_empty()){
        top = top - 1;
        return tab[top];
    }
    else{
        
        throw "la pile est vide, popez pas!";
    }
    
}
void print_stack () {
  std::cout << '[';
  for (int i = 0; i < top; i++)
    std::cout << tab[i] << ' ';
  std::cout << '[' << std::endl;
}

~int_stack () {
    delete [] tab;
}

private:
int top;
int size;
int* tab;




};
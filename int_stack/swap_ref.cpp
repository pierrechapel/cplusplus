#include <iostream>

void swap_ref(int& x, int& y){
    int i=x;
    
    x=y;
    y=i;


}

int main(){
    int a =11;
    int b= 22;
    int& ra=a;
    int& rb=b;
    std::cout<< a<< b<< '\n';
    swap_ref(ra,rb);
    std::cout<< a<< b<< '\n';
}
#include <iostream>
#include "calculette.h"

void test(){
    bool addition_correcte = true;
    bool soustraction_correcte = true;
    bool multiplication_correcte = true;
    bool division_correcte = true;
    char* tab [3];
    for(int i=1; i<10; i++){
        for(int j=1;j<10; j++){
            
            *tab[0]= i;
            *tab[1]= j;
            *tab[2]= '+';
            if(rpn_eval(3, tab) !=i+j){
                addition_correcte=false;
            }
            *tab[2]='-';
            if(rpn_eval(3, tab) !=i-j){
                soustraction_correcte=false;
            }
            *tab[2]='x';
            if(rpn_eval(3, tab) != i*j){
                multiplication_correcte=false;
            }
            *tab[2]='/';
            if(rpn_eval(3, tab) != i/j){
                division_correcte=false;
            }
        }

    }

    std::cout<< "addition"<< '\t'<< addition_correcte <<'\n';
    std::cout<< "soustraction"<< '\t'<< soustraction_correcte <<'\n';
    std::cout<< "multiplication"<< '\t'<< multiplication_correcte <<'\n';
    std::cout<< "division"<< '\t'<< division_correcte <<'\n';


}
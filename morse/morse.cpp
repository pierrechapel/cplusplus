#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "morse.h"

int main(){
    message truc( "/home/pierrechapel/c++/repo devoirs/cplusplus/morse", "test.txt");
    truc.code();
    

    message_code machin( "/home/pierrechapel/c++/repo devoirs/cplusplus/morse", "message_code.txt");
    machin.decode();
    return 0;
}
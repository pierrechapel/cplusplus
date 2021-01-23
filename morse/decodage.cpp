#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "morse.h"

int main(){
	string directory_path = "/home/pierrechapel/c++/repo devoirs/cplusplus/morse";
	string name_wav = "message_morse.wav";
	
	std::ofstream out("message_morse_transcrit.txt");
	std::ifstream in(name_wav, std::ifstream::binary);
	in.seekg(44, std::ios::beg); //on saute le header du .wav pour accéder directement aux données
	
	uint32_t fsize = in.tellg(); //on calcule la longueur du fichier sans son header
	in.seekg(0, std::ios::end);
	fsize = (uint32_t)in.tellg() - fsize;
	in.seekg(44, std::ios::beg);

  int16_t d;
  int longueur_espace = 0 ;//variable qui va détecter si il s'agit d'un espace entre points/tirets, lettres ou entre mots
  for (int i = 0; i < fsize; ++i) {
    // on lit les valeurs des données
    in.read(reinterpret_cast<char *>(&d), sizeof(int16_t));
    if (d==0){
        longueur_espace += 1;
    }
    if (d != 0 and longueur_espace == 0) {
        out<<"1";
    
    }
    else if (d != 0 and longueur_espace < 9000) {
        out<<" "; //espace entre des ti/tah
        longueur_espace = 0;
    }
    else if (d != 0 and longueur_espace < 27000) {
        out<<" &"; //espace entre des lettres
        out<<" ";
        longueur_espace = 0;
    }
    else if (d != 0 and longueur_espace < 7*9000) {
        out<<" ?"; //espace entre des mots
        out<< " ";
        longueur_espace = 0;    
    }
    
  }
  out<<" !";
  
  
  std::ifstream in2("message_morse_transcrit.txt");
  std::ofstream out2("message_en_morse.txt");
  
  string mot = "L";
  int taille=0;

  
  while(in2>>mot){
    
    taille = mot.size();
    if (mot == "&") {
        out2<<" ";
    }
    else if (mot == "!") {
        out2<<"!";
    }
    else if (mot == "?") {
        out2<<" ? ";
    }
    else if (taille<9000){
        out2<<".";
    }
    else if (taille<27000){
        out2<<"_";
    }
    
  }
  
  out2<<" !";
  
  out2.close();
  
  message_code message1(directory_path,"message_en_morse.txt");
  message1.decode();
  
  
  
  

return 0;


}
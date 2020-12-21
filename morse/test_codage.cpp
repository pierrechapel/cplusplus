#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

int main()
{
   ifstream message("/home/pierrechapel/c++/repo devoirs/cplusplus/morse/test.txt");
   ofstream message_code("/home/pierrechapel/c++/repo devoirs/cplusplus/morse/test_morse.txt");

   if(message and message_code)
   {
      //L'ouverture des deux fichiers s'est bien passée, on peut donc lire et écrire

      char lettre; //Une variable pour stocker les lettres lues
      message.get(lettre);
      while( lettre != '!') //Tant qu'on n'est pas à la fin signalé par un point d'exclamation, on lit
      {
         switch(lettre){// on code lettre par lettre dans le fichier code.
            case 'a' :
               message_code << "._ ";
               break;
            case 'b' :
               message_code << "_... ";
               break;
            case 'c' :
               message_code << "_._. ";
               break;
            case 'd' :
               message_code << "_.. ";
               break;
            case 'e' :
               message_code << ". ";
               break;
            case 'f' :
               message_code << ".._. ";
               break;
            case 'g' :
               message_code << "__. ";
               break;
            case 'h' :
               message_code << ".... ";
               break;
            case 'i' :
               message_code << ".. ";
               break;
            case 'j' :
               message_code << ".___ ";
               break;
            case 'k' :
               message_code << "_._ ";
               break;
            case 'l' :
               message_code << "._.. ";
               break;
            case 'm' :
               message_code << "__ ";
               break;
            case 'n' :
               message_code << "_. ";
               break;
            case 'o' :
               message_code << "___ ";
               break;
            case 'p' :
               message_code << ".__. ";
               break;
            case 'q' :
               message_code << "__._ ";
               break; 
            case 'r' :
               message_code << "._. ";
               break;
            case 's' :
               message_code << "... ";
               break;
            case 't' :
               message_code << "_ ";
               break;
            case 'u' :
               message_code << ".._ ";
               break;
            case 'v' :
               message_code << "..._ ";
               break; 
            case 'w' :
               message_code << ".__ ";
               break;
            case 'x' :
               message_code << "_.._ ";
               break;
            case 'y' :
               message_code << "_.__ ";
               break;
            case 'z' :
               message_code << "__.. ";
               break;
            case ' ' :
               message_code << "?"; //? symbolise l'espace entre des mots
               break;
         }
      message.get(lettre);
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }

   return 0;
}
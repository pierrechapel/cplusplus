#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class message
{
public:
    message( string directory_path, string name) : directory_path(directory_path), name(name){};

    void code(){
           ifstream buffer(directory_path +"/"+ name);
        ofstream message_code(directory_path + "/message_code.txt");

        if(buffer and message_code)
            {
            //L'ouverture des deux fichiers s'est bien passée, on peut donc lire et écrire

      char lettre; //Une variable pour stocker les lettres lues
      buffer.get(lettre);
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
               message_code << "? "; //? symbolise l'espace entre des mots
               break;
         }
      buffer.get(lettre);
      
      }
      message_code<< "! "; //symbolise la fin du message
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }
    }



private:
string directory_path;
string name;


};

class message_code
{
public:
    message_code (string directory_path, string name) : directory_path(directory_path), name(name){};

    void decode(){
        ifstream buffer(directory_path + "/" + name );
        ofstream message_decode( directory_path + "/message_decode.txt");
        
        if (buffer and message_decode){
            string mot;
            //buffer >> mot;
            while(buffer >> mot){
                if(mot == "._"){
                    message_decode<< 'a';
                }
                if(mot == "_..."){
                    message_decode<< 'b';
                }
                if(mot == "_._."){
                    message_decode<< 'c';
                }
                if(mot == "_.."){
                    message_decode<< 'd';
                }
                if(mot == "."){
                    message_decode<< 'e';
                }
                if(mot == ".._."){
                    message_decode<< 'f';
                }
                if(mot == "__."){
                    message_decode<< 'g';
                }
                if(mot == "...."){
                    message_decode<< 'h';
                }
                if(mot == ".."){
                    message_decode<< 'i';
                }
                if(mot == ".___"){
                    message_decode<< 'j';
                }
                if(mot == "_._"){
                    message_decode<< 'k';
                }
                if(mot == "._.."){
                    message_decode<< 'l';
                }
                if(mot == "__"){
                    message_decode<< 'm';
                }
                if(mot == "_."){
                    message_decode<< 'n';
                }
                if(mot == "___"){
                    message_decode<< 'o';
                }
                if(mot == ".__."){
                    message_decode<< 'p';
                }
                if(mot == "__._"){
                    message_decode<< 'q';
                }
                if(mot == "._."){
                    message_decode<< 'r';
                }
                if(mot == "..."){
                    message_decode<< 's';
                }
                if(mot == "_"){
                    message_decode<< 't';
                }
                if(mot == ".._"){
                    message_decode<< 'u';
                }
                if(mot == "..._"){
                    message_decode<< 'v';
                }
                if(mot == ".__"){
                    message_decode<< 'w';
                }
                if(mot == "_.._"){
                    message_decode<< 'x';
                }
                if(mot == "_.__"){
                    message_decode<< 'y';
                }
                if(mot == "__.."){
                    message_decode<< 'z';
                }
                if(mot == "?"){
                    message_decode<< ' ';
                }
            //buffer >> mot;
            }
        }
    }

	


private:
string directory_path;
string name;

};

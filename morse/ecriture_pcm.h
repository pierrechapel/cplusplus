#include <fstream>
#include <iostream>
#include <string>
using namespace std;



class pcm_morse
{
	public:
	pcm_morse(string directory_path, string name): directory_path(directory_path), name(name) {};
	
	void write_pcm(string name_text_file){
			std::ifstream text(directory_path + "/" + name_text_file);
	std::ofstream pcm(directory_path + "/" + name + ".pcm", std::ofstream::binary);
	int16_t intensite = 150;
	int16_t intensitem = -150;
	int16_t silence = 0;
	int longueur_bip = 80; //en périodes sonore on utilise le la3=440Hz comme note. 
	int longueur_silence = 8018;
	uint32_t fsize = text.tellg();
    text.seekg(0, std::ios::end);
    fsize = (uint32_t)text.tellg() - fsize;
    text.seekg(0, std::ios::beg);
    
    for (int i = 0; i < fsize; ++i) {
    char a;
    text.get(a);
    if (a == '_'){
        
        for (int i=0; i < 3*longueur_bip; i++) {
            for (int j=0; j<50; j++){
                pcm.write(reinterpret_cast <char *>(&intensite), sizeof(int16_t));
			}
			for (int j=0; j<50; j++){
				pcm.write(reinterpret_cast <char *>(&intensitem), sizeof(int16_t));
			}
		}
        for (int i=0; i < longueur_silence; i++) {
            pcm.write(reinterpret_cast <char *>(&silence), sizeof(int16_t));
            
		}
		
    }
    if (a == '.'){
        for (int i=0; i < longueur_bip; i++) {
            for (int j=0; j<50; j++){
                pcm.write(reinterpret_cast <char *>(&intensite), sizeof(int16_t));
			}
			for (int j=0; j<50; j++){
				pcm.write(reinterpret_cast <char *>(&intensitem), sizeof(int16_t));
			}
		}       
        for (int i=0; i < longueur_silence; i++) {
            pcm.write(reinterpret_cast <char *>(&silence), sizeof(int16_t));
            
		}
    }
    if (a == '?'){//espace entre les mots
        for (int k=0; k< 2*longueur_silence; k++) {
            pcm.write(reinterpret_cast <char *>(&silence), sizeof(int16_t));
        }
    }
    if (a == ' '){//espace entre les lettres
        for (int k=0; k< 2*longueur_silence; k++) {
            pcm.write(reinterpret_cast <char *>(&silence), sizeof(int16_t));
        }
    }
    if (a == '!'){}
    
  }
	
	}
		
	private:
		string directory_path;
		string name;
		
	
	
};
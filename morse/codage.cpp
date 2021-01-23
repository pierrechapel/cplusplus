#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "morse.h"
#include "ecriture_pcm.h"
#include "pcm_to_wav.h"



int main(){ 
    string directory_path = "/home/pierrechapel/c++/repo devoirs/cplusplus/morse";//il faut indiquer votre répertoire de travail
    string fichier_texte = "exemple.txt";// il faut renseigner le nom du fichier .txt à décoder.
	
    
    
    
    message texte = message(directory_path, fichier_texte);
    texte.code();
    
    pcm_morse message_morse = pcm_morse(directory_path, "message_morse");
    message_morse.write_pcm("message_code.txt");
    
    wav_morse message_morse_wav = wav_morse(directory_path, "message_morse");
    message_morse_wav.transfer_from_pcm("message_morse.pcm");
    
    
    
    
    
    return 0;
}
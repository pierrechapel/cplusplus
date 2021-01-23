CXX=g++
CXXFLAGS=-Wall -ggdb
RM=rm -f

codage : codage.cpp morse.h ecriture_pcm.h pcm_to_wav.h
	$(CXX) $(CXXFLAGS) $^ -o $@
	
decodage : decodage.cpp morse.h
	$(CXX) $(CXXFLAGS) $^ -o $@
	
clean_all : 
	$(RM) message_code.txt message_decode.txt message_en_morse.txt message_morse_transcrit.txt message_morse.pcm message_morse.wav

clean :
	$(RM) message_en_morse.txt message_morse_transcrit.txt message_morse.pcm
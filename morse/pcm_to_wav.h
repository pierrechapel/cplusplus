#include <fstream>
#include <iostream>
#include <string>
using namespace std;

typedef struct WAV_HEADER {
  /* RIFF Chunk Descriptor */
  uint8_t RIFF[4] = {'R', 'I', 'F', 'F'}; // RIFF Header Magic header
  uint32_t ChunkSize;                     // RIFF Chunk Size
  uint8_t WAVE[4] = {'W', 'A', 'V', 'E'}; // WAVE Header
  /* "fmt" sub-chunk */
  uint8_t fmt[4] = {'f', 'm', 't', ' '}; // FMT header
  uint32_t Subchunk1Size = 16;           // Size of the fmt chunk
  uint16_t AudioFormat = 1; // Audio format 1=PCM,6=mulaw,7=alaw,     257=IBM
                            // Mu-Law, 258=IBM A-Law, 259=ADPCM
  uint16_t NumOfChan = 1;   // Number of channels 1=Mono 2=Sterio
  uint32_t SamplesPerSec = 44100;   // Sampling Frequency in Hz
  uint32_t bytesPerSec = 44100 * 2; // bytes per second
  uint16_t blockAlign = 2;          // 2=16-bit mono, 4=16-bit stereo
  uint16_t bitsPerSample = 16;      // Number of bits per sample
  /* "data" sub-chunk */
  uint8_t Subchunk2ID[4] = {'d', 'a', 't', 'a'}; // "data"  string
  uint32_t Subchunk2Size;                        // Sampled data length
} wav_hdr;



class wav_morse
{
public:
	wav_morse( string directory_path, string name): directory_path(directory_path), name(name) {};
	
	void transfer_from_pcm(string name_pcm){// transfere les données brutes du .pcm nommé en argument dans un .wav créé par la fonction dans le répertoire de travail.
	  static_assert(sizeof(wav_hdr) == 44, "");

  std::string in_name = name_pcm; // raw pcm data without wave header
  std::ifstream in(in_name, std::ifstream::binary);

  uint32_t fsize = in.tellg();
  in.seekg(0, std::ios::end);
  fsize = (uint32_t)in.tellg() - fsize;
  in.seekg(0, std::ios::beg);

  printf("file size: %u\n", fsize);

  wav_hdr wav;
  wav.ChunkSize = fsize + sizeof(wav_hdr) - 8;
  wav.Subchunk2Size = fsize + sizeof(wav_hdr) - 44;

  std::ofstream out(name + ".wav", std::ios::binary);
  out.write(reinterpret_cast<const char *>(&wav), sizeof(wav));

  int16_t d;
  for (int i = 0; i < fsize; ++i) {
    // TODO: read/write in blocks
    in.read(reinterpret_cast<char *>(&d), sizeof(int16_t));
    out.write(reinterpret_cast<char *>(&d), sizeof(int16_t));
  }
	
	
	}
	
private:
	string directory_path;
	string name;



};
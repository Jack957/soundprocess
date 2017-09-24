#include <iostream>
#include "utils.hpp"
#include "effects.hpp"

int main(int argc, char const *argv[]) // effect type, input, output, 
{
    std::string in_filename = "input.wav", out_filename = "output.wav";
//    if (argc==1) {
//        return 0;
//    }
//    else if (argc==2) {
//        in_filename = "input.wav";
//        out_filename = "output.wav";
//    }
//    else if (argc==3) {
//        in_filename = argv[3];
//    }
//    else {
//        in_filename = argv[3];
//        out_filename = argv[4];
//    }  // TODO: redo command line params!

    AudioFile<double> audiodata = load_audio(in_filename);
    std::cout << "loaded" << std::endl;
    std::vector<arma::vec> arma_audiodata = convert_audio(audiodata);
    std::cout << "converted" << std::endl;
    paulstretch(arma_audiodata);
    write_audio(arma_audiodata, out_filename, audiodata.getSampleRate(), audiodata.getBitDepth());
    return 0;
}

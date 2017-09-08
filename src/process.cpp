#include <iostream>
#include "utils.hpp"
#include "effects.hpp"

int main(int argc, char const *argv[]) // effect type, input, output, 
{
    std::string in_filename = "input.wav", out_filename = "output.wav";
    if (argc==1) {
        return 0;
    }
    else if (argc==2) {
        in_filename = "input.wav";
        out_filename = "output.wav";
    }
    else if (argc==3) {
        in_filename = argv[3];
    }
    else {
        in_filename = argv[3];
        out_filename = argv[4];
    }

    AudioFile<double> audiodata = load_audio(filename);
    std::vector<arma::vec> arma_audiodata = convert_audio(audiodata);
    // arma_audiodata = process(arma_audiodata);
    // write_audio(arma_audiodata, out_filename, int sample_rate, int bit_depth) 
    return 0;
}
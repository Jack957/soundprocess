#include <armadillo>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "AudioFile.h"

std::vector<arma::vec> load_audio(const std::string &filename) {
    std::ifstream ifs(filename);
    std::string wavfilename;
    std::getline(ifs, wavfilename);

    AudioFile<double> audioFile;
    audioFile.load(wavfilename);
    int numChannels = audioFile.getNumChannels();
    int numSamples = audioFile.getNumSamplesPerChannel();

    std::vector<arma::vec> output;
    arma::vec channel = arma::zeros(numSamples);
    int i, k;

    for (i=0; i<numChannels; i++) {
        for (k=0; k<numSamples; k++) {
            channel[k] = audioFile.samples[i][k];
        }
        output.push_back(channel);
    }
    return output;
}

int main(int argc, char const *argv[])
{
    std::string filename;
    if (argc==1) {
        filename = "input";
    }
    else {
        filename = argv[1];
    }

    std::vector<arma::vec> audiodata = load_audio(filename);
    std::cout << audiodata[0].n_elem << std::endl;
    return 0;
}
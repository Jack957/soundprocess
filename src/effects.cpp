#include <cmath>
#include "arma-dsp.hpp"
#include "effects.hpp"
#include "utils.hpp"
#include <iostream>


void paulstretch(std::vector<arma::vec> &audio, unsigned int stretch) {
    for (int i=0; i<audio.size(); i++) {
        // std::cout << audio[i].n_elem << std::endl;;
        audio[i] = adsp::lowpass_filter(audio[i], 44100, 100.);
        // arma::cx_mat spectrogram = adsp::stft(audio[i], 1024, 16);
        // audio[i] = adsp::istft(spectrogram, 1024, 16);
    }
}

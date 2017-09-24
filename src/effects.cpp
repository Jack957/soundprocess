#include <cmath>
#include "arma-dsp.hpp"
#include "effects.hpp"
#include "utils.hpp"
#include <iostream>


void paulstretch(std::vector<arma::vec> &audio, unsigned int stretch) {
    for (int i=0; i<audio.size(); i++) {
        // std::cout << audio[i].n_elem << std::endl;;
        // audio[i] = adsp::one_pole_filter(audio[i], 1.0, 0.3);
        // arma::cx_mat spectrogram = adsp::stft(audio[i], 1024, 16);
        // audio[i] = adsp::istft(spectrogram, 1024, 16);
    }
}

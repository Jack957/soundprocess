#include <cmath>
#include <arma-dsp>
#include "effects.hpp"
#include "utils.hpp"

void single_delay(const std::vector<arma::vec> &audio, double delay_time, double wet_mix, int sample_rate, std::vector<arma::vec> &audio_output) {
    unsigned int delay_samples = (unsigned int)round(delay_time * sample_rate);

    int num_channels = audio.size();
    for (int i=0; i<num_channels; i++) {
        audio_output[i] = wet_mix * fir_filter(audio[i], 0.0, 1.0, delay_samples) + (1.0 - wet_mix) * audio[i];
    }
}

std::vector<arma::vec> single_delay(const std::vector<arma::vec> &audio, double delay_time, double wet_mix, int sample_rate, bool auto_pad=false) {
    std::vector<arma::vec> audio_output = audio;
    if (auto_pad) {
        pad_audio(audio_output, (int)round(delay_time * sample_rate), true);
    }
    single_delay(audio, delay_time, wet_mix, sample_rate, audio_output);
    return audio_output;
}
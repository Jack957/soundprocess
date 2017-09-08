
#include "utils.hpp"
#include <arma-dsp>

AudioFile<double> load_audio(const std::string &filename) {
    AudioFile<double> audio_file;
    audio_file.load(filename);
    return audioFile;
}

std::vector<arma::vec> convert_audio(const AudioFile<double> &audio_file) {
    int num_channels = audio_file.getNumChannels();
    int num_samples = audio_file.getNumSamplesPerChannel();

    std::vector<arma::vec> output;
    arma::vec channel = arma::zeros(numSamples);

    for (int i=0; i<num_channels; i++) {
        for (int k=0; k<num_samples; k++) {
            channel[k] = audioFile.samples[i][k];
        }
        output.push_back(channel);
    }

    return output;
}

AudioFile<double> convert_audio(const std::vector<arma::vec> &audio, int sample_rate, int bit_depth) {
    int num_channels = audio.size();
    AudioFile<double>::AudioBuffer buffer;
    buffer.resize(num_channels);
    for (int i=0; i<num_channels; i++) {
        buffer[i].resize(audio[i].n_elem);
        for (int k=0; k<audio[i].n_elem; k++) {
            buffer[i][k] = audio[i][k];
        }
    }

    AudioFile<double> audio_file;
    bool ok = audio_file.setAudioBuffer(buffer);
    audio_file.setBitDepth(bit_depth);
    audio_file.setSampleRate(sample_rate);
    return audio_file;
}

void write_audio(const std::vector<arma::vec> &audio, const std::string &filename, int sample_rate, int bit_depth) {
    AudioFile<double> audio_file = convert_audio(audio, sample_rate, bit_depth);
    write_audio(audio_file, filename);
}

void write_audio(const AudioFile<double> &audio_file, const std::string &filename) {
    audio_file.save(filename);
}

void pad_audio(std::vector<arma::vec> &audio, unsigned int n_zeros, bool end) {
    arma::vec b;

    int num_channels = audio.size();
    for (int i=0; i<num_channels; i++) {
        audio[i] = pad_zeros(audio[i], n_zeros, end);
    }
}
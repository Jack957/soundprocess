#ifndef SP_EFFECTS_HPP
#define SP_EFFECTS_HPP

void single_delay(const std::vector<arma::vec> &audio, double delay_time, double wet_mix, int sample_rate, std::vector<arma::vec> &audio_output);
std::vector<arma::vec> single_delay(const std::vector<arma::vec> &audio, double delay_time, double wet_mix, int sample_rate, bool auto_pad=false);

#endif
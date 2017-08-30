#include <iostream>
#include "utils.hpp"
#include "effects.hpp"

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
#include "../lib/libSRRFOOKIntf.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <filename> <GPIO Pin>\n";
        return 1;
    }

    std::string filename = argv[1];
    unsigned int gpioPin = std::stoi(argv[2]);

    // Read the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    std::string line;
    getline(file, line);
    file.close();

    std::stringstream ss(line);
    std::string item;
    std::vector<std::string> params;

    // Split the line by commas
    while (getline(ss, item, ',')) {
        params.push_back(item);
    }

    if (params.size() < 5) {
        std::cerr << "Incorrect file format. Expected 5 parameters." << std::endl;
        return 1;
    }

    unsigned int repetition = std::stoi(params[0]);
    unsigned int shortDelay = std::stoi(params[1]);
    unsigned int longDelay = std::stoi(params[2]);
    unsigned int extendedDelay = std::stoi(params[3]);
    std::string binaryVector = params[4];

    // Convert string to vector of unsigned ints
    std::vector<unsigned int> bits;
    for (char c : binaryVector) {
        if (c == '0' || c == '1') {
            bits.push_back(c - '0');
        }
    }

    try {
        libSRRFOOKIntf controller(gpioPin, shortDelay, longDelay, extendedDelay);
        controller.sendSeries(bits, repetition);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

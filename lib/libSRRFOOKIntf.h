#ifndef LIB_SRRFOOK_INTF_H
#define LIB_SRRFOOK_INTF_H

#include <vector>
class libSRRFOOKIntf {
public:
    // Constructor that initializes the GPIO pin used to communicate with the transceiver
    explicit libSRRFOOKIntf(unsigned int gpioPin, unsigned int sdtime, unsigned int ldtime, unsigned int extd);

    // Destructor to handle any cleanup if necessary
    virtual ~libSRRFOOKIntf();

    // Send a single bit
    void sendBit(unsigned int bitToSend);

    // Send a vector of bits, each bit repeated 'repetition' times
    void sendSeries(const std::vector<unsigned int>& vectorToSend, unsigned int repetition);

private:
    unsigned int pin;            // GPIO pin number
    unsigned int shortDTime;     // Short delay time
    unsigned int longDTime;      // Long delay time
    unsigned int extDTime;       // Extended delay 
};

#endif // LIB_SRRF_CONTROLLER_H


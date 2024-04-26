#include "libSRRFOOKIntf.h"
#include <pigpio.h>
#include <unistd.h>
#include <stdexcept>

// Constructor
libSRRFOOKIntf::libSRRFOOKIntf(unsigned int gpioPin, unsigned int sdtime, unsigned int ldtime, unsigned int extd)
    : pin(gpioPin), shortDTime(sdtime), longDTime(ldtime), extDTime(extd)
{
    if (gpioInitialise() < 0)
    {
        throw std::runtime_error("GPIO initialization failed.");
    }
    else
    {
        printf("pigpio initialised okay.\n");
    }
    gpioSetMode(pin, PI_OUTPUT);
    gpioWrite(pin, 0);

}

// Destructor
libSRRFOOKIntf::~libSRRFOOKIntf()
{
    gpioTerminate();
}

// Single bit
void libSRRFOOKIntf::sendBit(unsigned int bitToSend)
{
    if(bitToSend == 1)
    {
	gpioWrite(pin, 1);
        usleep(shortDTime);
        gpioWrite(pin, 0);
        usleep(longDTime);
    }
    else
    {
	gpioWrite(pin, 1);
        usleep(longDTime);
        gpioWrite(pin, 0);
        usleep(shortDTime);
    }
}

// A series
void libSRRFOOKIntf::sendSeries(const std::vector<unsigned int>& vectorToSend, unsigned int repetition)
{
    for (unsigned int repeat = 0; repeat < repetition; ++repeat)
{
        for (unsigned int bit : vectorToSend)
	{
            sendBit(bit);
        }
	usleep(extDTime);
    }
}

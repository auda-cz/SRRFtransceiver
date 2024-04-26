# SRRFtransceiver
Super-regenerative RF On–off keying transmitter/receiver (315MHz/433MHz) interface. Designed for remote controlling. 

Unfortunately, the current receivers I have are all fried or detuned for testing, so the receiver and sniffing functionalities are postponed for now. Besides, there's potential to include factory patterns into the hierarchy in future updates(if there is one ;)

## File Structure:
-   `libSRRFOOKIntf.h`: Header file for the libSRRFOOKIntf class, defining the driver interface
-   `libSRRFOOKIntf.cpp`: Implementation file for the libSRRFOOKIntf class.
-   `RemoteControl.cpp`:Main executable file
-   `sequences/`: Some examples for sequence file

## Usage:
```
./RemoteControl <filename> <GPIO Pin>
```
- `<GPIO Pin>`: The GPIO pin number connected to the SRRF transmitter.
- `filename`: A **one-line text** file describing the sequence is needed. The file is formed as:
```
    repetition,
    short_delay_duration_in_microsecond,
    long_delay_duration_in_microsecond,
    Extended_delay_between_repetition,
    PulseBits
```
delimited by a comma. Examples can be found at `sequences/`

## Environment Requirements:
-   OS: Linux (tested with Debian 12.5 bookworn on Raspberry Pi 4B)
-   Compiler: GCC or G++
-   Libraries: `libpigpio-dev`

## Compiling Instructions:
Ensure the pigpio library is installed (`sudo apt-get install pigpio`). No daemon is needed.

To compile, just call `make`, or `make clean` for cleaning.


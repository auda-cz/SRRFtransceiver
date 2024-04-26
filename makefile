# Compiler settings
CC = g++
CFLAGS = -Wall -I./lib
LDFLAGS = -lpigpio -L./lib

# Directory for binaries (keep it separate from source files)
BINDIR = ./bin

# Target executable and sources
EXEC = $(BINDIR)/RemoteControl
SOURCES = src/main.cpp
LIBRARY_SRC = lib/libSRRFOOKIntf.cpp
LIBRARY_OUT = lib/libSRRFOOKIntf.so

# Default target
all: $(EXEC)

# Rule for creating the executable
$(EXEC): $(LIBRARY_OUT) $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@ -lSRRFOOKIntf $(LDFLAGS) -Wl,-rpath,$(PWD)/lib

# Rule for creating the shared library
$(LIBRARY_OUT): $(LIBRARY_SRC)
	$(CC) $(CFLAGS) -shared -fPIC $(LIBRARY_SRC) -o $@ $(LDFLAGS)

# Clean rule
clean:
	rm -f $(BINDIR)/RemoteControl $(LIBRARY_OUT)

# Phony targets
.PHONY: all clean

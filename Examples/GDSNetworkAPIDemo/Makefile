# Cross-compiler for ARM (BeagleBone Green)
CXX = arm-linux-gnueabihf-g++  

# Compiler flags
CXXFLAGS = -pthread -std=c++17 -Wall -Wextra 

# Linker flags
LDFLAGS = -lrt  

# Target executable name
TARGET = GDSNetworkInterfaceDemo

# Source files
SRC = $(wildcard *.cpp)

# Build the executable
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Clean build files
clean:
	rm -f $(TARGET)


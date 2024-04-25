# Define the name of the executable file.
TARGET = array2d

# Define the C++ compiler to use.
CXX = g++

# Uncomment to link libraries (-lm is for the math library).
#LIBS = -lm

# Define the flags to use when compiling.
CXXFLAGS = -std=c++11 -Wall

# Define a list of source files used to make the TARGET executable.
SRCS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

# Define a list of header files used to make the TARGET executable.
HDRS = $(wildcard *.hpp) $(wildcard *.h)

# Define the names of the object files used to make the TARGET executable.
OBJS = $(SRCS:.cpp=.o)

# Deefine variable for debugging options.
DEBUG = -ggdb

# The first target in the Makefile is the default one.
all: $(TARGET)
	@echo All done compiling $(TARGET)

$(TARGET): $(HDRS) $(OBJS)
	$(CXX) $(CXXFLAGS) $(LIBS) $(OBJS) -o $(TARGET)

# Add debugging options.
debug: DBFLAGS = $(DEBUG)
debug: all

# Target defining how to build the object files (.o)
# from source (.cpp). The $< refers to the object
# files (to the left of the ':'). The $@ refers to
# the source files (to the right of the ':').
# '%' matches any nonempty string.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DBFLAGS) -c $< -o $@

# Define phony targets in this Makefile - that is, targets that do not
# lead to an executable product.
.PHONY: clean

clean:
	rm -f *.o *~
	rm -f $(TARGET)

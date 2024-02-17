# Define compiler
CXX := g++

# Define any compile-time flags
CXXFLAGS := -std=c++14 -Wall -g

# Define any directories containing header files
INCLUDES :=

# Define source file directory
SRC_DIR := .

# Define any libraries to link into executable
LIBS :=

# Define the C++ source files
SRCS := $(SRC_DIR)/main.cpp $(SRC_DIR)/Lattice.cpp $(SRC_DIR)/LatticeNode.cpp

# Define the C++ object files 
OBJS := $(SRCS:.cpp=.o)

# Define the executable file 
MAIN := main

# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above 
# and by deleting dependencies in the clean section

.PHONY: depend clean

all:    $(MAIN)
	@echo  Simple compiler named mycc has been compiled

$(MAIN): $(OBJS) 
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)

# This is a suffix replacement rule for building .o's from .cpp's
# It uses automatic variables $<: the name of the prerequisite of 
# the rule(a .cpp file) and $@: the name of the target of the rule 
# (a .o file) 
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it

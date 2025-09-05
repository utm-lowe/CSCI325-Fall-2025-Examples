# Find all cpp files in the current directory
SOURCES := $(wildcard *.cpp)

# Strip the .cpp to get program names
PROGRAMS := $(basename $(SOURCES))

# Default target: build all programs
all: $(PROGRAMS)

# Rule: each .cpp compiles into an executable of the same name
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean target: delete all compiled programs
clean:
	rm -f $(PROGRAMS)

PROGRAMA = p04_regular_expressions
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

SOURCES = main.cc bucle.cc 
OBJECTS = $(SOURCES:.cc=.o)

all: $(PROGRAMA)

$(PROGRAMA): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(PROGRAMA) $(OBJECTS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
PROGRAMA = p04_regular_expressions
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

SOURCES = p04_reg.cc bucle.cc variable.cc main.cc comment.cc descripcion.cc
OBJECTS = $(SOURCES:.cc=.o)

all: $(PROGRAMA)

$(PROGRAMA): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(PROGRAMA) $(OBJECTS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
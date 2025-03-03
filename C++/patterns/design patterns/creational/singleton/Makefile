COMPILER=g++
CFLAGS=-c -Wall
LDFLAGS=

# включает все файлы исходников для сборки проекта
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=application

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(COMPILER) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

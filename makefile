CC=g++
CFLAGS=-c -Wall -g
LDFLAGS= -pthread
SOURCES=main.cpp elevator.cpp bilding.cpp level.cpp man.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
        
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o 	
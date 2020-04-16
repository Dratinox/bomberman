LDFLAGS := -lSDL2 -lSDL2_image -Wall -pedantic
SRCDIR = src
DOXY=Doxyfile

OBJECTS =\
        $(SRCDIR)/Game.o\
        $(SRCDIR)/Bomb.o\
        $(SRCDIR)/Enemy.o\
        $(SRCDIR)/Character.o\
        $(SRCDIR)/IncreasedCount.o\
        $(SRCDIR)/IncreasedRange.o\
        $(SRCDIR)/InputHandler.o\
        $(SRCDIR)/Map.o\
        $(SRCDIR)/Player.o\
        $(SRCDIR)/PowerUps.o\
        $(SRCDIR)/Skate.o\
        $(SRCDIR)/TextureManager.o\
        $(SRCDIR)/main.o

bin: $(OBJECTS)
	g++ $(LDFLAGS) -o lauripat $(OBJECTS)

$(SRCDIR)/main.o:  $(SRCDIR)/main.cpp
	g++ $(LDFLAGS) -c -o  $(SRCDIR)/main.o  $(SRCDIR)/main.cpp

$(SRCDIR)/Game.o: $(SRCDIR)/Game.cpp $(SRCDIR)/Game.h
	g++ $(LDFLAGS) -c -o $(SRCDIR)/Game.o $(SRCDIR)/Game.cpp

$(SRCDIR)/Bomb.o: $(SRCDIR)/Bomb.cpp $(SRCDIR)/Bomb.h
	g++ $(LDFLAGS) -c -o $(SRCDIR)/Bomb.o $(SRCDIR)/Bomb.cpp

$(SRCDIR)/Enemy.o: $(SRCDIR)/Enemy.cpp $(SRCDIR)/Enemy.h
	g++ $(LDFLAGS) -c -o $(SRCDIR)/Enemy.o $(SRCDIR)/Enemy.cpp

$(SRCDIR)/Character.o: $(SRCDIR)/Character.cpp $(SRCDIR)/Character.h
	g++ $(LDFLAGS) -c -o $(SRCDIR)/Character.o $(SRCDIR)/Character.cpp

$(SRCDIR)/IncreasedCount.o: $(SRCDIR)/IncreasedCount.cpp $(SRCDIR)/IncreasedCount.h
	g++ $(LDFLAGS) -c -o $(SRCDIR)/IncreasedCount.o $(SRCDIR)/IncreasedCount.cpp

$(SRCDIR)/IncreasedRange.o: $(SRCDIR)/IncreasedRange.cpp $(SRCDIR)/IncreasedRange.h
	g++ $(LDFLAGS) -c -o $(SRCDIR)/IncreasedRange.o $(SRCDIR)/IncreasedRange.cpp

$(SRCDIR)/InputHandler.o: $(SRCDIR)/InputHandler.cpp $(SRCDIR)/InputHandler.h
	g++ $(LDFLAGS) -c -o $(SRCDIR)/InputHandler.o $(SRCDIR)/InputHandler.cpp

$(SRCDIR)/Map.o: $(SRCDIR)/Map.cpp $(SRCDIR)/Map.h
	g++ $(LDFLAGS) -c -o $(SRCDIR)/Map.o $(SRCDIR)/Map.cpp

$(SRCDIR)/Player.o: $(SRCDIR)/Player.cpp $(SRCDIR)/Player.h
	g++ $(LDFLAGS) -c -o $(SRCDIR)/Player.o $(SRCDIR)/Player.cpp

$(SRCDIR)/PowerUps.o: $(SRCDIR)/PowerUps.cpp $(SRCDIR)/PowerUps.h
	g++ $(LDFLAGS) -c -o $(SRCDIR)/PowerUps.o $(SRCDIR)/PowerUps.cpp

$(SRCDIR)/Skate.o: $(SRCDIR)/Skate.cpp $(SRCDIR)/Skate.h
	g++ $(LDFLAGS) -c -o $(SRCDIR)/Skate.o $(SRCDIR)/Skate.cpp

$(SRCDIR)/TextureManager.o: $(SRCDIR)/TextureManager.cpp $(SRCDIR)/TextureManager.h
	g++ $(LDFLAGS) -c -o $(SRCDIR)/TextureManager.o $(SRCDIR)/TextureManager.cpp

clean:
	rm -r -f  lauripat doc/ $(OBJECTS)

run: bin
	./lauripat
doc: 
	doxygen ./src/$(DOXY) 

compile: bin

all: bin

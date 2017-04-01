#Define special targets
.PHONY: clean, mrproper

#Disable implicit rules
.SUFFIXES:

#Variables
GXX = g++
CXXFLAGS = -std=c++11 -W -Wall -g
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

#Creates the executable
all: character.o enemy.o player.o case.o map.o world.o gameJam.o
	$(GXX) character.o enemy.o player.o gameJam.o world.o map.o case.o -o gameJam $(SFMLFLAGS)
	$(MAKE) clean
	./gameJam

#Builds dependecies
gameJam.o: gameJam.cpp
	$(GXX) -c gameJam.cpp -o gameJam.o $(CXXFLAGS)

case.o: case.cpp
	$(GXX) -c case.cpp -o case.o $(CXXFLAGS)

map.o: map.cpp
	$(GXX) -c map.cpp -o map.o $(CXXFLAGS)

world.o: world.cpp
	$(GXX) -c world.cpp -o world.o $(CXXFLAGS)


character.o: character.cpp
	$(GXX) -c character.cpp -o character.o $(CXXFLAGS)

player.o: player.cpp
	$(GXX) -c player.cpp -o player.o $(CXXFLAGS)

enemy.o: enemy.cpp
	$(GXX) -c enemy.cpp -o enemy.o $(CXXFLAGS)

git:
	git add *
	git commit -m "commit"
	git push

#Removes temporary files
clean:
	rm -rf *.o

#Removes all files (except the sources) in order to rebuild
mrproper: clean
	rm -rf gameJam

#Define special targets
.PHONY: clean, mrproper

#Disable implicit rules
.SUFFIXES:

#Variables
GXX = g++
CXXFLAGS = -std=c++11 -W -Wall -g
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

#Creates the executable
all: character.o enemy.o player.o case.o map.o world.o menu.o gameJam.o
	$(GXX) character.o enemy.o player.o menu.o gameJam.o world.o map.o case.o -o gameJam $(SFMLFLAGS)
	$(MAKE) clean
	./gameJam

#Builds dependecies
gameJam.o: gameJam.cpp
	$(GXX) -c gameJam.cpp -o gameJam.o $(CXXFLAGS)

menu.o: Menu/mainmenu.cpp
	$(GXX) -c Menu/mainmenu.cpp -o menu.o $(CXXFLAGS)

case.o: World/case.cpp
	$(GXX) -c World/case.cpp -o case.o $(CXXFLAGS)

map.o: World/map.cpp
	$(GXX) -c World/map.cpp -o map.o $(CXXFLAGS)

world.o: World/world.cpp
	$(GXX) -c World/world.cpp -o world.o $(CXXFLAGS)

character.o: Character/character.cpp
	$(GXX) -c Character/character.cpp -o character.o $(CXXFLAGS)

player.o: Character/player.cpp
	$(GXX) -c Character/player.cpp -o player.o $(CXXFLAGS)

enemy.o: Character/enemy.cpp
	$(GXX) -c Character/enemy.cpp -o enemy.o $(CXXFLAGS)

git:
	rm -f gameJam
	git add *
	git commit -m "commit"
	git push

#Removes temporary files
clean:
	rm -rf *.o

#Removes all files (except the sources) in order to rebuild
mrproper: clean
	rm -rf gameJam

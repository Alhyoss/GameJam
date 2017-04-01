#Define special targets
.PHONY: clean, mrproper

#Disable implicit rules
.SUFFIXES:

#Variables
GXX = g++
CXXFLAGS = -std=c++11 -W -Wall -g
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

#Creates the executable
all: gameJam.o
	$(GXX) gameJam.o -o gameJam $(SFMLFLAGS)
	$(MAKE) clean
	./gameJam

#Builds dependecies
gameJam.o: gameJam.cpp
	$(GXX) -c gameJam.cpp -o gameJam.o $(CXXFLAGS)

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

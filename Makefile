
all: rpg.exe

rpg.exe: compile ; g++ -o rpg.exe *.o

compile: ; g++ -c *.cpp

clean: ; rm *.o *.gch rpg.exe

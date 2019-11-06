OBJS = main.o game.o
CXX = g++
CXXFLAGS = -Wall -std=c++11
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS = -L/c/'Program Files'/SFML-2.5.1/lib
CPPFLAGS = -I/c/'Program Files'/SFML-2.5.1/include

sfml-app: $(OBJS)
	$(CXX) -o game $(OBJS) $(LDLIBS) $(LDFLAGS)

main.o: game.cc
game.o: game.cc

clean:
	$(RM) sfml-app $(OBJS)

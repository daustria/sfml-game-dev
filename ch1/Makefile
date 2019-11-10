OBJS = main.o game.o bullet.o enemy.o
CXX = g++
CXXFLAGS = -Wall -std=c++14
LDFLAGS = -L/c/SFML-2.5.1/lib
INCLUDES = -I/SFML-2.5.1/include 

sfml-app: $(OBJS)
	$(CXX) $(OBJS) -o sfml-app $(LDFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cc
	$(CXX) -c $< $(INCLUDES)

clean:
	$(RM) sfml-app $(OBJS)

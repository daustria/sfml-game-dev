OBJS = main.o game.o bullet.o enemy.o
CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -L/SFML-2.5.1/lib
INCLUDES = -I/SFML-2.5.1/include

sfml-app: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o sfml-app $(LDFLAGS) -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< $(INCLUDES)

clean:
	$(RM) sfml-app $(OBJS)

OBJS = main.o game.o
CXX = g++
CXXFLAGS = -Wall -std=c++14
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS = -L/c/Program Files/SFML-2.5.1/lib
INCLUDES = -I/c/Program Files/SFML-2.5.1/include 

sfml-app: $(OBJS)
	$(CXX) $(OBJS) -o sfml-app $(LDFLAGS) $(LDLIBS)

%.o: %.cc
	$(CXX) -c $< $(INCLUDES)

clean:
	$(RM) sfml-app $(OBJS)

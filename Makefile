CXX = g++

main: main.cpp plansza.cpp event.cpp monster.cpp player.cpp
	g++ -o main main.cpp plansza.cpp event.cpp monster.cpp player.cpp -std=c++11 -g

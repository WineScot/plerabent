CXX = g++

main: main.cpp plansza.cpp event.cpp monster.cpp player.cpp funkcje.cpp druid.cpp thief.cpp warrior.cpp
	g++ -o main main.cpp plansza.cpp event.cpp monster.cpp player.cpp funkcje.cpp druid.cpp thief.cpp warrior.cpp -std=c++11 -g

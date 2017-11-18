CXX = g++

main: main.cpp plansza.cpp event.cpp monster.cpp
	g++ -o main main.cpp plansza.cpp event.cpp monster.cpp

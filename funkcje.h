#ifndef FUNC
#define FUNC

#include <string>
#include <fstream>
#include "monster.h"
#include "event.h"
#include <cstdlib>

#ifdef WIN32
#include <windows.h>
#define sleep Sleep
#define clear "cls"
#define WAIT system("pause")
#else
#include <unistd.h> // for usleep
#define clear "clear"
#define WAIT getchar()
//#define sleep usleep
void sleep(int);
#endif


void main_init(std::string path);
void Event_init(std::string path);

#endif // FUNC

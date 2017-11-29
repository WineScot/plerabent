#include <string>
#include <fstream>
#include "monster.h"
#include "event.h"
#include <cstdlib>

#ifdef WIN32
#include <windows.h>
#define sleep Sleep
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>   // for nanosleep
#define sleep nanosleep
#else
#include <unistd.h> // for usleep
#define sleep usleep
#endif


void main_init(std::string path);
void Event_init(std::string path);

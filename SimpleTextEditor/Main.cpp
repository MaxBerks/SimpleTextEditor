#include <SDL.h>
#undef main

import DirectMediaLoggerAdapter;

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Quit();
	return 0;
}
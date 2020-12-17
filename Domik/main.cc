/*
 * main.cc
 *
 *  Created on: 25 нояб. 2020 г.
 *      Author: Лев
 */

#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>

#include "ExampleWindow.h"

#include <SDL2/SDL_main.h>

int main(int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	try {
		ExampleWindow w;

		w.main_loop();

	} catch (const std::exception &e) {
		std::cerr << "При выполнении программы "
				"произошла ошибка:" << std::endl <<
				e.what() << std::endl;
		return 1;
	} catch (...) {
		std::cerr << "При выполнении программы "
				"произошла неизвестная ошибка!"
				<< std::endl;
		return 1;
	}

	return 0;
}





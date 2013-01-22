#include <iostream>
#include "Snake.h"

int main()
{
	Snake* sGame = Snake::getInstance();
	sGame->run();
	return 0;
}
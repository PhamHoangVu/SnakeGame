#pragma once
#include "SnakeAPI.h"
#include <queue>
#include <time.h>
using namespace std;
//Size of background
#define WIDTH 80
#define HEIGHT 25

#define SNAKE_CHAR '@'

//Drection of snake
const int D_NORTH = 1;
const int D_EAST  = 2;
const int D_SOUTH = 3;
const int D_WEST  = 4;

//Speed
#define Speed 100

struct POSITION
{
	int X,Y;
};

class Snake
{
public:
	bool isPlay;
	int intLenght;
	int intTop, intLeft, intRight, intBottom;
	int curDirect;
	int moveTo(int direction);
	int eat(int direction);
	char B[WIDTH][HEIGHT];

	SnakeAPI* con;
	queue <POSITION> snakeBody;
	POSITION snakeHead;
	static Snake* _instance;

	Snake(void);
	void init();
	void run();
	void newGame();
	bool play();
	void genTarget();
	void endGame();
	static Snake* getInstance();
	~Snake(void);
};

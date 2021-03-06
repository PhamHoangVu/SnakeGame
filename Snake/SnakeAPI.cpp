// Author: VuPham
// Copyright 2012 Funkoi
#include "SnakeAPI.h"

SnakeAPI* SnakeAPI::_instance = NULL;


void SnakeAPI::setTextColor(GAME_COLOR color)
{
	WORD attrib = CSBI.wAttributes;
	attrib &= 0xFFF0;
	attrib |= (int)color;
	SetConsoleTextAttribute(hSnakeAPI, attrib);
	getInfo();
}

void SnakeAPI::setBackGroundColor(GAME_COLOR color)
{
	int attrib = CSBI.wAttributes;
	attrib &= 0xFF0F;
	attrib |= (int)color;
	SetConsoleTextAttribute(hSnakeAPI, (WORD)attrib);
	getInfo();
}

void SnakeAPI::getInfo()
{
	GetConsoleScreenBufferInfo(hSnakeAPI, &CSBI);
};

void SnakeAPI::gotoxy(int left, int top)
{
	COORD coord = {left, top};
	SetConsoleCursorPosition(hSnakeAPI , coord);
}

void SnakeAPI::clear(bool clearAttribute, char ch)
{
	getInfo();

	DWORD cCharsWritten;
	DWORD size = CSBI.dwSize.X * CSBI.dwSize.Y;
	COORD coord = {0, 0};
	FillConsoleOutputCharacterA(hSnakeAPI, ch, size, coord, &cCharsWritten);

	int attrib = CSBI.wAttributes;
	if (clearAttribute) 
		attrib = LIGHTGRAY;
	FillConsoleOutputAttribute(hSnakeAPI, attrib, size, coord, &cCharsWritten);

	SetConsoleCursorPosition(hSnakeAPI, coord);
	getInfo();
}

SnakeAPI::SnakeAPI()
{
	hSnakeAPI = GetStdHandle(STD_OUTPUT_HANDLE);
}

int SnakeAPI::whereX()
{
	getInfo();
	return CSBI.dwCursorPosition.X;
}

int SnakeAPI::whereY()
{
	getInfo();
	return CSBI.dwCursorPosition.Y;
}

void SnakeAPI::putChar(char ch, int left, int top)
{
	if (top == CURRENT_CURSOR)
	{
		left = whereX();
		top = whereY();
	}

	COORD coord = {left, top};
	DWORD cCharsWritten;
	FillConsoleOutputCharacterA(hSnakeAPI, ch, 1, coord, &cCharsWritten);
}

void SnakeAPI::setTitle(const char *title)
{
	SetConsoleTitleA(title);
}

SnakeAPI* SnakeAPI::getInstance()
{
	if (!_instance)
		_instance = new SnakeAPI;
	return _instance;
}

void SnakeAPI::setAttribute(int attribute)
{
	SetConsoleTextAttribute(hSnakeAPI, (WORD)attribute);
	getInfo();
}
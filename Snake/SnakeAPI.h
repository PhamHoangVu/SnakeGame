// Author: VuPham
// Copyright 2012 Funkoi
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>
#define _SNAKEAPI_H
#define _WIN32_WINNT 0x0500

//Define game keyboard
#define KEY_UP        0x48
#define KEY_DOWN      0x50
#define KEY_LEFT      0x4B
#define KEY_RIGHT     0x4D

#define CURRENT_CURSOR -1

enum GAME_COLOR
{
    BLACK        = 0x0000,
    LIGHTGRAY    = 0x0070,
};

class SnakeAPI
{
public:
    static SnakeAPI* _instance;
    HANDLE hSnakeAPI;
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    void getInfo();
    SnakeAPI();
    void setAttribute(int attribute);
    void clear(bool clearAttribute = false, char ch = ' '); 
    void gotoxy(int left, int top);
    int whereX();
    int whereY();
    void setTitle(const char *title);
    void putChar(char ch, int left = CURRENT_CURSOR, int top = CURRENT_CURSOR);
    void setTextColor(GAME_COLOR color);
    void setBackGroundColor(GAME_COLOR color);
    static SnakeAPI* getInstance();
    ~SnakeAPI();
};

#pragma once
#include"PlayerClass.h"
#include<graphics.h>

class GameClass
{
public:
	GameClass();
	~GameClass();

	IMAGE FIRST;
	IMAGE BTN;

	void welcomeActivity();

	//胜利
	void HaveWin();

	//开始游戏运行
	void Run();
};


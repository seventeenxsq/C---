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

	//ʤ��
	void HaveWin();

	//��ʼ��Ϸ����
	void Run();
};


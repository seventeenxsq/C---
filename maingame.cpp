#include<stdio.h>
#include<graphics.h>
#include <conio.h>
#include<thread>
#include "PlayerClass.h"
#include"GameClass.h"
using namespace std;

IMAGE FIRST;

int main() {


 	GameClass game;
	//��ӭ����
	game.welcomeActivity();

//##########ǰ������������
	//��ʼ��Ϸ
	game.Run();
	
	//ʤ��֮��
	game.HaveWin();

	
}

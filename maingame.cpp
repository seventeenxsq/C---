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
	//欢迎界面
	game.welcomeActivity();

//##########前面是引导界面
	//开始游戏
	game.Run();
	
	//胜利之后
	game.HaveWin();

	
}

#pragma once
#include"RoleClass.h"
#include<graphics.h>

//玩家类继承Role类
class PlayerClass :public RoleClass
{
public:   //初始化坐标和形象
	PlayerClass(int x, int y);
	~PlayerClass();

	int x, y;//人物的中心坐标

	int direction;  //0 1 2 3--上下左右

	int sight;//视野
	
	//魔法药水数量
	int countWater;

	//图片大小
	int imageSize;

	//绘制每走一步的人物下面的地图区域
	void PaintRoad(int i, int j, int sight);

	//判断是否撞墙的函数
	bool IfCrash(int direction);

	//监听键盘，并得到人物的中心点坐标
	void KeyDown_Coordinates();

	//背景图片、
	IMAGE ground;
	IMAGE BOX, TREE, HOUSE, BOX_Y, TREE_Y, HOUSE_Y;
	IMAGE PRIZE, PRIZE_Y;

	//再将中心点坐标转换成左上角的坐标函数！！
	int return_X(int x);
	int return_Y(int y);

	//判断获胜
	bool isWin();

	//贴图操作
	void PutImage(int direction);

	//撞到道具
	int getPrize(int direction);

	//获得道具后的改变操作
	void changeSelf(int i);


	void GameInfo();

private:
	//int x, y;//人物的坐标
	IMAGE role,roleY;//人物形象
	
};


#pragma once


 class RoleClass
{
public:
	RoleClass();
	~RoleClass(); 

	//步长
	int steplength;
	//判断是否撞墙的函数
	bool IfCrash();

	//坐标转换函数**用它来测算是否撞墙
	int TransformX(int x);

	int TransformY(int y);

	//void KeyDown();

private:
	//int speed;//速度
};


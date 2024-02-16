#include "PlayerClass.h"
#include<graphics.h>
#include<stdio.h>
#include<conio.h>  
#include<stdlib.h>

//#####地图设置   extern到所有文件
/*
	0   草地
	1	木箱
	2	树木
	3	房屋
	4	增加视野道具
	5	加速道具
	6	魔法药水
	7	解救长老（终点）
*/

int map[19][15] = {
{2,2,2,2,0,0,2,2,2,2,2,2,2,2,2},
{2,6,3,0,0,0,0,0,0,3,0,0,0,6,2},
{2,0,3,5,2,3,2,2,0,0,2,0,3,0,2},
{2,0,2,0,0,0,0,0,0,0,0,4,3,2,2},
{2,0,0,0,0,0,0,0,2,0,0,0,0,3,2},
{2,0,2,3,3,3,3,3,0,0,0,3,0,0,2},
{2,0,0,0,0,3,0,0,3,0,2,5,0,0,2},
{2,4,3,0,0,3,3,3,0,0,0,0,0,0,2},
{2,0,2,0,0,0,4,3,0,2,2,0,3,0,2},
{2,3,0,0,0,3,0,3,0,0,0,3,0,0,2},
{2,3,0,2,0,0,0,0,0,3,0,0,0,0,2},
{2,3,2,0,0,3,3,3,2,2,2,0,0,0,2},
{2,3,6,0,0,0,3,0,0,0,3,2,0,0,2},
{2,3,3,3,0,3,3,0,3,0,2,0,0,0,2},
{2,2,7,0,0,0,0,0,2,0,0,0,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2} };

//行走的图片帧
int imgNum=1;

//此处修改图像的大小 、速度,,这里传入的是人物的中心坐标
PlayerClass::PlayerClass(int x, int y)
{
	this->imageSize = 40;
	this->x = x+ imageSize /2; this->y = y+ imageSize /2;
	sight=1;
	this->steplength = 3;
	this->countWater = 0;

//########此处修改图像的大小###################
	

	//方向，初始化为向右
	direction = 3;

	loadimage(&ground, _T("FloorWall/FloorWall1.png"));
	loadimage(&role, _T("CaiTu/player1.png"));
	loadimage(&roleY, _T("YanMaTu/player1_Y.png"));
	loadimage(&TREE, _T("StoneWall/StoneWallTree.png"));
	loadimage(&HOUSE, _T("StoneWall/StoneWallBlue.png"));
	loadimage(&BOX, _T("StoneWall/SoilWall.png"));
	loadimage(&TREE_Y, _T("StoneWall/StoneWallTreeBlack.png"));
	loadimage(&HOUSE_Y, _T("StoneWall/StoneWallBlack.png"));
	loadimage(&PRIZE, _T("CaiTu/Prize.png"));
	loadimage(&PRIZE_Y, _T("YanMatu/Prize_Y.png"));
}

PlayerClass::~PlayerClass()
{
}

//返回左上角的像素值
int PlayerClass:: return_X(int x) {
	return (x - imageSize / 2);
}
int PlayerClass::return_Y(int y) {
	return (y - imageSize / 2);
}

//局部绘制地图  X，Y表示转换成矩阵的位置
void PlayerClass::PaintRoad(int X, int Y, int sight) {

	//行循环
	for (int i = X - sight; i <= X + sight; i++) {
		for (int j = Y - sight; j <= Y + sight; j++) {
			switch (map[i][j]) {
			case 0:
				putimage(i * 50 + 30, j * 50 + 30,&ground);
				break;
			case 1:putimage(i * 50 + 30, j * 50 + 30, &BOX);
				break;
			case 2:
				putimage(i * 50 + 30, j * 50 + 30, &ground);
				putimage(i * 50 + 30, j * 50 + 30, &TREE_Y, SRCAND);
				putimage(i * 50 + 30, j * 50 + 30, &TREE, SRCPAINT);
				break;
			case 3:
				putimage(i * 50 + 30, j * 50 + 30, &ground);
				putimage(i * 50 + 30, j * 50 + 30, &HOUSE_Y, SRCAND);
				putimage(i * 50 + 30, j * 50 + 30, &HOUSE, SRCPAINT);
				break;
			case 4:	//扩大视野
				putimage(i * 50 + 30, j * 50 + 30, &ground);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE_Y, 0, 0,SRCAND);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE, 0, 0,SRCPAINT);
				break;
			case 5://加速
				putimage(i * 50 + 30, j * 50 + 30, &ground);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE_Y, 150, 0, SRCAND);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE, 150, 0, SRCPAINT);
				break;
			case 6://魔法药水
				putimage(i * 50 + 30, j * 50 + 30, &ground);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE_Y, 50, 0, SRCAND);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE, 50, 0, SRCPAINT);
				break;
			case 7://终点长老
				putimage(i * 50 + 30, j * 50 + 30, &ground);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE_Y, 100, 0, SRCAND);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE, 100, 0, SRCPAINT);
				break;
			}
		}
	}
}

//############putimage的坐标在左上角，所以要将（x,y）转换成左上角坐标。


//重写是否碰撞函数
bool PlayerClass::IfCrash(int direction) {

	//存储的是像素坐标值
	//右上角 
	int Right_Up[2] = { this->x + imageSize / 2,this->y - imageSize / 2 };
	//左上角
	int Left_Up[2] = { this->x - imageSize / 2,this->y - imageSize / 2 };
	//左下角
	int Left_Down[2] = { this->x - imageSize / 2,this->y + imageSize / 2 };
	//右下角
	int Right_Down[2] = { this->x + imageSize / 2,this->y + imageSize / 2 };

	switch (direction) {

	case 0: {	//向上走的判断
		int inputX = this->TransformX(Right_Up[0] - 1);//转换成了矩阵的坐标
		int inputY = this->TransformY(Right_Up[1] - this->steplength);
		int input_X = this->TransformX(Left_Up[0]);
		//
		if (map[inputX][inputY] == 3 || map[input_X][inputY] == 3
			||map[inputX][inputY] == 2 || map[input_X][inputY] == 2) {
			return true;
		}break; }

	case 1: { //向下走的判断
		int inputX = this->TransformX(Right_Down[0] - 1);
		int inputY = this->TransformY(Right_Down[1] + this->steplength);
		int input_X = this->TransformX(Left_Down[0]);
		if (map[inputX][inputY] == 3 || map[input_X][inputY] == 3
			|| map[inputX][inputY] == 2 || map[input_X][inputY] == 2) {
			return true;
		}break; }

	case 2: {  //向左走的判断
		int inputX = this->TransformX(Left_Down[0] - this->steplength);
		int inputY = this->TransformY(Left_Down[1] - 1);
		int input_Y = this->TransformY(Left_Up[1]);
		if (map[inputX][inputY] == 3 || map[inputX][input_Y] == 3
		|| map[inputX][inputY] == 2 || map[inputX][input_Y] == 2) {
			return true;
		}break; }
	
	case 3: {   //向右走的判断
		int inputX = this->TransformX(Right_Down[0] + this->steplength);
		int inputY = this->TransformY(Right_Down[1] - 1);
		int input_Y = this->TransformY(Right_Up[1]);
		if (map[inputX][inputY] == 3 || map[inputX][input_Y] == 3
		|| map[inputX][inputY] == 2 || map[inputX][input_Y] == 2) {
			return true;
		}break; }

	}
	return false;
}

//监听键盘然后执行坐标换算的操作，在此处不执行任何的贴图的操作
//此函数意在修改人物的坐标
void PlayerClass::KeyDown_Coordinates() {

		//表示道具种类的
		int PrizeKind;
		
		int inputX = this->TransformX(this->x);
		int inputY = this->TransformY(this->y);
		char choice = _getch();
		switch (choice)
		{
		case 'w':
		case 'W':
		case 72:
			//将方向转换为向上
			this->direction = 0;
			if (!IfCrash(0)) {//如果不撞墙
				PrizeKind = this->getPrize(this->direction);
				if (PrizeKind) {//如果前方是道具
					changeSelf(PrizeKind);
					imgNum++;
					this->x += steplength;
					if (imgNum == 4)
						imgNum = 0;
				}
				else {
					imgNum++;
					this->y -= steplength;
					if (imgNum == 4)
						imgNum = 0;
				}
			}break;
		case 's':
		case 'S':
		case 80:
			this->direction = 1;
			if (!IfCrash(1)) {
				PrizeKind = this->getPrize(this->direction);
				if (PrizeKind) {//如果前方是道具
					changeSelf(PrizeKind);
					imgNum++;
					this->x += steplength;
					if (imgNum == 4)
						imgNum = 0;
				}
				else {
					imgNum++;
					this->y += steplength;
					if (imgNum == 4)
						imgNum = 0;
				}
			}break;
		case 'a':
		case 'A':
		case 75:
			this->direction = 2;
			if (!IfCrash(2)) {
				PrizeKind = this->getPrize(this->direction);
				if (PrizeKind) {//如果前方是道具
					changeSelf(PrizeKind);
					imgNum++;
					this->x += steplength;
					if (imgNum == 4)
						imgNum = 0;
				}
				else {
					imgNum++;
					this->x -= steplength;
					if (imgNum == 4)
						imgNum = 0;
				}
			}break;
		case 'd':
		case 'D':
		case 77:
			this->direction = 3;
			if (!IfCrash(3)) {
				PrizeKind = this->getPrize(this->direction);
				if (PrizeKind) {//如果前方是道具
					changeSelf(PrizeKind);
					imgNum++;
					this->x += steplength;
					if (imgNum == 4)
						imgNum = 0;
				}
				else {
					imgNum++;
					this->x += steplength;
					if (imgNum == 4)
						imgNum = 0;
				}
			}break;
	
	}

}

//#######此处只贴人物
void PlayerClass::PutImage(int direction) {

		//PaintRoad(inputX, inputY, this->sight);
		int inputX = this->TransformX(this->x);
		int inputY = this->TransformY(this->y);
		//放下面的草地
		PaintRoad(inputX, inputY, this->sight);

		switch (direction) {
			//向上走
		case 0:
			//cleardevice();
			//PaintRoad(inputX, inputY, this->sight);
			putimage(this->return_X(x), this->return_Y(y), imageSize, imageSize, &roleY, imageSize * imgNum, imageSize * 3, SRCAND);
			putimage(this->return_X(x), this->return_Y(y), imageSize, imageSize, &role, imageSize * imgNum, imageSize * 3, SRCPAINT);
			break;
		case 1:

			putimage(this->return_X(x), this->return_Y(y), imageSize, imageSize, &roleY, imageSize * imgNum, imageSize * 0, SRCAND);
			putimage(this->return_X(x), this->return_Y(y), imageSize, imageSize, &role, imageSize * imgNum, imageSize * 0, SRCPAINT);
			break;
		case 2:

			putimage(this->return_X(x), this->return_Y(y), imageSize, imageSize, &roleY, imageSize * imgNum, imageSize * 1, SRCAND);
			putimage(this->return_X(x), this->return_Y(y), imageSize, imageSize, &role, imageSize * imgNum, imageSize * 1, SRCPAINT);
			break;
		case 3:

			putimage(this->return_X(x), this->return_Y(y), imageSize, imageSize, &roleY, imageSize * imgNum, imageSize * 2, SRCAND);
			putimage(this->return_X(x), this->return_Y(y), imageSize, imageSize, &role, imageSize * imgNum, imageSize * 2, SRCPAINT);
			break;
		}
		
}

//判断是否获胜
bool PlayerClass::isWin() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 15; j++) {
			//如果地图上存在6或7证明没有胜利
			if (map[i][j] == 6 || map[i][j] == 7) {
				return false;
			}
		}
	}
	return true;
}

//判断前方是否为道具
int PlayerClass::getPrize(int direction) {
	int inputX, inputY;
	switch (direction) {
	case 0://向上
		inputX = this->TransformX(this->x);
		inputY = this->TransformY(this->y-imageSize / 2 - 2);
		if (map[inputX][inputY] == 4) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 1;
		}
	
		if (map[inputX][inputY] == 5) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 2;
		}
		if (map[inputX][inputY] == 6) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 3;
		}
		if (map[inputX][inputY] == 7) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 4;
		}
		break;
	case 1://下
		inputX = this->TransformX(this->x);
		inputY = this->TransformY(this->y+imageSize / 2 +2);
		if (map[inputX][inputY] == 4) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 1;
		}
		if (map[inputX][inputY] == 5) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 2;
		}
		if (map[inputX][inputY] == 6) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 3;
		}
		if (map[inputX][inputY] == 7) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 4;
		}
		break;
	case 2://左
		inputX = this->TransformX(this->x-imageSize/2-2);
		inputY = this->TransformY(this->y);
		if (map[inputX][inputY] == 4) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 1;
		}
		if (map[inputX][inputY] == 5) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 2;
		}
		if (map[inputX][inputY] == 6) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 3;
		}
		if (map[inputX][inputY] == 7) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 4;
		}
		break;
	case 3://右
		inputX = this->TransformX(this->x + imageSize / 2 + 2);
		inputY = this->TransformY(this->y);
		if (map[inputX][inputY] == 4) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 1;
		}
		if (map[inputX][inputY] == 5) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 2;
		}
		if (map[inputX][inputY] == 6) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 3;
		}
		if (map[inputX][inputY] == 7) {
			map[inputX][inputY] = 0;//将图片重新贴成草地
			return 4;
		}
		break;
	}
	return 0;
}

//#########获得道具后的能力变化操作
void PlayerClass::changeSelf(int i) {
	switch (i) {
	case 1://加视野道具
		this->sight += 1;//视野值+1
		break;
	case 2://加速道具
		this->steplength += 2;
		break;
	case 3:  //魔鬼药水
		this->countWater += 1;
		break;
	case 4://碰到长老
		if (this->countWater != 3) {//收集到的药水不等于3
			MessageBox(GetForegroundWindow(), _T("只有三瓶魔法药水才能救长老，你没收集到三瓶反而害死了长老，你玩了小伙纸！！！"), _T("长老死了。。。"), 1);
			closegraph();
			exit(0);
		}

	}
	return;
}

void PlayerClass::GameInfo() {
	LOGFONT f;//这个结构体定义了字体的属性。
//########游戏名称
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 45;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("幼圆"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	f.lfWeight = 1000;				//字体粗细
	f.lfItalic = true;					//斜体
	settextcolor(GREEN);				//设置字体颜色
	settextstyle(&f);                     // 设置字体样式

	outtextxy(980, 30, _T("丛 林 大冒险"));
	
//######分割线
	setlinecolor(BLUE);               //设置划线颜色
	setlinestyle(
		PS_DASHDOTDOT,10,NULL,0
	);
	line(980,100,1300,100);							//画分割线


//######玩家信息部分
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 35;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("楷体"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	f.lfWeight = FW_BLACK;				//字体粗细
	//f.lfItalic = true;					//斜体
	settextcolor(WHITE);				//设置字体颜色
	settextstyle(&f);                     // 设置字体样式
	outtextxy(1060,125,_T("玩家信息"));

	setlinecolor(WHITE);               //设置划线颜色
	setlinestyle(
		0, 2, NULL, 0
	);
	line(980, 160, 1300, 160);							//画分割线
	line(975, 0, 975, 800);							//画分割线

	////信息字符串
	//string information;
	//information = "视 野 范 围 ：					" + to_string(player.sight)+"\n"
	//			+ "行 走 速 度 ：					" + to_string(player.sight)+"\n"
	//			+ "魔 法 药 水 ：				    " + to_string(player.sight)+"\n";
//#######玩家信息在此输出

	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 25;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("楷体"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	f.lfWeight = FW_BLACK;				//字体粗细
	f.lfItalic = false;					//斜体
	settextcolor(WHITE);				//设置字体颜色
	settextstyle(&f);                     // 设置字体样式


	TCHAR str[16];//字符数组
	outtextxy(1000, 180, _T("视野范围  ："));
	swprintf_s(str, _T("%d"),this->sight);  //如果项目属性选用多字符集可不加_T     
	outtextxy(1250, 180, str);

	outtextxy(1000, 220, _T("行走速度  ："));
	swprintf_s(str, _T("%d"), this->steplength);  //如果项目属性选用多字符集可不加_T     
	outtextxy(1250, 220, str);

	outtextxy(1000, 260, _T("魔法药水数："));
	swprintf_s(str, _T("%d"), this->countWater);  //如果项目属性选用多字符集可不加_T     
	outtextxy(1250, 260, str);


//#######分割线
	line(980, 300, 1300, 300);							//画分割线


	setlinecolor(GREEN);               //设置划线颜色
	setlinestyle(
		PS_DASHDOTDOT, 10, NULL, 0
	);
	line(980, 320, 1300, 320);							//画分割线


//######说明部分########
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 35;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("楷体"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	f.lfWeight = FW_BLACK;				//字体粗细
	f.lfItalic = true;					//斜体
	settextcolor(WHITE);				//设置字体颜色
	settextstyle(&f);                     // 设置字体样式
	outtextxy(1060, 340, _T("游戏说明"));

//#######再来一条分割线
	setlinecolor(WHITE);               //设置划线颜色
	setlinestyle(
		0, 2, NULL, 0
	);
	line(980, 380, 1300, 380);							//画分割线

//######说明部分

	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 25;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("宋体"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	f.lfWeight = FW_BLACK;				//字体粗细
	f.lfItalic = false;					//斜体
	settextcolor(WHITE);				//设置字体颜色
	settextstyle(&f);                     // 设置字体样式

	outtextxy(980, 400, _T("游戏说明: "));
	outtextxy(980, 430, _T("在暗黑的丛林里藏匿着三个"));
	outtextxy(980, 460, _T("世间罕见的魔法药水，只有"));
	outtextxy(980, 490, _T("收集全部三个蓝色魔法药水"));
	outtextxy(980, 520, _T("才能救出被封印的精灵长老！"));
	outtextxy(980, 550, _T("还有一些魔法道具可能对你"));
	outtextxy(980, 580, _T("有所帮助，它们能让你加速"));
	outtextxy(980, 610, _T("或者拓宽视野。加油勇士！"));

//######最后提示语

	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 35;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("楷体"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	f.lfWeight = FW_BLACK;				//字体粗细
	f.lfItalic = true;					//斜体
	settextcolor(RED);				//设置字体颜色
	settextstyle(&f);                     // 设置字体样式
	outtextxy(980, 650, _T("救出长老"));
	outtextxy(980, 700, _T("获得神秘大礼！！！"));


//贴长老
	putimage(730,130,50, 50, &PRIZE_Y, 100, 0, SRCAND);
	putimage(730, 130, 50, 50, &PRIZE, 100, 0, SRCPAINT);
}

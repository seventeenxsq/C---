#include "GameClass.h"
#include<graphics.h>
#include<String>
//弹窗的头文件
#include<mmsystem.h>		//与多媒体的接口
#include<Windows.h>
#pragma comment(lib,"winmm.lib")
using namespace std;


GameClass::GameClass()
{
	loadimage(&FIRST, _T("welcome.jpg"));
	loadimage(&BTN, _T("开始游戏.jpg"));
}

GameClass::~GameClass()
{
}


//###胜利以后
void GameClass::HaveWin() {
	MessageBox(GetForegroundWindow(),_T("勇士，谢谢你救了我，这是我们族最珍贵的宝贝请你收下！么么哒"), _T("长老大喘一口气"),1);
	MessageBox(GetForegroundWindow(), _T("颜值主播 乔碧罗 +1"), _T("恭喜获得"), 1);
	MessageBox(GetForegroundWindow(), _T("蔡徐坤篮球 +1"), _T("恭喜获得"), 1);
//####添加音乐“鸡你太美”
	mciSendString(L"open 鸡你太美.mp3", 0, 0, 0);
	mciSendString(L"play 鸡你太美.mp3", 0, 0, 0);

	getchar();
	//mciSendString(L"close 鸡你太美.mp3", 0, 0, 0);
}

//###欢迎界面
void GameClass::welcomeActivity() {

	//初始化画布
	initgraph(600, 600);
	putimage(0, 0, &FIRST);
	outtextxy(250,500,_T("点击开始冒险"));
	mciSendString(L"open play.wav", 0, 0, 0);
	mciSendString(L"play play.wav", 0, 0, 0);
	//鼠标消息结构体
	MOUSEMSG mouse;
	//
	while (1) {
		FlushMouseMsgBuffer();//每次刷新鼠标消息池
	    mouse = GetMouseMsg();//判断鼠标有无点击左键
		if (mouse.mkLButton==true)break;
	}
	mciSendString(L"close play.wav", 0, 0, 0);
	closegraph();
}


void GameClass::Run() {
	initgraph(1300, 850);
	mciSendString(L"open mysoul.mp3", 0, 0, 0);
	mciSendString(L"play mysoul.mp3", 0, 0, 0);
	MessageBox(GetForegroundWindow(), _T("先收集三个蓝色的魔法药水，即可解救被封印的长老，还有些道具给你帮助"), _T("任务拯救长老！"), 1);
	PlayerClass player1(30, 250);
	//Monster monster1(500, 500);

	//在适当的地方初始化人物
	/*player1.PaintRoad(1,5,1);
	player1.PutImage(3);*/


	while (1) {
		//清屏
		cleardevice();
		player1.GameInfo();
		//判断是否胜利   如果胜利跳出循环
		if (player1.isWin()) { break; }
		//监听键盘
		player1.KeyDown_Coordinates();

		BeginBatchDraw();
		//下面执行贴图操作
		player1.PutImage(player1.direction);
		FlushBatchDraw();
	}
	mciSendString(L"close mysoul.mp3", 0, 0, 0);

	//getchar();
	//关闭画布
	//closegraph();


}
#include "GameClass.h"
#include<graphics.h>
#include<String>
//������ͷ�ļ�
#include<mmsystem.h>		//���ý��Ľӿ�
#include<Windows.h>
#pragma comment(lib,"winmm.lib")
using namespace std;


GameClass::GameClass()
{
	loadimage(&FIRST, _T("welcome.jpg"));
	loadimage(&BTN, _T("��ʼ��Ϸ.jpg"));
}

GameClass::~GameClass()
{
}


//###ʤ���Ժ�
void GameClass::HaveWin() {
	MessageBox(GetForegroundWindow(),_T("��ʿ��лл������ң����������������ı����������£�ôô��"), _T("���ϴ�һ����"),1);
	MessageBox(GetForegroundWindow(), _T("��ֵ���� �Ǳ��� +1"), _T("��ϲ���"), 1);
	MessageBox(GetForegroundWindow(), _T("���������� +1"), _T("��ϲ���"), 1);
//####������֡�����̫����
	mciSendString(L"open ����̫��.mp3", 0, 0, 0);
	mciSendString(L"play ����̫��.mp3", 0, 0, 0);

	getchar();
	//mciSendString(L"close ����̫��.mp3", 0, 0, 0);
}

//###��ӭ����
void GameClass::welcomeActivity() {

	//��ʼ������
	initgraph(600, 600);
	putimage(0, 0, &FIRST);
	outtextxy(250,500,_T("�����ʼð��"));
	mciSendString(L"open play.wav", 0, 0, 0);
	mciSendString(L"play play.wav", 0, 0, 0);
	//�����Ϣ�ṹ��
	MOUSEMSG mouse;
	//
	while (1) {
		FlushMouseMsgBuffer();//ÿ��ˢ�������Ϣ��
	    mouse = GetMouseMsg();//�ж�������޵�����
		if (mouse.mkLButton==true)break;
	}
	mciSendString(L"close play.wav", 0, 0, 0);
	closegraph();
}


void GameClass::Run() {
	initgraph(1300, 850);
	mciSendString(L"open mysoul.mp3", 0, 0, 0);
	mciSendString(L"play mysoul.mp3", 0, 0, 0);
	MessageBox(GetForegroundWindow(), _T("���ռ�������ɫ��ħ��ҩˮ�����ɽ�ȱ���ӡ�ĳ��ϣ�����Щ���߸������"), _T("�������ȳ��ϣ�"), 1);
	PlayerClass player1(30, 250);
	//Monster monster1(500, 500);

	//���ʵ��ĵط���ʼ������
	/*player1.PaintRoad(1,5,1);
	player1.PutImage(3);*/


	while (1) {
		//����
		cleardevice();
		player1.GameInfo();
		//�ж��Ƿ�ʤ��   ���ʤ������ѭ��
		if (player1.isWin()) { break; }
		//��������
		player1.KeyDown_Coordinates();

		BeginBatchDraw();
		//����ִ����ͼ����
		player1.PutImage(player1.direction);
		FlushBatchDraw();
	}
	mciSendString(L"close mysoul.mp3", 0, 0, 0);

	//getchar();
	//�رջ���
	//closegraph();


}
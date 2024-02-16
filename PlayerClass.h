#pragma once
#include"RoleClass.h"
#include<graphics.h>

//�����̳�Role��
class PlayerClass :public RoleClass
{
public:   //��ʼ�����������
	PlayerClass(int x, int y);
	~PlayerClass();

	int x, y;//�������������

	int direction;  //0 1 2 3--��������

	int sight;//��Ұ
	
	//ħ��ҩˮ����
	int countWater;

	//ͼƬ��С
	int imageSize;

	//����ÿ��һ������������ĵ�ͼ����
	void PaintRoad(int i, int j, int sight);

	//�ж��Ƿ�ײǽ�ĺ���
	bool IfCrash(int direction);

	//�������̣����õ���������ĵ�����
	void KeyDown_Coordinates();

	//����ͼƬ��
	IMAGE ground;
	IMAGE BOX, TREE, HOUSE, BOX_Y, TREE_Y, HOUSE_Y;
	IMAGE PRIZE, PRIZE_Y;

	//�ٽ����ĵ�����ת�������Ͻǵ����꺯������
	int return_X(int x);
	int return_Y(int y);

	//�жϻ�ʤ
	bool isWin();

	//��ͼ����
	void PutImage(int direction);

	//ײ������
	int getPrize(int direction);

	//��õ��ߺ�ĸı����
	void changeSelf(int i);


	void GameInfo();

private:
	//int x, y;//���������
	IMAGE role,roleY;//��������
	
};


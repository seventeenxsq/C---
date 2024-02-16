#include "PlayerClass.h"
#include<graphics.h>
#include<stdio.h>
#include<conio.h>  
#include<stdlib.h>

//#####��ͼ����   extern�������ļ�
/*
	0   �ݵ�
	1	ľ��
	2	��ľ
	3	����
	4	������Ұ����
	5	���ٵ���
	6	ħ��ҩˮ
	7	��ȳ��ϣ��յ㣩
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

//���ߵ�ͼƬ֡
int imgNum=1;

//�˴��޸�ͼ��Ĵ�С ���ٶ�,,���ﴫ������������������
PlayerClass::PlayerClass(int x, int y)
{
	this->imageSize = 40;
	this->x = x+ imageSize /2; this->y = y+ imageSize /2;
	sight=1;
	this->steplength = 3;
	this->countWater = 0;

//########�˴��޸�ͼ��Ĵ�С###################
	

	//���򣬳�ʼ��Ϊ����
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

//�������Ͻǵ�����ֵ
int PlayerClass:: return_X(int x) {
	return (x - imageSize / 2);
}
int PlayerClass::return_Y(int y) {
	return (y - imageSize / 2);
}

//�ֲ����Ƶ�ͼ  X��Y��ʾת���ɾ����λ��
void PlayerClass::PaintRoad(int X, int Y, int sight) {

	//��ѭ��
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
			case 4:	//������Ұ
				putimage(i * 50 + 30, j * 50 + 30, &ground);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE_Y, 0, 0,SRCAND);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE, 0, 0,SRCPAINT);
				break;
			case 5://����
				putimage(i * 50 + 30, j * 50 + 30, &ground);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE_Y, 150, 0, SRCAND);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE, 150, 0, SRCPAINT);
				break;
			case 6://ħ��ҩˮ
				putimage(i * 50 + 30, j * 50 + 30, &ground);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE_Y, 50, 0, SRCAND);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE, 50, 0, SRCPAINT);
				break;
			case 7://�յ㳤��
				putimage(i * 50 + 30, j * 50 + 30, &ground);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE_Y, 100, 0, SRCAND);
				putimage(i * 50 + 30, j * 50 + 30, 50, 50, &PRIZE, 100, 0, SRCPAINT);
				break;
			}
		}
	}
}

//############putimage�����������Ͻǣ�����Ҫ����x,y��ת�������Ͻ����ꡣ


//��д�Ƿ���ײ����
bool PlayerClass::IfCrash(int direction) {

	//�洢������������ֵ
	//���Ͻ� 
	int Right_Up[2] = { this->x + imageSize / 2,this->y - imageSize / 2 };
	//���Ͻ�
	int Left_Up[2] = { this->x - imageSize / 2,this->y - imageSize / 2 };
	//���½�
	int Left_Down[2] = { this->x - imageSize / 2,this->y + imageSize / 2 };
	//���½�
	int Right_Down[2] = { this->x + imageSize / 2,this->y + imageSize / 2 };

	switch (direction) {

	case 0: {	//�����ߵ��ж�
		int inputX = this->TransformX(Right_Up[0] - 1);//ת�����˾��������
		int inputY = this->TransformY(Right_Up[1] - this->steplength);
		int input_X = this->TransformX(Left_Up[0]);
		//
		if (map[inputX][inputY] == 3 || map[input_X][inputY] == 3
			||map[inputX][inputY] == 2 || map[input_X][inputY] == 2) {
			return true;
		}break; }

	case 1: { //�����ߵ��ж�
		int inputX = this->TransformX(Right_Down[0] - 1);
		int inputY = this->TransformY(Right_Down[1] + this->steplength);
		int input_X = this->TransformX(Left_Down[0]);
		if (map[inputX][inputY] == 3 || map[input_X][inputY] == 3
			|| map[inputX][inputY] == 2 || map[input_X][inputY] == 2) {
			return true;
		}break; }

	case 2: {  //�����ߵ��ж�
		int inputX = this->TransformX(Left_Down[0] - this->steplength);
		int inputY = this->TransformY(Left_Down[1] - 1);
		int input_Y = this->TransformY(Left_Up[1]);
		if (map[inputX][inputY] == 3 || map[inputX][input_Y] == 3
		|| map[inputX][inputY] == 2 || map[inputX][input_Y] == 2) {
			return true;
		}break; }
	
	case 3: {   //�����ߵ��ж�
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

//��������Ȼ��ִ�����껻��Ĳ������ڴ˴���ִ���κε���ͼ�Ĳ���
//�˺��������޸����������
void PlayerClass::KeyDown_Coordinates() {

		//��ʾ���������
		int PrizeKind;
		
		int inputX = this->TransformX(this->x);
		int inputY = this->TransformY(this->y);
		char choice = _getch();
		switch (choice)
		{
		case 'w':
		case 'W':
		case 72:
			//������ת��Ϊ����
			this->direction = 0;
			if (!IfCrash(0)) {//�����ײǽ
				PrizeKind = this->getPrize(this->direction);
				if (PrizeKind) {//���ǰ���ǵ���
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
				if (PrizeKind) {//���ǰ���ǵ���
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
				if (PrizeKind) {//���ǰ���ǵ���
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
				if (PrizeKind) {//���ǰ���ǵ���
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

//#######�˴�ֻ������
void PlayerClass::PutImage(int direction) {

		//PaintRoad(inputX, inputY, this->sight);
		int inputX = this->TransformX(this->x);
		int inputY = this->TransformY(this->y);
		//������Ĳݵ�
		PaintRoad(inputX, inputY, this->sight);

		switch (direction) {
			//������
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

//�ж��Ƿ��ʤ
bool PlayerClass::isWin() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 15; j++) {
			//�����ͼ�ϴ���6��7֤��û��ʤ��
			if (map[i][j] == 6 || map[i][j] == 7) {
				return false;
			}
		}
	}
	return true;
}

//�ж�ǰ���Ƿ�Ϊ����
int PlayerClass::getPrize(int direction) {
	int inputX, inputY;
	switch (direction) {
	case 0://����
		inputX = this->TransformX(this->x);
		inputY = this->TransformY(this->y-imageSize / 2 - 2);
		if (map[inputX][inputY] == 4) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 1;
		}
	
		if (map[inputX][inputY] == 5) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 2;
		}
		if (map[inputX][inputY] == 6) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 3;
		}
		if (map[inputX][inputY] == 7) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 4;
		}
		break;
	case 1://��
		inputX = this->TransformX(this->x);
		inputY = this->TransformY(this->y+imageSize / 2 +2);
		if (map[inputX][inputY] == 4) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 1;
		}
		if (map[inputX][inputY] == 5) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 2;
		}
		if (map[inputX][inputY] == 6) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 3;
		}
		if (map[inputX][inputY] == 7) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 4;
		}
		break;
	case 2://��
		inputX = this->TransformX(this->x-imageSize/2-2);
		inputY = this->TransformY(this->y);
		if (map[inputX][inputY] == 4) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 1;
		}
		if (map[inputX][inputY] == 5) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 2;
		}
		if (map[inputX][inputY] == 6) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 3;
		}
		if (map[inputX][inputY] == 7) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 4;
		}
		break;
	case 3://��
		inputX = this->TransformX(this->x + imageSize / 2 + 2);
		inputY = this->TransformY(this->y);
		if (map[inputX][inputY] == 4) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 1;
		}
		if (map[inputX][inputY] == 5) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 2;
		}
		if (map[inputX][inputY] == 6) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 3;
		}
		if (map[inputX][inputY] == 7) {
			map[inputX][inputY] = 0;//��ͼƬ�������ɲݵ�
			return 4;
		}
		break;
	}
	return 0;
}

//#########��õ��ߺ�������仯����
void PlayerClass::changeSelf(int i) {
	switch (i) {
	case 1://����Ұ����
		this->sight += 1;//��Ұֵ+1
		break;
	case 2://���ٵ���
		this->steplength += 2;
		break;
	case 3:  //ħ��ҩˮ
		this->countWater += 1;
		break;
	case 4://��������
		if (this->countWater != 3) {//�ռ�����ҩˮ������3
			MessageBox(GetForegroundWindow(), _T("ֻ����ƿħ��ҩˮ���ܾȳ��ϣ���û�ռ�����ƿ���������˳��ϣ�������С��ֽ������"), _T("�������ˡ�����"), 1);
			closegraph();
			exit(0);
		}

	}
	return;
}

void PlayerClass::GameInfo() {
	LOGFONT f;//����ṹ�嶨������������ԡ�
//########��Ϸ����
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 45;                      // ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("��Բ"));    // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	f.lfWeight = 1000;				//�����ϸ
	f.lfItalic = true;					//б��
	settextcolor(GREEN);				//����������ɫ
	settextstyle(&f);                     // ����������ʽ

	outtextxy(980, 30, _T("�� �� ��ð��"));
	
//######�ָ���
	setlinecolor(BLUE);               //���û�����ɫ
	setlinestyle(
		PS_DASHDOTDOT,10,NULL,0
	);
	line(980,100,1300,100);							//���ָ���


//######�����Ϣ����
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 35;                      // ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	f.lfWeight = FW_BLACK;				//�����ϸ
	//f.lfItalic = true;					//б��
	settextcolor(WHITE);				//����������ɫ
	settextstyle(&f);                     // ����������ʽ
	outtextxy(1060,125,_T("�����Ϣ"));

	setlinecolor(WHITE);               //���û�����ɫ
	setlinestyle(
		0, 2, NULL, 0
	);
	line(980, 160, 1300, 160);							//���ָ���
	line(975, 0, 975, 800);							//���ָ���

	////��Ϣ�ַ���
	//string information;
	//information = "�� Ұ �� Χ ��					" + to_string(player.sight)+"\n"
	//			+ "�� �� �� �� ��					" + to_string(player.sight)+"\n"
	//			+ "ħ �� ҩ ˮ ��				    " + to_string(player.sight)+"\n";
//#######�����Ϣ�ڴ����

	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 25;                      // ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	f.lfWeight = FW_BLACK;				//�����ϸ
	f.lfItalic = false;					//б��
	settextcolor(WHITE);				//����������ɫ
	settextstyle(&f);                     // ����������ʽ


	TCHAR str[16];//�ַ�����
	outtextxy(1000, 180, _T("��Ұ��Χ  ��"));
	swprintf_s(str, _T("%d"),this->sight);  //�����Ŀ����ѡ�ö��ַ����ɲ���_T     
	outtextxy(1250, 180, str);

	outtextxy(1000, 220, _T("�����ٶ�  ��"));
	swprintf_s(str, _T("%d"), this->steplength);  //�����Ŀ����ѡ�ö��ַ����ɲ���_T     
	outtextxy(1250, 220, str);

	outtextxy(1000, 260, _T("ħ��ҩˮ����"));
	swprintf_s(str, _T("%d"), this->countWater);  //�����Ŀ����ѡ�ö��ַ����ɲ���_T     
	outtextxy(1250, 260, str);


//#######�ָ���
	line(980, 300, 1300, 300);							//���ָ���


	setlinecolor(GREEN);               //���û�����ɫ
	setlinestyle(
		PS_DASHDOTDOT, 10, NULL, 0
	);
	line(980, 320, 1300, 320);							//���ָ���


//######˵������########
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 35;                      // ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	f.lfWeight = FW_BLACK;				//�����ϸ
	f.lfItalic = true;					//б��
	settextcolor(WHITE);				//����������ɫ
	settextstyle(&f);                     // ����������ʽ
	outtextxy(1060, 340, _T("��Ϸ˵��"));

//#######����һ���ָ���
	setlinecolor(WHITE);               //���û�����ɫ
	setlinestyle(
		0, 2, NULL, 0
	);
	line(980, 380, 1300, 380);							//���ָ���

//######˵������

	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 25;                      // ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	f.lfWeight = FW_BLACK;				//�����ϸ
	f.lfItalic = false;					//б��
	settextcolor(WHITE);				//����������ɫ
	settextstyle(&f);                     // ����������ʽ

	outtextxy(980, 400, _T("��Ϸ˵��: "));
	outtextxy(980, 430, _T("�ڰ��ڵĴ��������������"));
	outtextxy(980, 460, _T("���亱����ħ��ҩˮ��ֻ��"));
	outtextxy(980, 490, _T("�ռ�ȫ��������ɫħ��ҩˮ"));
	outtextxy(980, 520, _T("���ܾȳ�����ӡ�ľ��鳤�ϣ�"));
	outtextxy(980, 550, _T("����һЩħ�����߿��ܶ���"));
	outtextxy(980, 580, _T("�����������������������"));
	outtextxy(980, 610, _T("�����ؿ���Ұ��������ʿ��"));

//######�����ʾ��

	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 35;                      // ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	f.lfWeight = FW_BLACK;				//�����ϸ
	f.lfItalic = true;					//б��
	settextcolor(RED);				//����������ɫ
	settextstyle(&f);                     // ����������ʽ
	outtextxy(980, 650, _T("�ȳ�����"));
	outtextxy(980, 700, _T("������ش��񣡣���"));


//������
	putimage(730,130,50, 50, &PRIZE_Y, 100, 0, SRCAND);
	putimage(730, 130, 50, 50, &PRIZE, 100, 0, SRCPAINT);
}

#pragma once


 class RoleClass
{
public:
	RoleClass();
	~RoleClass(); 

	//����
	int steplength;
	//�ж��Ƿ�ײǽ�ĺ���
	bool IfCrash();

	//����ת������**�����������Ƿ�ײǽ
	int TransformX(int x);

	int TransformY(int y);

	//void KeyDown();

private:
	//int speed;//�ٶ�
};


#include "RoleClass.h"

RoleClass::RoleClass()
{
}

RoleClass::~RoleClass()
{
}

///#####���ڵ����������ĵ��������########
//����ת������,ת���ɾ����Ӧ������
int RoleClass::TransformX(int x) {
	return int((x - 30) / 50);
}

int RoleClass::TransformY(int y) {
	return int((y - 30) / 50);
}

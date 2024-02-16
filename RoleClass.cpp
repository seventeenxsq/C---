#include "RoleClass.h"

RoleClass::RoleClass()
{
}

RoleClass::~RoleClass()
{
}

///#####现在的坐标是中心点的坐标了########
//坐标转换函数,转换成矩阵对应的坐标
int RoleClass::TransformX(int x) {
	return int((x - 30) / 50);
}

int RoleClass::TransformY(int y) {
	return int((y - 30) / 50);
}

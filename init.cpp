#include "windows.h"

/// <summary>
/// ������� �������������� ��������� ������� ��� �������
/// </summary>
void initConsoleSettings()
{
	system("color F0");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	system("title ���������� �������� ��� �����������");
}
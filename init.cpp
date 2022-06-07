#include "windows.h"

/// <summary>
/// Функция инициализирует настройки консоли для проекта
/// </summary>
void initConsoleSettings()
{
	system("color F0");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	system("title Реализация операций над множествами");
}
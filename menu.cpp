#include <iostream>
#include <set>

#include "menu.h"
#include "sets.h"

using std::cout;
using std::cin;
using std::endl;
using std::set;
using std::string;

namespace menu {

	/// <summary>
	/// Запускает основную работу меню
	/// </summary>
	/// <returns> bool projectStatus </returns>
	bool work()
	{
		bool projectStatus = true;
		short int operation;

		menu::showMenu();

		operation = menu::changeOperation();

		switch (operation) {
			case 1: menu::equality(); break;
			case 2: menu::subset(); break;
			case 3: menu::merge(); break;
			case 4: menu::intersection(); break;
			case 5: menu::difference(); break;
			case 6: menu::symmetricalDifference(); break;
			case 7: menu::clearScreen(); break;
			case 8:
				cout << "Программа завершила свою работу. " << endl;
				projectStatus = false;
				break;
			default:
				cout << "Элемент меню выбран неверно!" << endl;
				break;
		}

		return projectStatus;
	}

	/// <summary>
	/// Показывает доступные элементы меню
	/// </summary>
	void showMenu()
	{
		cout << endl;
		printLine();
		cout << "Меню: " << endl;
		cout << "1. Равенство множеств" << endl;
		cout << "2. Проверка на подмножество" << endl;
		cout << "3. Объединение множеств" << endl;
		cout << "4. Пересечение множеств" << endl;
		cout << "5. Разность множеств" << endl;
		cout << "6. Симметрическая разность множеств" << endl;
		cout << "7. Очистить экран" << endl;
		cout << "8. Завершить" << endl;
		printLine();
	}

	/// <summary>
	/// Вводит элемент меню, а затем возвращает его
	/// </summary>
	/// <returns> int operation </returns>
	short int changeOperation()
	{
		short int operation;

		cout << "Выберите операцию (введите соответствующую цифру):" << endl;
		cin >> operation;

		return operation;
	}

	/// <summary>
	/// Запускает проверку множеств на равенство
	/// </summary>
	void equality()
	{
		//Выводим заголовок
		printOperationHeader("Проверка множеств A и B на равенство: ");

		//Вводим множество A, создаём указатель, выводим множество на экран
		set<string> setA = sets::enterSet("A");
		set<string>* pointerSetA = &setA;
		cout << sets::prepareToPrint(pointerSetA, "A") << endl;

		//Вводим множество B, создаём указатель, выводим множество на экран
		set<string> setB = sets::enterSet("B");
		set<string>* pointerSetB = &setB;
		cout << sets::prepareToPrint(pointerSetB, "B") << endl;

		//Проверяем результат и выводим его
		if (sets::checkEquality(pointerSetA, pointerSetB))
			printResult("Множества равны");
		else
			printResult("Множества не равны");
	}

	/// <summary>
	/// Запускает проверку на помножество
	/// </summary>
	void subset()
	{
		//Выводим заголовок
		printOperationHeader("Проверка, является ли множество А подмножеством B: ");

		//Вводим множество A, создаём указатель, выводим множество на экран
		set<string> setA = sets::enterSet("A");
		set<string>* pointerSetA = &setA;
		cout << sets::prepareToPrint(pointerSetA, "A") << endl;

		//Вводим множество B, создаём указатель, выводим множество на экран
		set<string> setB = sets::enterSet("B");
		set<string>* pointerSetB = &setB;
		cout << sets::prepareToPrint(pointerSetB, "B") << endl;

		if (sets::checkSubset(pointerSetA, pointerSetB))
			printResult("А является подмножеством B.");
		else
			printResult("А не является подмножеством B.");
	}

	/// <summary>
	/// Запускает операцию объединения множеств
	/// </summary>
	void merge()
	{
		//Выводим заголовок
		printOperationHeader("Объединение множеств A и B: ");

		//Вводим множество A, создаём указатель, выводим множество на экран
		set<string> setA = sets::enterSet("A");
		set<string>* pointerSetA = &setA;
		cout << sets::prepareToPrint(pointerSetA, "A") << endl;

		//Вводим множество B, создаём указатель, выводим множество на экран
		set<string> setB = sets::enterSet("B");
		set<string>* pointerSetB = &setB;
		cout << sets::prepareToPrint(pointerSetB, "B") << endl;

		//Объединяем 2 множества
		set<string> setC = sets::merge(pointerSetA, pointerSetB);
		set<string>* pointerSetC = &setC; //Создаём указатель для передачи в функцию вывода

		//Выводим результат
		printResult(sets::prepareToPrint(pointerSetC, "C"));
	}

	/// <summary>
	/// Запускает операцию пересечения множеств
	/// </summary>
	void intersection()
	{
		//Выводим заголовок
		printOperationHeader("Пересечение множеств A и B: ");

		//Вводим множество A, создаём указатель, выводим множество на экран
		set<string> setA = sets::enterSet("A");
		set<string>* pointerSetA = &setA;
		cout << sets::prepareToPrint(pointerSetA, "A") << endl;

		//Вводим множество B, создаём указатель, выводим множество на экран
		set<string> setB = sets::enterSet("B");
		set<string>* pointerSetB = &setB;
		cout << sets::prepareToPrint(pointerSetB, "B") << endl;

		//Пересекаем 2 множества
		set<string> setC = sets::intersection(pointerSetA, pointerSetB);
		set<string>* pointerSetC = &setC; //Создаём указатель для передачи в функцию вывода

		//Выводим результат
		printResult(sets::prepareToPrint(pointerSetC, "C"));
	}

	/// <summary>
	/// Запускает операцию разности множеств
	/// </summary>
	void difference()
	{
		//Выводим заголовок
		printOperationHeader("Разность множеств A и B: ");

		//Вводим множество A, создаём указатель, выводим множество на экран
		set<string> setA = sets::enterSet("A");
		set<string>* pointerSetA = &setA;
		cout << sets::prepareToPrint(pointerSetA, "A") << endl;

		//Вводим множество B, создаём указатель, выводим множество на экран
		set<string> setB = sets::enterSet("B");
		set<string>* pointerSetB = &setB;
		cout << sets::prepareToPrint(pointerSetB, "B") << endl;

		//Выполняем операцию разности множеств
		set<string> setC = sets::difference(pointerSetA, pointerSetB);
		set<string>* pointerSetC = &setC; //Создаём указатель для передачи в функцию вывода

		//Выводим результат
		printResult(sets::prepareToPrint(pointerSetC, "C"));
	}

	/// <summary>
	/// Запускает операцию симметрической разности множеств
	/// </summary>
	void symmetricalDifference()
	{
		//Выводим заголовок
		printOperationHeader("Симметрическая разность множеств A и B: ");

		//Вводим множество A, создаём указатель, выводим множество на экран
		set<string> setA = sets::enterSet("A");
		set<string>* pointerSetA = &setA;
		cout << sets::prepareToPrint(pointerSetA, "A") << endl;

		//Вводим множество B, создаём указатель, выводим множество на экран
		set<string> setB = sets::enterSet("B");
		set<string>* pointerSetB = &setB;
		cout << sets::prepareToPrint(pointerSetB, "B") << endl;

		//Выполняем операцию симметрической разности множеств
		set<string> setC = sets::symmetricalDifference(pointerSetA, pointerSetB);
		set<string>* pointerSetC = &setC; //Создаём указатель для передачи в функцию вывода

		//Выводим результат
		printResult(sets::prepareToPrint(pointerSetC, "C"));
	}

	/// <summary>
	/// Очищает экран консоли от выведенного текста
	/// </summary>
	void clearScreen()
	{
		system("cls");
	}

	/// <summary>
	/// Эта функция выводит результат на экран (сверху отступ и гор. черта, затем сам результат)
	/// </summary>
	/// <param name="text"> Текст результирующего сообщения </param>
	void printResult(const string text)
	{
		cout << endl;
		printLine();
		cout << "Результат: " << text << endl;
	}

	/// <summary>
	/// Выводит заголовок операции на экран
	/// </summary>
	/// <param name="text"> Текст заголовка </param>
	void printOperationHeader(const string text)
	{
		printLine();
		cout << text << endl << endl;
	}

	/// <summary>
	/// Выводит линию из тире на экран
	/// </summary>
	void printLine()
	{
		cout << "--------------------------------------------------" << endl;
	}
}
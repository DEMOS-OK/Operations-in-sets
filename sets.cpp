#include <set>
#include <string>
#include <iostream>

#include "sets.h"

using std::set;
using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::endl;

namespace sets {

	/// <summary>
	/// Возвращает множество элементов, полученных из введённой строки
	/// </summary>
	/// <param name="nameOfSet"> Имя множества (будет выводиться в консоли) </param>
	/// <returns> Множество введённых элементов </returns>
	set<string> enterSet(const string nameOfSet)
	{
		string inputString;
		set<string> createdSet;
		set<string>* pointerSet = &createdSet;

		//Ввод множества в строку через пробел
		cout << "Введите элементы множества " << nameOfSet << " через пробел:" << endl;
		getline(cin, inputString);
		if (inputString == "\n" || inputString.empty()) {
			getline(cin, inputString);
		}

		//Заполняем множество элементами из введённой строки
		sets::fillSetFromString(pointerSet, inputString);

		return createdSet;
	}

	/// <summary>
	/// Выводит запись вида "A = {a1,a2,a3,a4}"
	/// </summary>
	/// <param name="pointerSet"> Указатель на множество </param>
	/// <param name="nameOfSet"> Имя множества </param>
	string prepareToPrint(set<string>* pointerSet, const string nameOfSet)
	{
		string strToPrint = nameOfSet + " = {";
		short i = 0;
		for (auto element : *pointerSet) {
			strToPrint += element;
			if (i != pointerSet->size() - 1)
				strToPrint += ", ";
			i++;
		}
		strToPrint += "}";

		return strToPrint;
	}

	/// <summary>
	/// Заполняет переданное множество элементами из переданной строки
	/// </summary>
	/// <param name="pointerSet"> Указатель на множество </param>
	/// <param name="inputString"></param>
	void fillSetFromString(set<string>* pointerSet, string inputString)
	{
		size_t pos = 0;
		string delim = " "; //Разделитель
		while ((pos = inputString.find(delim)) != string::npos) { //Находим позицию пробела
			pointerSet->insert(inputString.substr(0, pos)); //Добавляем подстроку строки до пробела
			inputString.erase(0, pos + delim.length()); //Укорачиваем строку
		}
		if (!inputString.empty())
			pointerSet->insert(inputString); //Учитываем последний элемент строки
	}

	/// <summary>
	/// Проверяет 2 множества на равенство
	/// </summary>
	/// <param name="pointerSetA"> Указатель на первое множество </param>
	/// <param name="pointerSetB"> Указатель на второе множество </param>
	/// <returns> true, если множества равны, иначе false</returns>
	bool checkEquality(set<string>* pointerSetA, set<string>* pointerSetB)
	{
		return (*pointerSetA) == (*pointerSetB);
	}

	/// <summary>
	///	Проверяет, что множество A является подмножеством множества B
	/// </summary>
	/// <param name="pointerSetA"> Указатель на множество A </param>
	/// <param name="pointerSetB"> Указатель на множество B </param>
	/// <returns> bool </returns>
	bool checkSubset(set<string>* pointerSetA, set<string>* pointerSetB)
	{
		if (pointerSetA->empty())
			return true;

		for (auto elementA : *pointerSetA)
			if (!sets::elementInSet(elementA, pointerSetB))
				return false;

		return true;
	}

	/// <summary>
	/// Проверяет, есть ли элемент в множестве
	/// </summary>
	/// <param name="elementA"> элемент, который нужно найти </param>
	/// <param name="pointerSetB"> указатель на множество, в котором нужно найти </param>
	/// <returns> bool </returns>
	bool elementInSet(const string elementA, set <string>* pointerSetB)
	{
		for (auto elementB : *pointerSetB)
			if (elementA == elementB)
				return true;

		return false;
	}


	/// <summary>
	/// Выполняет операцию объединения для двух переданных множеств
	/// </summary>
	/// <param name="pointerSetA"> Указатель на множество A </param>
	/// <param name="pointerSetB"> Указатель на множество B </param>
	/// <returns> множество C, состоящее из элементов A и B </returns>
	set<string> merge(set<string>* pointerSetA, set<string>* pointerSetB)
	{
		set<string> setC;

		for (auto elementA : *pointerSetA)
			setC.insert(elementA);

		for (auto elementB : *pointerSetB)
			setC.insert(elementB);

		return setC;
	}

	/// <summary>
	/// Выполняет операцию пересечения двух переданных множеств
	/// </summary>
	/// <param name="pointerSetA"> Указатель на множество A </param>
	/// <param name="pointerSetB"> Указатель на множество B </param>
	/// <returns> множество C, состоящее из элементов, которые есть и в A, и в B </returns>
	set<string> intersection(set<string>* pointerSetA, set<string>* pointerSetB)
	{
		set<string> setC;

		for (auto elementA : *pointerSetA)
			if (sets::elementInSet(elementA, pointerSetB))
				setC.insert(elementA);

		return setC;
	}

	/// <summary>
	/// Выполняет операцию разности для множеств A и B
	/// </summary>
	/// <param name="pointerSetA"> указатель на множество A </param>
	/// <param name="pointerSetB"> указатель на множество B</param>
	/// <returns> множество C, состоящее из элементов A, которых нет в B</returns>
	set<string> difference(set<string>* pointerSetA, set<string>* pointerSetB)
	{
		set<string> setC;

		for (auto elementA : *pointerSetA)
			if (!sets::elementInSet(elementA, pointerSetB))
				setC.insert(elementA);

		return setC;
	}

	/// <summary>
	/// Выполняет операцию симметрической разности множеств A и B
	/// </summary>
	/// <param name="pointerSetA"> указатель на множество A </param>
	/// <param name="pointerSetB"> указатель на множество B </param>
	/// <returns> множество C, состоящее из элементов A, которых нет в B, и элементов B, которых нет в A </returns>
	set<string> symmetricalDifference(set<string>* pointerSetA, set<string>* pointerSetB)
	{
		//Получаем результаты разности множеств A / B и B / A
		set<string> c1 = sets::difference(pointerSetA, pointerSetB);
		set<string> c2 = sets::difference(pointerSetB, pointerSetA);

		//Создаём указатели на полученные множества
		set<string>* pointerC1 = &c1;
		set<string>* pointerC2 = &c2;

		//Объединяем полученные множества и возвращаем результат
		return sets::merge(pointerC1, pointerC2);
	}
}

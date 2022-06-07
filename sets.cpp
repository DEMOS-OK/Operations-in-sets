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
	/// ���������� ��������� ���������, ���������� �� �������� ������
	/// </summary>
	/// <param name="nameOfSet"> ��� ��������� (����� ���������� � �������) </param>
	/// <returns> ��������� �������� ��������� </returns>
	set<string> enterSet(const string nameOfSet)
	{
		string inputString;
		set<string> createdSet;
		set<string>* pointerSet = &createdSet;

		//���� ��������� � ������ ����� ������
		cout << "������� �������� ��������� " << nameOfSet << " ����� ������:" << endl;
		getline(cin, inputString);
		if (inputString == "\n" || inputString.empty()) {
			getline(cin, inputString);
		}

		//��������� ��������� ���������� �� �������� ������
		sets::fillSetFromString(pointerSet, inputString);

		return createdSet;
	}

	/// <summary>
	/// ������� ������ ���� "A = {a1,a2,a3,a4}"
	/// </summary>
	/// <param name="pointerSet"> ��������� �� ��������� </param>
	/// <param name="nameOfSet"> ��� ��������� </param>
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
	/// ��������� ���������� ��������� ���������� �� ���������� ������
	/// </summary>
	/// <param name="pointerSet"> ��������� �� ��������� </param>
	/// <param name="inputString"></param>
	void fillSetFromString(set<string>* pointerSet, string inputString)
	{
		size_t pos = 0;
		string delim = " "; //�����������
		while ((pos = inputString.find(delim)) != string::npos) { //������� ������� �������
			pointerSet->insert(inputString.substr(0, pos)); //��������� ��������� ������ �� �������
			inputString.erase(0, pos + delim.length()); //����������� ������
		}
		if (!inputString.empty())
			pointerSet->insert(inputString); //��������� ��������� ������� ������
	}

	/// <summary>
	/// ��������� 2 ��������� �� ���������
	/// </summary>
	/// <param name="pointerSetA"> ��������� �� ������ ��������� </param>
	/// <param name="pointerSetB"> ��������� �� ������ ��������� </param>
	/// <returns> true, ���� ��������� �����, ����� false</returns>
	bool checkEquality(set<string>* pointerSetA, set<string>* pointerSetB)
	{
		return (*pointerSetA) == (*pointerSetB);
	}

	/// <summary>
	///	���������, ��� ��������� A �������� ������������� ��������� B
	/// </summary>
	/// <param name="pointerSetA"> ��������� �� ��������� A </param>
	/// <param name="pointerSetB"> ��������� �� ��������� B </param>
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
	/// ���������, ���� �� ������� � ���������
	/// </summary>
	/// <param name="elementA"> �������, ������� ����� ����� </param>
	/// <param name="pointerSetB"> ��������� �� ���������, � ������� ����� ����� </param>
	/// <returns> bool </returns>
	bool elementInSet(const string elementA, set <string>* pointerSetB)
	{
		for (auto elementB : *pointerSetB)
			if (elementA == elementB)
				return true;

		return false;
	}


	/// <summary>
	/// ��������� �������� ����������� ��� ���� ���������� ��������
	/// </summary>
	/// <param name="pointerSetA"> ��������� �� ��������� A </param>
	/// <param name="pointerSetB"> ��������� �� ��������� B </param>
	/// <returns> ��������� C, ��������� �� ��������� A � B </returns>
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
	/// ��������� �������� ����������� ���� ���������� ��������
	/// </summary>
	/// <param name="pointerSetA"> ��������� �� ��������� A </param>
	/// <param name="pointerSetB"> ��������� �� ��������� B </param>
	/// <returns> ��������� C, ��������� �� ���������, ������� ���� � � A, � � B </returns>
	set<string> intersection(set<string>* pointerSetA, set<string>* pointerSetB)
	{
		set<string> setC;

		for (auto elementA : *pointerSetA)
			if (sets::elementInSet(elementA, pointerSetB))
				setC.insert(elementA);

		return setC;
	}

	/// <summary>
	/// ��������� �������� �������� ��� �������� A � B
	/// </summary>
	/// <param name="pointerSetA"> ��������� �� ��������� A </param>
	/// <param name="pointerSetB"> ��������� �� ��������� B</param>
	/// <returns> ��������� C, ��������� �� ��������� A, ������� ��� � B</returns>
	set<string> difference(set<string>* pointerSetA, set<string>* pointerSetB)
	{
		set<string> setC;

		for (auto elementA : *pointerSetA)
			if (!sets::elementInSet(elementA, pointerSetB))
				setC.insert(elementA);

		return setC;
	}

	/// <summary>
	/// ��������� �������� �������������� �������� �������� A � B
	/// </summary>
	/// <param name="pointerSetA"> ��������� �� ��������� A </param>
	/// <param name="pointerSetB"> ��������� �� ��������� B </param>
	/// <returns> ��������� C, ��������� �� ��������� A, ������� ��� � B, � ��������� B, ������� ��� � A </returns>
	set<string> symmetricalDifference(set<string>* pointerSetA, set<string>* pointerSetB)
	{
		//�������� ���������� �������� �������� A / B � B / A
		set<string> c1 = sets::difference(pointerSetA, pointerSetB);
		set<string> c2 = sets::difference(pointerSetB, pointerSetA);

		//������ ��������� �� ���������� ���������
		set<string>* pointerC1 = &c1;
		set<string>* pointerC2 = &c2;

		//���������� ���������� ��������� � ���������� ���������
		return sets::merge(pointerC1, pointerC2);
	}
}

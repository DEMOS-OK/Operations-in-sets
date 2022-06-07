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
	/// ��������� �������� ������ ����
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
				cout << "��������� ��������� ���� ������. " << endl;
				projectStatus = false;
				break;
			default:
				cout << "������� ���� ������ �������!" << endl;
				break;
		}

		return projectStatus;
	}

	/// <summary>
	/// ���������� ��������� �������� ����
	/// </summary>
	void showMenu()
	{
		cout << endl;
		printLine();
		cout << "����: " << endl;
		cout << "1. ��������� ��������" << endl;
		cout << "2. �������� �� ������������" << endl;
		cout << "3. ����������� ��������" << endl;
		cout << "4. ����������� ��������" << endl;
		cout << "5. �������� ��������" << endl;
		cout << "6. �������������� �������� ��������" << endl;
		cout << "7. �������� �����" << endl;
		cout << "8. ���������" << endl;
		printLine();
	}

	/// <summary>
	/// ������ ������� ����, � ����� ���������� ���
	/// </summary>
	/// <returns> int operation </returns>
	short int changeOperation()
	{
		short int operation;

		cout << "�������� �������� (������� ��������������� �����):" << endl;
		cin >> operation;

		return operation;
	}

	/// <summary>
	/// ��������� �������� �������� �� ���������
	/// </summary>
	void equality()
	{
		//������� ���������
		printOperationHeader("�������� �������� A � B �� ���������: ");

		//������ ��������� A, ������ ���������, ������� ��������� �� �����
		set<string> setA = sets::enterSet("A");
		set<string>* pointerSetA = &setA;
		cout << sets::prepareToPrint(pointerSetA, "A") << endl;

		//������ ��������� B, ������ ���������, ������� ��������� �� �����
		set<string> setB = sets::enterSet("B");
		set<string>* pointerSetB = &setB;
		cout << sets::prepareToPrint(pointerSetB, "B") << endl;

		//��������� ��������� � ������� ���
		if (sets::checkEquality(pointerSetA, pointerSetB))
			printResult("��������� �����");
		else
			printResult("��������� �� �����");
	}

	/// <summary>
	/// ��������� �������� �� �����������
	/// </summary>
	void subset()
	{
		//������� ���������
		printOperationHeader("��������, �������� �� ��������� � ������������� B: ");

		//������ ��������� A, ������ ���������, ������� ��������� �� �����
		set<string> setA = sets::enterSet("A");
		set<string>* pointerSetA = &setA;
		cout << sets::prepareToPrint(pointerSetA, "A") << endl;

		//������ ��������� B, ������ ���������, ������� ��������� �� �����
		set<string> setB = sets::enterSet("B");
		set<string>* pointerSetB = &setB;
		cout << sets::prepareToPrint(pointerSetB, "B") << endl;

		if (sets::checkSubset(pointerSetA, pointerSetB))
			printResult("� �������� ������������� B.");
		else
			printResult("� �� �������� ������������� B.");
	}

	/// <summary>
	/// ��������� �������� ����������� ��������
	/// </summary>
	void merge()
	{
		//������� ���������
		printOperationHeader("����������� �������� A � B: ");

		//������ ��������� A, ������ ���������, ������� ��������� �� �����
		set<string> setA = sets::enterSet("A");
		set<string>* pointerSetA = &setA;
		cout << sets::prepareToPrint(pointerSetA, "A") << endl;

		//������ ��������� B, ������ ���������, ������� ��������� �� �����
		set<string> setB = sets::enterSet("B");
		set<string>* pointerSetB = &setB;
		cout << sets::prepareToPrint(pointerSetB, "B") << endl;

		//���������� 2 ���������
		set<string> setC = sets::merge(pointerSetA, pointerSetB);
		set<string>* pointerSetC = &setC; //������ ��������� ��� �������� � ������� ������

		//������� ���������
		printResult(sets::prepareToPrint(pointerSetC, "C"));
	}

	/// <summary>
	/// ��������� �������� ����������� ��������
	/// </summary>
	void intersection()
	{
		//������� ���������
		printOperationHeader("����������� �������� A � B: ");

		//������ ��������� A, ������ ���������, ������� ��������� �� �����
		set<string> setA = sets::enterSet("A");
		set<string>* pointerSetA = &setA;
		cout << sets::prepareToPrint(pointerSetA, "A") << endl;

		//������ ��������� B, ������ ���������, ������� ��������� �� �����
		set<string> setB = sets::enterSet("B");
		set<string>* pointerSetB = &setB;
		cout << sets::prepareToPrint(pointerSetB, "B") << endl;

		//���������� 2 ���������
		set<string> setC = sets::intersection(pointerSetA, pointerSetB);
		set<string>* pointerSetC = &setC; //������ ��������� ��� �������� � ������� ������

		//������� ���������
		printResult(sets::prepareToPrint(pointerSetC, "C"));
	}

	/// <summary>
	/// ��������� �������� �������� ��������
	/// </summary>
	void difference()
	{
		//������� ���������
		printOperationHeader("�������� �������� A � B: ");

		//������ ��������� A, ������ ���������, ������� ��������� �� �����
		set<string> setA = sets::enterSet("A");
		set<string>* pointerSetA = &setA;
		cout << sets::prepareToPrint(pointerSetA, "A") << endl;

		//������ ��������� B, ������ ���������, ������� ��������� �� �����
		set<string> setB = sets::enterSet("B");
		set<string>* pointerSetB = &setB;
		cout << sets::prepareToPrint(pointerSetB, "B") << endl;

		//��������� �������� �������� ��������
		set<string> setC = sets::difference(pointerSetA, pointerSetB);
		set<string>* pointerSetC = &setC; //������ ��������� ��� �������� � ������� ������

		//������� ���������
		printResult(sets::prepareToPrint(pointerSetC, "C"));
	}

	/// <summary>
	/// ��������� �������� �������������� �������� ��������
	/// </summary>
	void symmetricalDifference()
	{
		//������� ���������
		printOperationHeader("�������������� �������� �������� A � B: ");

		//������ ��������� A, ������ ���������, ������� ��������� �� �����
		set<string> setA = sets::enterSet("A");
		set<string>* pointerSetA = &setA;
		cout << sets::prepareToPrint(pointerSetA, "A") << endl;

		//������ ��������� B, ������ ���������, ������� ��������� �� �����
		set<string> setB = sets::enterSet("B");
		set<string>* pointerSetB = &setB;
		cout << sets::prepareToPrint(pointerSetB, "B") << endl;

		//��������� �������� �������������� �������� ��������
		set<string> setC = sets::symmetricalDifference(pointerSetA, pointerSetB);
		set<string>* pointerSetC = &setC; //������ ��������� ��� �������� � ������� ������

		//������� ���������
		printResult(sets::prepareToPrint(pointerSetC, "C"));
	}

	/// <summary>
	/// ������� ����� ������� �� ����������� ������
	/// </summary>
	void clearScreen()
	{
		system("cls");
	}

	/// <summary>
	/// ��� ������� ������� ��������� �� ����� (������ ������ � ���. �����, ����� ��� ���������)
	/// </summary>
	/// <param name="text"> ����� ��������������� ��������� </param>
	void printResult(const string text)
	{
		cout << endl;
		printLine();
		cout << "���������: " << text << endl;
	}

	/// <summary>
	/// ������� ��������� �������� �� �����
	/// </summary>
	/// <param name="text"> ����� ��������� </param>
	void printOperationHeader(const string text)
	{
		printLine();
		cout << text << endl << endl;
	}

	/// <summary>
	/// ������� ����� �� ���� �� �����
	/// </summary>
	void printLine()
	{
		cout << "--------------------------------------------------" << endl;
	}
}
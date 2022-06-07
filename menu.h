#pragma once

#include <string>

namespace menu {
	bool work();
	void showMenu();
	short int changeOperation();
	void equality();
	void subset();
	void merge();
	void intersection();
	void difference();
	void symmetricalDifference();
	void printLine();
	void printResult(const std::string text);
	void printOperationHeader(const std::string text);
	void clearScreen();
}

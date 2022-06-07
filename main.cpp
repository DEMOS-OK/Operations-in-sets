#include <iostream>

#include "init.h"
#include "sets.h"
#include "menu.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	initConsoleSettings();

	int i = 0;
	bool projectStatus = true;

	while (projectStatus) {
		projectStatus = menu::work();
	}

	system("pause");
	return 0;
}

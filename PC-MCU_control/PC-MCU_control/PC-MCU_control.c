#include "Full.h"
//#include "Debug.h"
#include "Menu.h"
#include <string.h>

int main(int argc, char* argv[])
{
	if ((argc == 1) || !strcmp(argv[1], "Test"))
		Menu(Debug);
	else
		Menu(Reliase);

    return 0;
}


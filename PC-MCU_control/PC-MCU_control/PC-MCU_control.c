#include "Full.h"
#include "Debug.h"
#include <string.h>

int main(int argc, char* argv[])
{
	if ((argc == 1) || !strcmp(argv[1], "Test"))
		DebugMode();
	else
		FullMode();

    return 0;
}


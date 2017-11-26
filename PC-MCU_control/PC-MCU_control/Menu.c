#include "Menu.h"

#define BUFFER_LENGTH 200
#define FUNCTION_DESCRIPTION void (*function)(HANDLE MCU)

typedef struct
{
	const char* commandName;
	const char* commandDescription;
	FUNCTION_DESCRIPTION;
} command_t;

static void _showGreetings(command_t commands[], int comAmount)
{
	int i;

	printf("Welcome to PC->MCU module debug.\n To call needed debug mode enter on of this commands:\n");

	for (i = 0; i < comAmount; i++)
		printf("%s\n", commands[i].commandName);

	printf("\nBe careful, register is important\n");
}

static void _menuMain(void)
{
	char command[BUFFER_LENGTH];
	command_t commands[] = { { "Exit", "Finishes debugging", NULL },{ "L13", "", DebugL13},{ "Names", "", DebugNames} };
	int comAmount;
	int i;
	HANDLE MCU;

	comAmount = sizeof(commands) / sizeof(*commands);
	MCU = FOpenCOM();

	_showGreetings(commands, comAmount);

	while (1)
	{
		if (MCU == NULL)
		{
			printf("MCU wasn't found. Please, check the connection of MCU.\nEnter 'Done' to try connect again.\nEnter 'Exit' to stop debugging\n\n");
			while (1)
			{
				fgets(command, BUFFER_LENGTH, stdin);

				while (strstr(command, "\n") == NULL)
					fgets(command, BUFFER_LENGTH, stdin);

				if (strstr(command, "Exit") != NULL)
				{
					return;
				}

				if (strstr(command, "Done") != NULL)
				{
					MCU = FOpenCOM();
					break;
				}
			}
		}
		else
		{
			fgets(command, BUFFER_LENGTH, stdin);

			while (strstr(command, "\n") == NULL)
				fgets(command, BUFFER_LENGTH, stdin);

			for (i = 0; i < comAmount; i++)
				if (strstr(command, commands[i].commandName) != NULL)
					if (commands[i].function != NULL)
					{
						commands[i].function(MCU);
						_showGreetings(commands, comAmount);
					}
					else
						return;
		}
	}
}

void Menu(MENU_ARGUMENT)
{
	switch (mode)
	{
	case(Debug):
	{
		_menuMain();
		break;
	}
	default:
		break;
	}
}
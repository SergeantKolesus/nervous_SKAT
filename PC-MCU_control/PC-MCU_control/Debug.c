#include "Debug.h"

/*typedef enum
{
	Included,
	DirectNum,
	TwoValue,
	TextConnected
} control_mode_t;*/

#define FILE_NAME "Nerves.cfg"

void DebugNames(HANDLE MCU)
{
	char name[200];
	char names[100][200];
	FILE* namesBase;
	int i;
	int namesAmount;
	unsigned char byte;
	DWORD sendedBytes;

	namesBase = fopen(FILE_NAME, "r");

	if (namesBase == NULL)
	{
		printf("Configuration file doesn't found\n\n");
		return;
	}

	for (i = 0; i < 100; i++)
		names[i][0] = '\0';

	for (i = 0; ; i++)
	{
		fgets(names[i], 200, namesBase);
		if (names[i][0] == '\0')
			break;
		if(strstr(names[i], "\n") != NULL)
			*strstr(names[i], "\n") = '\0';
	}

	namesAmount = i;


	while (1)
	{
		printf("Enter name of nerve or 'Exit' to stop\n");

		fgets(name, 200, stdin);

		while (strstr(name, "\n") == NULL)
			fgets(name, 200, stdin);

		if (strstr(name, "\n") != NULL)
			*strstr(name, "\n") = '\0';

		if (strstr(name, "Exit") != NULL)
		{
			printf("Names debug finished\n\n");
			return;
		}

		for(i = 0; i < namesAmount; i++)
			if (strstr(names[i], name) != NULL)
			{
				byte = i;
				break;
			}

		printf("Enter command to control nerve\nCommands are:\non\noff\nchange\n");

		fgets(name, 200, stdin);

		while (strstr(name, "\n") == NULL)
			fgets(name, 200, stdin);

		if (strstr(name, "on") != NULL)
			byte = byte | 64;

		if (strstr(name, "off") != NULL)
			byte = byte | 128;

		if (strstr(name, "change") != NULL)
			byte = byte | 192;

		if (byte == i)
			printf("Unknown command\n");
		else
		{
			WriteFile(MCU, &byte, 1, &sendedBytes, NULL);
			if (sendedBytes == 0)
				printf("ERROR: bytes weren't sent\n");
			else
				printf("You sent byte %X\n", byte);
		}

	}

}

void DebugL13(HANDLE MCU)
{
	char command[15];
	DWORD sendedBytes;
	unsigned char controlByte;

	printf("To control L13 lamp use this command:\non\noff\nchange\nexit\nIf entered command won't be recognized, will be sent previous command\n\nBe careful, register is important\n\n");

	do
	{
		fgets(command, 15, stdin);

		while (strstr(command, "\n") == NULL)
			fgets(command, 15, stdin);

		if (strstr(command, "on") != NULL)
			controlByte = 77;

		if (strstr(command, "off") != NULL)
			controlByte = 141;

		if (strstr(command, "change") != NULL)
			controlByte = 205;

		if (strstr(command, "exit") != NULL)
			break;

		WriteFile(MCU, &controlByte, 1, &sendedBytes, NULL);
		if(sendedBytes == 0)
			printf("ERROR: bytes weren't sent\n");
		else
			printf("You sent byte %X\n", controlByte);
	} while (1);

	printf("L13 debug finished\n\n");
}

/*static control_mode_t _setMode(void) 
{
	char command[15];

	printf("I'm a lazy ass, so please enter 'included', and after it enter 'on', 'off' or 'change'. To stop enter 'exit'\n");

	fgets(command, 15, stdin);

	while (strstr(command, "\n") == NULL)
		fgets(command, 15, stdin);

	if(strstr(command, "included") != NULL)
		return Included;

	if (strstr(command, "direct") != NULL)
		return DirectNum;

	if (strstr(command, "two") != NULL)
		return TwoValue;

	if (strstr(command, "text") != NULL)
		return TextConnected;
}*/

/*void DebugMode(void)
{
	//LPCWSTR MCUPort;
	HANDLE MCU;
	control_mode_t mode;

	MCU = FOpenCOM();

	mode = _setMode();

	switch (mode)
	{
	case(Included):
	{
		_debugL13(MCU);
		break;
	}
	default:
		break;
	}

	CloseHandle(MCU);
}*/
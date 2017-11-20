#include "Debug.h"

typedef enum
{
	Included,
	DirectNum,
	TwoValue,
	TextConnected
} control_mode_t;

static void _debugL13(HANDLE MCU)
{
	char command[15];
	DWORD sendedBytes;
	unsigned char controlByte;

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

		WriteFile(MCU, &controlByte, 1, &sendedBytes, NULL);
		if(sendedBytes == 0)
			printf("ERROR: bytes weren't sent\n");
		else
			printf("You sent byte %X\n", controlByte);
	} while (strstr(command, "exit") == NULL);
}

static control_mode_t _setMode(void)
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
}

void DebugMode(void)
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
}
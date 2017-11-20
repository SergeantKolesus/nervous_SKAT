#include "COM.h"

LPCWSTR FindCOM(void)
{
	int size;
	int i;
	LPCWSTR COMPorts[] = { L"//./COM1", L"//./COM2" , L"//./COM3" , L"//./COM4" , L"//./COM5" , L"//./COM6" , L"//./COM7" , L"//./COM8" , L"//./COM9" , L"//./COM10" };
	HANDLE mcu;

	size = sizeof(COMPorts) / sizeof(*COMPorts);

	for (i = 0; i < size; i++)
	{
		mcu = CreateFile(COMPorts[i], GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (mcu != INVALID_HANDLE_VALUE)
		{
			CloseHandle(mcu);
			return COMPorts[i];
		}
	}

	return NULL;
}

HANDLE FOpenCOM(void)
{
	int size;
	int i;
	LPCWSTR COMPorts[] = { L"//./COM1", L"//./COM2" , L"//./COM3" , L"//./COM4" , L"//./COM5" , L"//./COM6" , L"//./COM7" , L"//./COM8" , L"//./COM9" , L"//./COM10" };
	HANDLE mcu;

	size = sizeof(COMPorts) / sizeof(*COMPorts);

	for (i = 0; i < size; i++)
	{
		mcu = CreateFile(COMPorts[i], GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (mcu != INVALID_HANDLE_VALUE)
			return mcu;
	}

	return NULL;
}
﻿void Decode(int inputData, int* outputPort, char* outputComand)
{
	*outputPort = inputData << 2 >> 2;

	inputData = inputData >> 6;

	switch (inputData)
	{
	case 1:
		{
			*outputComand = 'A';
			break;
		}
	case 2:
		{
			*outputComand = 'D';
			break;
		}
	case 3:
		{
			*outputComand = 'C';
			break;
		}
	default:
		break;
	}
}
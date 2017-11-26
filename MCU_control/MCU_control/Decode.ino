static unsigned char inputData;

void CollectData(void)
{
	unsigned char port;
	unsigned char command;

	if(Serial.available() != 0)
	{
		inputData = Serial.read();
		Serial.print("I received: ");
        Serial.println(inputData, DEC);
		Decode(inputData, &port, &command);
		switch (command)
		{
		case 'A':
			digitalWrite(port, HIGH);
			break;
		case 'D':
			digitalWrite(port, LOW);
			break;
		case 'C':
			digitalWrite(port, !digitalRead(port));
			//DEBUGGERB
			digitalWrite(PD2, !digitalRead(port));
			digitalWrite(PD1, digitalRead(port));
			//DEBUGGERE
			break;
		default:
			break;
		}
	}
}

void Decode(int inputData, unsigned char* outputPort, unsigned char* outputComand)
{
	*outputPort = inputData & 63;

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
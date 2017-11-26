void setup() 
{
	pinMode(13, OUTPUT);
	pinMode(PD1, OUTPUT);
	pinMode(PD2, OUTPUT);
	delay(3000);
	digitalWrite(PD2, HIGH);
	digitalWrite(PD1, LOW);
}

void loop() 
{
	CollectData();
}

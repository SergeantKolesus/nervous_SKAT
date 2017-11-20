void setup() 
{
	pinMode(13, OUTPUT);
	pinMode(PD3, OUTPUT);
	pinMode(PD1, OUTPUT);
	delay(3000);
	digitalWrite(PD1, HIGH);
	digitalWrite(PD3, LOW);
}

void loop() 
{
	CollectData();
}

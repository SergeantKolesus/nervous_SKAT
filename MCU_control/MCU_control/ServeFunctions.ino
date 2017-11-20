static void _shortBlink(int pin)
{
	digitalWrite(pin, HIGH);   
	delay(1000);              
	digitalWrite(pin, LOW);    
}

static void _longBlink(int pin)
{
	digitalWrite(pin, HIGH);   
	delay(2000);              
	digitalWrite(pin, LOW);    
}

void Standbuy(void)
{
	_shortBlink(13);
	delay(800);
	_shortBlink(13);
	delay(800);
	_shortBlink(13);
	delay(1600);
	_longBlink(13);
	delay(800);
	_shortBlink(13);
	delay(800);
	_longBlink(13);
	delay(2500);
}
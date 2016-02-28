const int delayValue = 25;

int led1 = 2;
int led2 = 4;
int led3 = 7;
int led4 = 8;

void LedsMagic(int);

void setup() {
  Serial.begin(9600);

	pinMode(led1,OUTPUT);
	pinMode(led2,OUTPUT);
	pinMode(led3,OUTPUT);
	pinMode(led4,OUTPUT);
}

void loop() {
	//keep the delay's methods as they are
  delay(delayValue);
  int sensorvalue = analogRead(A0);
  Serial.println(sensorvalue);
  delay(delayValue); 

	////LedsMagic(sensorvalue);
}

void LedsMagic(int value) {
	
	int tmpdelay = 0;

	if (value > 0 && value <= 250) 
		tmpdelay = 1000;
	else if (value >= 250 && value <= 500)
		tmpdelay = 500;
	else if (value >= 500 && value <= 750)
		tmpdelay = 250;
	else
		tmpdelay = 100;

		digitalWrite(led1,HIGH);
		digitalWrite(led2,LOW);
		digitalWrite(led3,LOW);
		digitalWrite(led4,LOW);
		delay(tmpdelay);
		digitalWrite(led1,LOW);
		digitalWrite(led2,HIGH);
		digitalWrite(led3,LOW);
		digitalWrite(led4,LOW);
		delay(tmpdelay);
		digitalWrite(led1,LOW);
		digitalWrite(led2,LOW);
		digitalWrite(led3,HIGH);
		digitalWrite(led4,LOW);
		delay(tmpdelay);
		digitalWrite(led1,LOW);
		digitalWrite(led2,LOW);
		digitalWrite(led3,LOW);
		digitalWrite(led4,HIGH);
		delay(tmpdelay);




	
}


















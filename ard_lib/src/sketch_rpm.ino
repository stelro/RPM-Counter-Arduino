int led1 = 2;
int led2 = 4;
int led3 = 7;
int led4 = 8;

int counter = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
	 counter++;
		delay(20);
	 if ( counter == 10000) {
		 Serial.println(counter);
		 counter = 0;
	 }

	 delay(20);

}

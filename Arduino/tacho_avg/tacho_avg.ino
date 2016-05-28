#define NUM_VALUES 10

unsigned int passes = 0;
unsigned long first = 0;
unsigned long last = 0;
int counter = -2; //this is -2 because in order to save value in AverageArray[0] when we access *if* in void loop()passes is *passes==2*, so counter must be *counter==0*
float RPM=0;

float AverageArray[NUM_VALUES]; //array with 10 values that are used to return a RPM with the average value of 10 measurements
for(int i=0;i < NUM_VALUES;i++)
{
  AverageArray[i]=0; //make each element equals to zero
}

void blade_Pass(){
  passes++;
  counter++;
  if (passes == 1){
    first = micros();
  }
  else if (passes > 1){
    last = micros();
  }
}

void setup()
{
  attachInterrupt(0,blade_Pass,FALLING);
  Serial.begin(9600);
}


void loop()
{
  if (passes > 1){
    float passesPerSecond = (float)passes / ((float)last - (float)first) * 1000.0 * 1000.0;
    AverageArray[counter] = passesPerSecond * 60.0;// / numBlades;

    if(counter == 10)
    {
      for(counter = 0; counter < NUM_VALUES; counter++)
      {
        RPM = RPM + AverageArray[counter];
      }
      Serial.print(" RPM: "); //the values will be printed every 1 sec because the printing happens every 10 rounds and the delay is 0.1s. 10* 0.1 = 1sec
      Serial.println(RPM/NUM_VALUES); //In order to print the average of the array we must divide the sum of the AverageArray that we measure at for with the NUM_VALUES
      counter = 0; //we make the *counter=0;* in order to save the next 10 values of the tachometer
    }
    
//    Serial.print("Passes: ");
//    Serial.print(passes);
//    Serial.print(" Time: ");
//    Serial.print(last-first);
//    Serial.print(" PPS: ");
//    Serial.print(passesPerSecond);
    passes = 0;
    delay(100);
  }
  
  attachInterrupt(0,blade_Pass,FALLING);
}

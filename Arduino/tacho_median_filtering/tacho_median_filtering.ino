const int NUM_VALUES=10; //numReadings

unsigned int passes = 0;
unsigned long first = 0;
unsigned long last = 0;
unsigned long Timer = 0;

int counter = 0;  //readIndex                this is -2 because in order to save value in AverageArray[0] when we access *if* in void loop()passes is *passes==2*, so counter must be *counter==0*
int RPM=0;

int AverageArray[NUM_VALUES]; //array with 10 values that are used to return a RPM with the average value of 10 measurements


void blade_Pass(){
  passes++;
  
  //Serial.print("Pass : ");
  //Serial.println(passes);
  if (passes == 1){
    first = micros();
  }
  else if (passes > 1){
    last = micros();
  }
}

void bubbleSort()
{
  if(counter >= 10)  //bubble sort
    {
        for(int i=0; i<NUM_VALUES-1; i++)
        {
          for(int j=0; j<(NUM_VALUES-(i+1)); j++) 
          {
            if(AverageArray[j] > AverageArray[j+1])
            {
              int t = AverageArray[j];
              AverageArray[j] = AverageArray[j+1];
              AverageArray[j+1] = t;
            }
          }
        }
        Serial.println(AverageArray[4]);
        counter = 0;
    }
}

void setup()
{
  attachInterrupt(0,blade_Pass,FALLING);
  Serial.begin(9600);
  for(int i=0;i < NUM_VALUES; i++)
  {
    AverageArray[i]=0; //make each element equals to zero
  }
}


void loop()
{
  if (passes > 1)
  {  //2 rounds per dt
    float passesPerSecond = (float)passes / ((float)last - (float)first) * 1000.0 * 1000.0;
    AverageArray[counter] = passesPerSecond * 30.0;// 60.0/2
    counter++;
    bubbleSort();
    passes = 0;
  }

  
  attachInterrupt(0,blade_Pass,FALLING);
}

const int NUM_VALUES=10; //numReadings

unsigned int passes = 0;
unsigned long first = 0;
unsigned long last = 0;
unsigned long Timer = 0;

int counter = 0;  //readIndex 

int AverageArray[NUM_VALUES]; //array with 10 values that are used to return a RPM with the average value of 10 measurements
//int min=0;


void blade_Pass(){
  passes++;
  if (passes == 1){
    first = micros();
  }
  else if (passes > 1){
    last = micros();
  }
}

void quickSort(int arr[], int left, int right);

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
    
    if(counter >=10)  //bubble sort
    {   
      quickSort( AverageArray,AverageArray[0],AverageArray[NUM_VALUES-1] );
//        if(millis() - Timer >= 10)
//        {
//          Timer = millis();
          //Serial.print("RPM: ");
          Serial.println(AverageArray[4]);    
        //}    
       counter = 0;  
     }//if counter
     passes = 0;
  }
  attachInterrupt(0,blade_Pass,FALLING);
}

void quickSort(int arr[], int left, int right)
{
     
     int i = left, j = right;
     int tmp;
     int pivot = arr[(left + right) / 2];

     /* partition */
     while (i <= j) {
           while (arr[i] < pivot)
                 i++;
           while (arr[j] > pivot)
                 j--;
           if (i <= j) {
                 tmp = arr[i];
                 arr[i] = arr[j];
                 arr[j] = tmp;
                 i++;
                 j--;
           }
     };
     /* recursion */
     if (left < j)
           quickSort(arr, left, j);
     if (i < right)
           quickSort(arr, i, right);
     
}

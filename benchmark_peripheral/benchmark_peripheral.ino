//define LED_BUILTIN 13 // for Arduino Uno

void setup() 
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  delay(3000);

  Serial.println("***************************************************");
  Serial.println("*              Arduino Benchmark                  *");
  Serial.println("***************************************************");
  Serial.println("");
}

void benchmark_digitalWrite(uint32_t count)
{
  uint32_t n;
  for(n=0;n<count/8;n++)
  {
    // unroled loop to minimize for loop influence
    digitalWrite(LED_BUILTIN,HIGH);
    digitalWrite(LED_BUILTIN,LOW);
    digitalWrite(LED_BUILTIN,HIGH);
    digitalWrite(LED_BUILTIN,LOW);
    digitalWrite(LED_BUILTIN,HIGH);
    digitalWrite(LED_BUILTIN,LOW);
    digitalWrite(LED_BUILTIN,HIGH);
    digitalWrite(LED_BUILTIN,LOW);

  }
}

void benchmark_analogRead(uint32_t count)
{
  uint32_t n;
  for(n=0;n<count;n++)
  {
    analogRead(0);
  }
}

void loop() 
{
  uint16_t n;

  uint32_t startTime;
  uint32_t stopTime;
  uint32_t numberOfTries=100000;
  uint32_t timeNeeded;
  
  Serial.println("digitalWrite speed benchmark");
  Serial.println("=============================");
    
  startTime=micros();
  benchmark_digitalWrite(numberOfTries);
  stopTime=micros();
  timeNeeded = stopTime-startTime;
  
  Serial.print("number of tries: ");Serial.print(numberOfTries);Serial.print("  ");
  Serial.print("duration [us]: "); Serial.print(timeNeeded);Serial.print("  ==> ");
  Serial.print("speed [megaSamples/second] : "); Serial.println((float)numberOfTries / timeNeeded); Serial.print("  "); 
  Serial.println("");   
  
  Serial.println("analogRead speed benchmark");
  Serial.println("=============================");
    
  startTime=micros();
  benchmark_analogRead(numberOfTries);
  stopTime=micros();
  timeNeeded = stopTime-startTime;
  
  Serial.print("number of tries: ");Serial.print(numberOfTries);Serial.print("  ");
  Serial.print("duration [us]: "); Serial.print(timeNeeded);Serial.print("  ==> ");
  Serial.print("speed [kiloSamples/second] : "); Serial.println((float)numberOfTries / timeNeeded * 1000); Serial.print("  ");
  Serial.println("");
  
  delay(5000);
  Serial.println("");
  Serial.println("");
  Serial.println("");
}

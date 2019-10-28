// static char theTCCR1A = 0b10000010; //varible for TCCR1A

bool instructions[] = 
{
  {1, 0, 0, 0, 1, 1, 0, 0, 0},
  {1, 0, 0, 0, 1, 0, 1, 0, 0},
  {0, 1, 0, 0, 0, 1, 1, 0, 0},
  {0, 1, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 1, 0, 1, 0, 1},
  {0, 0, 1, 0, 0, 1, 1, 0, 1}
}

int inApin[2] = {7, 4};  // INA: Clockwise input
int inBpin[2] = {8, 9}; // INB: Counter-clockwise input
int enApin[2] = {x, x}; // EN: Status of switches output (Analog pin)
int enBpin[2] = {x, x}; // EN: Status of switches output (Analog pin)
int pwmpin[2] = {5, 6}; // PWM input
int cspin[2] = {2, 3}; // CS: Current sense ANALOG input

int duty_cycle = 1023 // Value between 0 and 1023
int frequency = 50 //Oscilation frequency

void setup()
{
  for (int i=0; i<2; i++)
  {
    pinMode(inApin[i], OUTPUT);
    pinMode(inBpin[i], OUTPUT);
    pinMode(pwmpin[i], OUTPUT);
    pinMode(enApin[i], OUTPUT);
    pinMode(enBpin[i], OUTPUT);
  }
  
  for (int i=0; i<2; i++)
  {
    digitalWrite(inApin[i], LOW);
    digitalWrite(inBpin[i], LOW);
  }  
}

void loop() 
{
  for (int i=0; i<6; i++) 
  {
    int microsince = micros()
    digitalWrite(inApin[0], instructions[i][0]);
    digitalWrite(inBpin[0], instructions[i][1]);
    digitalWrite(inApin[1], instructions[i][2]);
    digitalWrite(inBpin[1], instructions[i][3]);
    digitalWrite(enApin[0], instructions[i][4]);
    digitalWrite(enBpin[0], instructions[i][5]);
    digitalWrite(enApin[1], instructions[i][6]);
    digitalWrite(enBpin[1], instructions[i][7]);
    
    while(microsince - micros() <= (1/frequency)*1000000/2) 
    {
      sinus_curve_point = round(duty_cycle * sin(2 * 3.14159 * frequency * (microsince - micros()) / 1000000))
      analogWrite(pwmpin[instructions[i][8]], sinus_curve_point);
    }
  }
}

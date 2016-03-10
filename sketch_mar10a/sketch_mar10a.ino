#define ledPin 13
/*
 * Each of the timers has a counter that is incremented on each tick of the timer's clock.
 * CTC timer interrupts are triggered when the counter reaches a specified value stored in the compare match register. 
*/

/*
 * timer1 is 16 bit, which means it can store a maximum counter value of 65535.
 * periods = prescaler*(1+31250)/16M=0.5s. when using, calculate OCR1A instead
*/
void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  // initialize timer1 
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 62500;            // compare match register 31250=16MHz/256/2Hz
  TCCR1B |= (1 << WGM12);   // CTC mode ( Clear Timer on Compare Match)
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  interrupts();             // enable all interrupts
}

ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
  static float v_set,v,acc,s,s_fore,s_set;
  v_set=30;
  s_set=6000;
  acc=2;


  if((s+s_fore)<s_set){
     
     
     if (v<v_set){
          v=1*acc+v;
          s=1*v+s;
      }
     else{
          v=v_set;
          s=1*v+s;
          s_fore=pow(v,2)/2/acc;
      }
    

  }
  else if (v>=0) { 
    v=v-1*acc;
    s=1*v+s;
  }
 
  Serial.println(v);
   
  
  digitalWrite(ledPin, digitalRead(ledPin) ^ 1);   // toggle LED pin


  
  int x=x+0.1;
  //Serial.println(x);
}

void loop()
{
  // your program here...
}



#define ledPin 13
#define stepPin 8
#define dirPin 9 
#define MICROSTEP 8
#define REVOLUTION 200

double delta_t=(double)256/16000000;

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
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  digitalWrite(dirPin, 1);
  
  Serial.begin(9600);
  // initialize timer1 
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;


/*
 * FOR Microstepping is Full step
 * this stepper is 1'8 per step. then a rotation hass 360/1.8=200 step per revolution  
 * f_pulse=N*f_step=N*f_revolution*200=200N*rpm/60
 * OCR=16m/f_timer/prescaler=16m/f_pulse/2/prescaler=1.2M/N/rpm/prescaler
 */
  
  //OCR1A = 1200000/MICROSTEP/(rpm+1)/256;            // compare match register 31250=16MHz/256/2Hz  // 640,000 = 1 rms   400= 1 step

  OCR1A=0;   

  
  TCCR1B |= (1 << WGM12);   // CTC mode ( Clear Timer on Compare Match)
  TCCR1B |= (1 << CS12);    // 256 prescaler, thus every "tick" takes  256/16M s 
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  interrupts();             // enable all interrupts
}

ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
 
  static double v_set,v,acc,s,s_fore,s_set;
  v_set=20;  //rotation speed rps
  s_set=100;
  acc=200; //rotation per square second
  static double block;

  digitalWrite(stepPin, 0);
  if((s+s_fore)<s_set)
  {

         if (v<v_set)
         {
              v=delta_t*acc+v;
              s=delta_t*v+s;
              block+=v*delta_t;
          }
         else
         {
              v=v_set;
              s=delta_t*v+s;
              s_fore=pow(v,2)/2/acc;
              block+=v*delta_t;
          }
  }
   
else if(v>0)
{
  v=v-delta_t*acc;
  s=delta_t*v+s;
  block+=v*delta_t;
}
else if(v<=0)
{
  v=0;
  s_fore=0;
   s=0;
  delay(2000);      
 }
    

if (block>1.0/MICROSTEP/REVOLUTION)  // reality meaning ,when 1 step made, output this step
{
  block-=1.0/MICROSTEP/REVOLUTION;
  digitalWrite(stepPin, 1);

}
     
 }
 

void loop()
{
  // your program here...
}



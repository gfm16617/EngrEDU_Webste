#define BUTTON_1  2
#define BUTTON_2  3
#define GREEN_LED 4
#define RED_LED   5
#define BUZZER    6

#define DATA      9
#define LATCH     8
#define CLOCK     7

#define DIGIT_4   10
#define DIGIT_3   11
#define DIGIT_2   12
#define DIGIT_1   13 

unsigned char table[]=
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c
,0x39,0x5e,0x79,0x71,0x00};

void setup() {
  // LEDs Pins
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // Button Pins
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);

  // Buzer Pins
  pinMode(BUZZER, OUTPUT);

  // 7-Seg Display
  pinMode(DIGIT_1, OUTPUT);
  pinMode(DIGIT_2, OUTPUT);
  pinMode(DIGIT_3, OUTPUT);
  pinMode(DIGIT_4, OUTPUT);

  // Shift Register Pins
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);

  disp_on();
}

void Display(unsigned char num)
{

  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, table[num]);
  digitalWrite(LATCH, HIGH);
}

void Display_Numbers()
{
  unsigned char sleep_time = 100;
  
  Display(0);
  delay(sleep_time);
  Display(1);
  delay(sleep_time);
  Display(2);
  delay(sleep_time);
  Display(3);
  delay(sleep_time);
  Display(4);
  delay(sleep_time);
  Display(5);
  delay(sleep_time);
  Display(6);
  delay(sleep_time);
  Display(7);
  delay(sleep_time);
  Display(8);
  delay(sleep_time);
  Display(9);
  delay(sleep_time);
  Display(10);
  delay(sleep_time);
  Display(11);
  delay(sleep_time);
  Display(12);
  delay(sleep_time);
  Display(13);
  delay(sleep_time);
  Display(14);
  delay(sleep_time);
  Display(15);
  delay(sleep_time);
  Display(16);
  delay(sleep_time);
}

void disp_on()
{
   digitalWrite(DIGIT_1, LOW);
   digitalWrite(DIGIT_2, LOW);
   digitalWrite(DIGIT_3, LOW);
   digitalWrite(DIGIT_4, LOW);
}

void BlinkLEDs()
{
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  delay(500);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(500);
}

void Active_Buzzer()
{
  unsigned char i;
  unsigned char sleep_time = 1; // ms
  
  for(i=0;i<100;i++)
   {
    digitalWrite(BUZZER,HIGH);
    delay(sleep_time);//wait for 1ms
    digitalWrite(BUZZER,LOW);
    delay(sleep_time);//wait for 1ms
    }
}

void Buttons()
{
  unsigned int buttonState = 0;         // variable for reading the pushbutton status
  
  buttonState = digitalRead(BUTTON_1);
  digitalWrite(RED_LED, buttonState);

  buttonState = digitalRead(BUTTON_2);
  digitalWrite(GREEN_LED, buttonState);
}

void loop() {
  BlinkLEDs();
  //Display_Numbers();
  //Active_Buzzer();
  //Buttons();
}

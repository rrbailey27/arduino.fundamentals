const int buttonPin = 2;     // the number of the pushbutton pin
int press = 0;  // the number of time the button is pressed

void setup() 
{
  pinMode(buttonPin, INPUT);     // initialize the pushbutton pin as an input:
  Serial.begin(9600);  // more on this later in the lab
}

void loop()
{
  if (CheckButton()==true) //calls the CheckButton function
  {     
    Serial.println(press); // this prints the value of "press";  more on Seriallater
    press++; //this is a shorthand way of writing Press=press+1 - increments the counter by 1
  } 
  
}

bool CheckButton(void)
{
  bool retVal = false;
  static int prevReading = 0; // 0 means "LOW" 1 neans "HIGH" for digitalRead in Arduino

  bool currReading = digitalRead(buttonPin);

  if(you write this statement!)
  {
    delay(200); 
    /* dleay is added to help handle button "debouncing"
    the button mounted on a breadboard is not a very precise
    swtich... so thie helps average out 
    some of those issues
    */
    retVal = true;
  }

  prevReading = currReading;
  return retVal;
}

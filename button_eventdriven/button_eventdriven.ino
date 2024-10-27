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
    press++; //this is a shorthand way of writing Press=press+1 - increments the counter by 1
    Serial.println(press); // this prints the count more on Serial later

  } 

// you can comment out the above if loop and uncomment the following one
// to see what happens if you just count up without event-driven programming

/*
  if (digitalRead(buttonPin) == 0)
  {
    press++; //this is a shorthand way of writing Press=press+1 - increments the counter by 1
    Serial.println(press); // this prints the count more on Serial later

  }
  */
  
}


bool CheckButton(void)
{
  bool retVal = false;
  static int prevReading = 1; // 0 means "LOW" or 0V,  1 neans "HIGH" or 5V for digitalRead in Arduino
  // with a pull-up resistor, 1 means 'not pressed" and 0 means the button is "pressed"

  bool currReading = digitalRead(buttonPin);

  if(you write this statement!)
  {
    delay(200); 
    /* delay is added to help handle button "debouncing"
    the button mounted on a breadboard is not a very precise
    switch... so this helps average out 
    some of those issues
    */
    retVal = true; // this sets the value that the function will return to "true" - because the button has been pressed!
  }

  prevReading = currReading;  // sets the vale of "prevReading" to the current reading value for the next pass through this loop

  return retVal; // returns the value of retVal
}

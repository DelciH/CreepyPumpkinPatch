#include <Servo.h>


class Pumpkin
{
  Servo servo;              // the servo
  int pos;              // current servo position 
  int increment;        // increment to move for each interval
  int  updateInterval;      // interval between updates
  unsigned long lastUpdate; // last update of position
  int pumpkinpos;
public: 
  Pumpkin(int interval)
  {
    updateInterval = interval;
    increment = 1;
  }
  void Position(int newpos)
  {
    pumpkinpos = newpos;
  }
  void Attach(int pin)
  {
    servo.attach(pin);
  }
  
  void Detach()
  {
    servo.detach();
  }
  
  void Update()
  {
    Serial.print("Last update: ");
    Serial.print (lastUpdate);
    Serial.print("      Update Interval: ");
    Serial.print(updateInterval);
    Serial.print("      Pumpkin Pos: ");
    Serial.print(pumpkinpos);
    Serial.print("      Current Position: ");
    Serial.println(pos);

    //check to see which direction we should turn
    
    
    if((millis() - lastUpdate) > updateInterval)  // time to update
    {
      
      lastUpdate = millis();
      
      if (pos != pumpkinpos)
      {
        //not there yet
        servo.write(pos);
        if (pos < pumpkinpos)
        {
          increment = 1;
        } else {
          increment = -1;
        }
        pos += increment;
      }
      
      
      

      
      
    }
  }
};
 



Pumpkin pumpkin1(50);
Pumpkin pumpkin2(50);
Pumpkin pumpkin3(50);
Pumpkin pumpkin4(50);
Pumpkin pumpkin5(50);
Pumpkin pumpkin6(50);
Pumpkin pumpkin7(50);
Pumpkin pumpkin8(50);
unsigned long timeOfLastButtonEvent = 0;

int buttonState[4];             // the current reading from the input pin
int lastButtonState[4];   // the previous reading from the input pin

// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
int lastDebounceTime[4] ;  // the last time the output pin was toggled
int debounceDelay = 50; 






 
unsigned long tmplastUpdate;
int laststate;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pumpkin1.Attach(9);
  pumpkin2.Attach(10);
  pumpkin3.Attach(11);
  pumpkin4.Attach(12);
  pumpkin5.Attach(13);
  pumpkin6.Attach(14);
  pumpkin7.Attach(15);
  pumpkin8.Attach(16);
  
  
  
  pumpkin1.Position(90);
  pumpkin2.Position(90);
  pumpkin3.Position(90);
  pumpkin4.Position(90);
  pumpkin5.Position(90);
  pumpkin6.Position(90);
  pumpkin7.Position(90);
  pumpkin8.Position(90);

  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  
}

void loop() {
     
     
     UpdatePumpkins();
     unsigned long currentTime = millis();
     
     
     for (int i=0;i<4;i++)
     {
      
      //   ##### start debounce
        int reading = digitalRead(i+2);
        
          // If the switch changed, due to noise or pressing:
          if (reading != lastButtonState[i]) {
            // reset the debouncing timer
            lastDebounceTime[i] = millis();
          }
        
          if ((millis() - lastDebounceTime[i]) > debounceDelay) {
            // whatever the reading is at, it's been there for longer
            // than the debounce delay, so take it as the actual current state:
            Serial.println(buttonState[i]);
            // if the button state has changed:
            if (reading != buttonState[i]) {
              buttonState[i] = reading;
              
              
              if ((buttonState[0]==0) && (i==0) )
                   {
                      //first switch is triggered
                      //left side
                      pumpkin1.Position(90);
                      pumpkin2.Position(68);
                      pumpkin3.Position(45);
                      pumpkin4.Position(22);
                      //right side  
                      pumpkin5.Position(90);
                      pumpkin6.Position(112);
                      pumpkin7.Position(135);
                      pumpkin8.Position(158);
                      timeOfLastButtonEvent = currentTime;
                   }
              if ((buttonState[1]==0) && (i==1))
                   {
                      //2nd switch is triggered
                      //left side
                      pumpkin1.Position(112);
                      pumpkin2.Position(90);
                      pumpkin3.Position(68);
                      pumpkin4.Position(45);
                      //right side  
                      pumpkin5.Position(68);
                      pumpkin6.Position(90);
                      pumpkin7.Position(112);
                      pumpkin8.Position(135);
                      timeOfLastButtonEvent = currentTime;
                   }
              if ((buttonState[2]==0) && (i==2))
                   {
                      //3rd switch is triggered
                      //left side
                      pumpkin1.Position(135);
                      pumpkin2.Position(112);
                      pumpkin3.Position(90);
                      pumpkin4.Position(68);
                      //right side  
                      pumpkin5.Position(45);
                      pumpkin6.Position(68);
                      pumpkin7.Position(90);
                      pumpkin8.Position(112);
                      timeOfLastButtonEvent = currentTime;
                   }
              if ((buttonState[3]==0) && (i==3))
                   {
                      //4th switch is triggered
                      //left side
                      pumpkin1.Position(147);
                      pumpkin2.Position(135);
                      pumpkin3.Position(112);
                      pumpkin4.Position(90);
                      //right side  
                      pumpkin5.Position(22);
                      pumpkin6.Position(45);
                      pumpkin7.Position(68);
                      pumpkin8.Position(90);
                      timeOfLastButtonEvent = currentTime;
                   }
            }
          }
        
        
          // save the reading.  Next time through the loop,
          // it'll be the lastButtonState:
          lastButtonState[i] = reading;
     //   ##### end debounce
      
      
      
      
      
      
      
     }
    
    


     //reset if no button pressed in X amount of time
     if (currentTime - timeOfLastButtonEvent > 5000)
      {
        pumpkin1.Position(90);
        pumpkin2.Position(90);
        pumpkin3.Position(90);
        pumpkin4.Position(90);
        pumpkin5.Position(90);
        pumpkin6.Position(90);
        pumpkin7.Position(90);
        pumpkin8.Position(90);
      }
     
  /*   
     if (digitalRead(2) == 1)
      {
        if (digitalRead(2) != laststate)
        {
          pumpkin1.Position(90);
          pumpkin2.Position(90);
          pumpkin3.Position(90);
          pumpkin4.Position(90);
          pumpkin5.Position(90);
          pumpkin6.Position(90);
          pumpkin7.Position(90);
          pumpkin8.Position(90);
        }
        laststate=1;
      } else {
        if (digitalRead(2) != laststate)
        {
          pumpkin1.Position(0);
          pumpkin2.Position(0);
          pumpkin3.Position(0);
          pumpkin4.Position(0);
          pumpkin5.Position(0);
          pumpkin6.Position(0);
          pumpkin7.Position(0);
          pumpkin8.Position(0);
        }
        laststate=0;
      }
      */
  /*
  servo_2.Update();
  servo_3.Update();
  servo_4.Update();
  servo_5.Update();
  servo_6.Update();
  servo_7.Update();
  servo_8.Update();
  */

 
  
/*
 * 

 if {switchone active)
{  
  //switch 1 activr, we need to turn the pumpkins
  set1 needs to turn to x
  set2 needs to turn to x + 15
  set2 needs to turn to x + 30
  set2 needs to turn to x + 45
}
if {switchtwo active}
{
  //switch 1 activr, we need to turn the pumpkins
  set1 needs to turn to x - 15
  set2 needs to turn to x 
  set2 needs to turn to x + 15
  set2 needs to turn to x + 30
}

if {switch 3 active}
{
  //switch 1 activr, we need to turn the pumpkins
  set1 needs to turn to x - 30
  set2 needs to turn to x - 15
  set2 needs to turn to x 
  set2 needs to turn to x + 15
}

if { switch 4 active }
{
  //switch 1 activr, we need to turn the pumpkins
  set1 needs to turn to x - 45
  set2 needs to turn to x - 30
  set2 needs to turn to x - 15
  set2 needs to turn to x 
  
}
*/
}



void UpdatePumpkins()
{
  pumpkin1.Update();
  pumpkin2.Update();
  pumpkin3.Update();
  pumpkin4.Update();
  pumpkin5.Update();
  pumpkin6.Update();
  pumpkin7.Update();
  pumpkin8.Update();
  
}



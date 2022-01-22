#include <Servo.h>                       
Servo handServo;
Servo boxServo;

int statusswitch = 0, action = 1;


void setup()
{
  Serial.begin(9600);
  handServo.attach(5);
  boxServo.attach(6);
  handServo.write(180);   
  boxServo.write(70);    
}


void loop()
{
  statusswitch = digitalRead(2);


  if (statusswitch == LOW) {

    if (action == 1)
    {
      for (int i = 70; i <= 115; i++)
      {
        boxServo.write(i);
        delay(13);
      }
      for (int i = 180; i >= 30; i--)
      {
        handServo.write(i);
        delay(20);
      }
      delay(1000);
      handServo.write(16);
      delay(200);
      for (int i = 16; i <= 180; i++)
      {
        handServo.write(i);
        delay(20);
      }
      for (int i = 110; i >= 70; i--)
      {
        boxServo.write(i);
        delay(20);
      }
      action++;
    }


    else if (action == 2)
    {
      for (int i = 70; i <= 115; i++) {
        boxServo.write(i);
        delay(6);
      }
      delay(550);
      handServo.write(26);
      delay(550);
      handServo.write(180);
      delay(550);
      boxServo.write(70);
      delay(1500);
      for (int i = 70; i <= 115; i++) {
        boxServo.write(i);
        delay(6);
      }
      delay(3000);
      boxServo.write(70);
      action++;
    }



    else if (action == 3)
    {
      Serial.println("Action 3");
      for (int i = 70; i <= 115; i++) {
        boxServo.write(i);
        delay(6);
      }
      delay(1000);
      boxServo.write(70);
      delay(2000);
      for (int i = 70; i <= 115; i++) {
        boxServo.write(i);
        delay(6);
      }
      handServo.write(26);
      delay(550);
      handServo.write(180);
      delay(500);
      boxServo.write(70);
      action++;
    }



    else if (action == 4)
    {
      Serial.println("Action 4");
      for (int i = 70; i <= 115; i++)
      {
        boxServo.write(i);
        delay(20);
      }
      for (int i = 180; i >= 35; i--)
      {
        handServo.write(i);
        delay(20);
      }
      delay(2000);
      handServo.write(26);
      delay(200);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      action++;
    }


    else if (action == 5)
    {
      Serial.println("Action 5");
      for (int i = 70; i <= 110; i++) {
        boxServo.write(i);
        delay(6);
      }
      delay(1000);
      for (int i = 0; i < 3; i++)
      {
        for (int j = 70; j <= 110; j++) {
          boxServo.write(j);
          delay(50);
        }
        for (int j = 110; j >= 70; j--)
        {
          boxServo.write(j);
          delay(50);
        }
      }
      for (int j = 70; j <= 115; j++) {
        boxServo.write(j);
        delay(50);
      }
      for (int i = 180; i >= 35; i--)
      {
        handServo.write(i);
        delay(40);
      }
      delay(100);
      handServo.write(26);
      delay(400);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      action = 1;
    }

  }

}

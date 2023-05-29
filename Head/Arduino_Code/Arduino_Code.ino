
#include <Servo.h>
Servo servoVer; //Vertical Servo
Servo servoHor; //Horizontal Servo
int x;
int y;
int prevX;
int prevY;
void setup()
{
  Serial.begin(9600);
  servoVer.attach(9); //Attach Vertical Servo to Pin 5
  servoHor.attach(10); //Attach Horizontal Servo to Pin 6
  servoVer.write(0);
  servoHor.write(90);
}
void Pos()
{
  if(prevX != x || prevY != y)
  {
    int servoX = map(x, 300, 0, 30, 179);
    int servoY = map(y, 450, 0, 179, 75);
    servoX = min(servoX, 150);
    servoX = max(servoX, 30);
    servoY = min(servoY, 179);
    servoY = max(servoY, 65);
    
    servoHor.write(servoX);
    servoVer.write(servoY);
  }
}
void loop()
{
  if(Serial.available() > 0)
  {
    if(Serial.read() == 'X')
    {
      x = Serial.parseInt();
      if(Serial.read() == 'Y')
      {
        y = Serial.parseInt();
       Pos();
      }
    }
    while(Serial.available() > 0)
    {
      Serial.read();
    }
  }
}

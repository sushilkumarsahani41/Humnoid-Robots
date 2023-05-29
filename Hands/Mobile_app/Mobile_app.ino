#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3LEsbJJ_q"
#define BLYNK_TEMPLATE_NAME "Hands"
#define BLYNK_AUTH_TOKEN "5mcCEV65El8GOVZHnCVxxQ52Uto-Cw9b"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include<ESP32Servo.h>
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Devloper";
char pass[] = "12345678";

Servo first;
Servo Index;
Servo middle;
Servo ring;
Servo pinky;

void setup()
{
  // Debug console
  Serial.begin(115200);
  first.attach(13);
  Index.attach(12);
  middle.attach(14);
  ring.attach(27);
  pinky.attach(26);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

BLYNK_WRITE(V0)
 {
 if(param.asInt()==1)
  {
    first.write(90);
  }
  else
  {
    first.write(0);
  }
}


BLYNK_WRITE(V1)
 {
 if(param.asInt()==1)
  {
    Index.write(90);
  }
  else
  {
    Index.write(0);
  }
}


BLYNK_WRITE(V2)
 {
 if(param.asInt()==1)
  {
    middle.write(90);
  }
  else
  {
    middle.write(0);
  }
}


BLYNK_WRITE(V3)
 {
 if(param.asInt()==1)
  {
    ring.write(90);
  }
  else
  {
    ring.write(0);
  }
}


BLYNK_WRITE(V4)
 {
 if(param.asInt()==1)
  {
    pinky.write(90);
  }
  else
  {
    pinky.write(0);
  }
}


BLYNK_WRITE(V5)
 {
 if(param.asInt()==1)
  {
    first.write(90);
    Index.write(90);
    middle.write(90);
    ring.write(90);
    pinky.write(90);
  }
  else
  {
    first.write(0);
    Index.write(0);
    middle.write(0);
    ring.write(0);
    pinky.write(0);
  }
}


void loop()
{

  Blynk.run();
}



/**************************************************************
 * Read analogic data with OAK. In the example I'll use a LDR
 *
 * App project setup:
 *   Display or graph widget attached to Virtual Pin V1
 *
 **************************************************************/

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "";

// Pin on the OAK where LDR output is connected to
int LDR_Pin = A0;

void setup()
{

  Blynk.config(auth);

  while (Blynk.connect() == false) {
    // Wait until connected
  }

}

BLYNK_READ(V1) // Widget in the app READs Virtal Pin V1 with the certain frequency
{
  // This command writes analog read to Virtual Pin V1
  Blynk.virtualWrite(1, analogRead(LDR_Pin));
}

void loop()
{
  Blynk.run();
}


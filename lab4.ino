#include "SevSeg.h"
SevSeg sevseg;
byte Hour = 0;
byte Min = 0;
void setup() {
byte numDigits = 4;
byte digitPins[] = {2, 3, 4, 5};
byte segmentPins[] = {8, 9, 10, 11, 12, 13, 14, 15};
//bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
byte hardwareConfig = COMMON_CATHODE; // See README.md for options
//bool updateWithDelays = false; // Default. Recommended
//bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
pinMode(6,INPUT);
sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins /*resistorsOnSegments*//*, updateWithDelays/*,*//* leadingZeros*/);
sevseg.setBrightness(90);

}

void loop() {
static unsigned long timer = millis();

boolean Pin6= digitalRead (6); // Reset
if (Pin6 == HIGH)
Min = Hour = 0;

if (millis() - timer >= 100) {
timer += 100;
sevseg.setNumber(Hour * 100 + Min, 0);
Min = Min + 1;
if (Min ==60 )
{
Min = 0;
if (Hour == 23)
Hour=0;
else
Hour++;
}

}
sevseg.refreshDisplay(); // Must run repeatedly

}

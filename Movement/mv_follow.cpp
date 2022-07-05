/*
Date: 06.22.2022
Students:
Name of the project: Bluetooth-controlled Car
independent following of an object
*/


int distance;
static int followDistance = 10;
static int sendSignal = 7;
static int getSignal = 6;
...
//setup
pinMode(sendSignal, OUTPUT);
pinMode(getSignal, INPUT);
//loop
...

//def
void Follow() {
  	digitalWrite(sendSignal, LOW);
	delay(5);
	digitalWrite(sendSignal, HIGH);
	delay(5);
	digitalWrite(sendSignal, LOW);
	delay = pulseIN(getSignal, HIGH);
	distance = (delay / 2) * 0.03432;

  	if (distance > followDistance) {
    		moveForward();
  	}
}

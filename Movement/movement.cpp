const int IN_A0 = A0;                                 //legt den analogen Pin für den IR-Sensor fest  
const int IN_D0 = 11;                                 //legt den digitalen Pin für den IR-Sensor fest

const int lGes = 10;                                  //legt den PWM-Pin für die Geschwindigkeit der Motoren fest
const int lM1 = 9;                                    //legt die Pins für die Ansteuerung des Motors fest
const int lM2 = 8;                                    //legt die Pins für die Ansteuerung des Motors fest

const int rGes = 5;                                   //legt den PWM-Pin für die Geschwindigkeit der Motoren fest
const int rM1 = 7;                                    //legt die Pins für die Ansteuerung des Motors fest
const int rM2 = 6;                                    //legt die Pins für die Ansteuerung des Motors fest

bool value_D0;                                        //führt die Variable ein, in welocher gespeichert wird, ob eine Fahrbahnmarkierung erkannt wurde


void setup() {
  pinMode(lGes, OUTPUT);                              //an dem oben definierten Pin wird etwas augegeben
  pinMode(rGes, OUTPUT);                              //an dem oben definierten Pin wird etwas augegeben
  pinMode(lM1, OUTPUT);                               //an dem oben definierten Pin wird etwas augegeben
  pinMode(lM2, OUTPUT);                               //an dem oben definierten Pin wird etwas augegeben
  pinMode(rM1, OUTPUT);                               //an dem oben definierten Pin wird etwas augegeben
  pinMode(rM2, OUTPUT);                               //an dem oben definierten Pin wird etwas augegeben
  
  pinMode(IN_A0, INPUT);                              //an dem oben definierten Pin wird eine Eingabe angenommen
  pinMode(IN_D0, INPUT);                              //an dem oben definierten Pin wird eine Eingabe angenommen

  Serial.begin(9600);                                 //das Serial-Communication-Protocol wird gestartet
}


void loop () {
  IrValue();                                          //der IR-Sensor wird ausgelesen
  if (value_D0 == true) {                             //falls der IR-Value-Wert zutrifft, dh. weißer Untergrund...
    moveForeward();                                   //...fährt der wagen geradeaus
  }
  else if (value_D0 == false) {                       //falls er jedoch nicht zutrifft, dh den Fahrbahnrand erkennt...
    moveLeft();                                       //biegt er nach links ab
  }
}

void moveForeward () {                                //void für die Vorwärtsbewegung
  digitalWrite (lM1, HIGH);
  digitalWrite (lM2, LOW);
  analogWrite (lGes, 200);
  digitalWrite (rM1, HIGH);
  digitalWrite (rM2, LOW);
  analogWrite (rGes, 200);
}

void moveBackwards () {                                //void für die Rückwertsbewegung
  digitalWrite (lM1, LOW);
  digitalWrite (lM2, HIGH);
  analogWrite (lGes, 200);
  digitalWrite (rM1, LOW);
  digitalWrite (rM2, HIGH);
  analogWrite (rGes, 200);
}

void moveRight() {                                     //void für die Rechtsbewegung
  digitalWrite (lM1, HIGH);
  digitalWrite (lM2, LOW);
  analogWrite (lGes, 200);
  digitalWrite (rM1, LOW);
  digitalWrite (rM2, HIGH);
  analogWrite (rGes, 200);
}

void moveLeft () {                                    //void für die Linksbewegung
  digitalWrite (lM1, LOW);
  digitalWrite (lM2, HIGH);
  analogWrite (lGes, 200);
  digitalWrite (rM1, HIGH);
  digitalWrite (rM2, LOW);
  analogWrite (rGes, 200);
}

void IrValue() {
  value_D0 = digitalRead(IN_D0);                      //der IR-Sensor wird ausgelesen
}

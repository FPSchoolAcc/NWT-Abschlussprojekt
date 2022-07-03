const int IN_A0 = A0;
const int IN_D0 = 11;

const int lGes = 10;
const int lM1 = 9;
const int lM2 = 8;

const int rGes = 5;
const int rM1 = 7;
const int rM2 = 6;

bool value_D0;


void setup() {
  pinMode(lGes, OUTPUT);
  pinMode(rGes, OUTPUT);
  pinMode(lM1, OUTPUT);
  pinMode(lM2, OUTPUT);
  pinMode(rM1, OUTPUT);
  pinMode(rM2, OUTPUT);
  pinMode(IN_A0, INPUT);
  pinMode(IN_D0, INPUT);

  Serial.begin(9600);
}


void loop () {
  IrValue();
  if (value_D0 == true) {
    moveForeward();
  }
  else if (value_D0 == false) {
    moveLeft();
  }
}

void moveForeward () {
  digitalWrite (lM1, HIGH);
  digitalWrite (lM2, LOW);
  analogWrite (lGes, 200);
  digitalWrite (rM1, HIGH);
  digitalWrite (rM2, LOW);
  analogWrite (rGes, 200);
}

void moveBackwads () {
  digitalWrite (lM1, LOW);
  digitalWrite (lM2, HIGH);
  analogWrite (lGes, 200);
  digitalWrite (rM1, LOW);
  digitalWrite (rM2, HIGH);
  analogWrite (rGes, 200);
}

void moveRight() {
  digitalWrite (lM1, HIGH);
  digitalWrite (lM2, LOW);
  analogWrite (lGes, 200);
  digitalWrite (rM1, LOW);
  digitalWrite (rM2, HIGH);
  analogWrite (rGes, 200);
}

void moveLeft () {
  digitalWrite (lM1, LOW);
  digitalWrite (lM2, HIGH);
  analogWrite (lGes, 200);
  digitalWrite (rM1, HIGH);
  digitalWrite (rM2, LOW);
  analogWrite (rGes, 200);
}

void IrValue() {
  value_D0 = digitalRead(IN_D0);
}
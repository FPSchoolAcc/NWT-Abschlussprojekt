int lGes = 10;
int lM1 = 9;
int lM2 = 8;

int rGes = 5;
int rM1 = 7;
int rM2 = 6;

void setup(){
  pinMode(lGES, OUTPUT);    
  pinMode(rGes, OUTPUT);
  pinMode(lM1, OUTPUT);
  pinMode(lM2, OUTPUT);
  pinMode(rM1, OUTPUT);
  pinMode(rM2, OUTPUT);
}


void loop (){

}

void moveForward (){
    digitalWrite (lM1, HIGH);
    digitalWrite (lM2, LOW);
    analogWrite (lGes, 200);
    digitalWrite (rM1, HIGH);
    digitalWrite (rM2, LOW);
    analogWrite (rGes, 200);
}

void movebackwads (){
    digitalWrite (lM1, LOW);
    digitalWrite (lM2, HIGH);
    analogWrite (lGes, 200);
    digitalWrite (rM1, LOW);
    digitalWrite (rM2, HIGH);
    analogWrite (rGes, 200);
}

void moveLeft() {
    digitalWrite (lM1, HIGH);
    digitalWrite (lM2, LOW);
    analogWrite (lGes, 200);
    digitalWrite (rM1, LOW);
    digitalWrite (rM2, HIGH);
    analogWrite (rGes, 200); 
}

void moveRight () {
    digitalWrite (lM1, LOW);
    digitalWrite (lM2, HIGH);
    analogWrite (lGes, 200);
    digitalWrite (rM1, HIGH;
    digitalWrite (rM2, LOW);
    analogWrite (rGes, 200);
}

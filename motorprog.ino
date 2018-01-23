int motorPinA = 3;
int motorPinB = 11;

int speed = 0;

void setup() {
  Serial.begin(9600);
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Direction Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  pinMode(3, OUTPUT); //Initiates PWM Channel A pin
  digitalWrite(3, HIGH);
  digitalWrite(9, LOW);

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Direction Channel B pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel B pin
  pinMode(11, OUTPUT); //Initiates PWM Channel B pin
  digitalWrite(8, LOW);
  digitalWrite(11, HIGH);
  while (!Serial);
  Serial.println("Enter Speed (40 to 150) : ");
}

void loop() {

  if (Serial.available())
  {
    int speed = Serial.parseInt();

    if (speed >= 40 && speed <= 150)
    {
      analogWrite(motorPinA, speed);
      analogWrite(motorPinB, speed);
      delay(60000);
    }
    else
    {
      Serial.println("Wrong input try Again : ");
    }
  }
}





int motorPinA = 3;
int motorPinB = 11;

int speed = 0;

void setup() {
  Serial.begin(9600);
  //Setup Channel A
  //pinMode(12, OUTPUT); //Initiates Direction Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  pinMode(3, OUTPUT); //Initiates PWM Channel A pin
  digitalWrite(3, HIGH);
  digitalWrite(9, LOW);

  //Setup Channel B
  //pinMode(13, OUTPUT); //Initiates Direction Channel B pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel B pin
  pinMode(11, OUTPUT); //Initiates PWM Channel B pin
  digitalWrite(11, HIGH);
  digitalWrite(8, LOW);
  Serial.println("Enter Speed (40 to 150) : ");
  speed = Serial.parseInt();
}

void loop() {
  if (Serial.available())
  {
    int speed = Serial.parseInt();
    if (speed >= 40 && speed <= 150)f
    {
      analogWrite(motorPinA, speed);
      analogWrite(motorPinB, speed);
      delay(60000);
    }
    else
    {
      Serial.println("Wrong input try Again : ");
    }
  }
}

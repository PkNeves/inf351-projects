// Link projeto: https://www.tinkercad.com/things/61INOquJCPC-sinal-de-transito-com-millis-inf-351/editel?sharecode=55GGh4_gTXeSKtbzUXC8MCQ1jOaVLpfPGv1oVy23m9s

/// C++ code
//

#define l1red 12
#define l1yellow 11
#define l1green 10

#define l2red 9
#define l2yellow 8
#define l2green 7

#define Switch 6

unsigned long myTime;
bool state;

void setup()
{
  myTime = millis();
  state = false;
  pinMode(Switch, INPUT_PULLUP);
  
  pinMode(l1red, OUTPUT);
  pinMode(l1yellow, OUTPUT);
  pinMode(l1green, OUTPUT);
  pinMode(l2red, OUTPUT);
  pinMode(l2yellow, OUTPUT);
  pinMode(l2green, OUTPUT);
}

void loop()
{
  if ( digitalRead(Switch) == LOW ) {
    state = true;
  } else {
    state = false;
  }
  
  if (state) {
    if ( millis() - myTime < 3000) {
      // close for 1
      digitalWrite(l1red, HIGH);
      digitalWrite(l1yellow, LOW);

      // open for 2
      digitalWrite(l2green, HIGH);
      digitalWrite(l2red, LOW);
    } else if ( millis() - myTime < 5000) {
      	// changing 2
    	digitalWrite(l2green, LOW);
    	digitalWrite(l2yellow, HIGH);
    } else if ( millis() - myTime < 7000) {
      	// open for 1
    	digitalWrite(l1red, LOW);
    	digitalWrite(l1green, HIGH);
    
      	// close for 2
    	digitalWrite(l2yellow, LOW);
    	digitalWrite(l2red, HIGH);
    } else if ( millis() - myTime < 10000) {
      	// changing 1
     	digitalWrite(l1green, LOW);
    	digitalWrite(l1yellow, HIGH);
    } else {
    	myTime = millis();
    }
  } else {
  	digitalWrite(l1red, LOW);
    digitalWrite(l1green, LOW);
    digitalWrite(l1yellow, LOW);
    digitalWrite(l2red, LOW);
    digitalWrite(l2green, LOW);
    digitalWrite(l2yellow, LOW);
  }
}
int trig = 4;
int echo = 5;
#define S 6
#define R 9
#define B 10
#define G 11

float distancia;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(S, INPUT_PULLUP);

  // led
  pinMode(R, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(G, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(S) == LOW)
  {
    digitalWrite(R, LOW);
    digitalWrite(B, LOW);
    digitalWrite(G, LOW);
  }
  else
  {

    digitalWrite(trig, LOW);
    delay(0005);
    digitalWrite(trig, HIGH);
    delay(0010);
    digitalWrite(trig, LOW);

    distancia = pulseIn(echo, HIGH);
    distancia = distancia / 58;
    Serial.println(distancia);

    int distancia2 = (int)distancia;

    if (distancia > 60)
    {
      analogWrite(R, 0);
      analogWrite(G, 0);
      analogWrite(B, 0);
    }
    else if (distancia > 100)
    {
      analogWrite(R, 90);
      analogWrite(G, 60);
      analogWrite(B, 30);
    }
    else if (distancia > 80)
    {
      analogWrite(R, 60);
      analogWrite(G, 60);
      analogWrite(B, 60);
    }
    else if (distancia > 70)
    {
      analogWrite(R, 30);
      analogWrite(G, 60);
      analogWrite(B, 90);
    }
    else if (distancia > 60)
    {
      analogWrite(R, 100);
      analogWrite(G, 100);
      analogWrite(B, 30);
    }
    else if (distancia > 40)
    {
      analogWrite(R, 255);
      analogWrite(G, 10);
      analogWrite(B, 150);
    }
    else
    {
      analogWrite(R, 255);
      analogWrite(G, 255);
      analogWrite(B, 255);
    }
  }
}

int trig = 3;
int echo = 5;

#define S 4
#define G1 6
#define G2 7
#define Y1 10
#define Y2 11
#define R1 12
#define R2 13

float distancia;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(S, INPUT_PULLUP);

  // led
  pinMode(G1, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(Y1, OUTPUT);
  pinMode(Y2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);

  // speaker
  pinMode(9, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(S) == LOW)
  {
    noTone(8);

    digitalWrite(G1, LOW);
    digitalWrite(G2, LOW);
    digitalWrite(Y1, LOW);
    digitalWrite(Y2, LOW);
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
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

    if (distancia > 120)
    {
      noTone(8);

      digitalWrite(G1, LOW);
      digitalWrite(G2, LOW);
      digitalWrite(Y1, LOW);
      digitalWrite(Y2, LOW);
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
    }
    else if (distancia > 100)
    {

      digitalWrite(G1, HIGH);
      digitalWrite(G2, LOW);
      digitalWrite(Y1, LOW);
      digitalWrite(Y2, LOW);
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
    }
    else if (distancia > 80)
    {

      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(Y1, LOW);
      digitalWrite(Y2, LOW);
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
    }
    else if (distancia > 70)
    {
      tone(9, 800, 200);

      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(Y1, HIGH);
      digitalWrite(Y2, LOW);
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
    }
    else if (distancia > 60)
    {
      tone(9, 900, 200);

      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(Y1, HIGH);
      digitalWrite(Y2, HIGH);
      digitalWrite(R1, LOW);
      digitalWrite(R2, LOW);
    }
    else if (distancia > 40)
    {
      tone(9, 1000, 200);

      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(Y1, HIGH);
      digitalWrite(Y2, HIGH);
      digitalWrite(R1, HIGH);
      digitalWrite(R2, LOW);
    }
    else
    {
      tone(9, 1100, 200);

      digitalWrite(G1, HIGH);
      digitalWrite(G2, HIGH);
      digitalWrite(Y1, HIGH);
      digitalWrite(Y2, HIGH);
      digitalWrite(R1, HIGH);
      digitalWrite(R2, HIGH);
    }
  }
}

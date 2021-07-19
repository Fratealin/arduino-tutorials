int ledPin[] = {2,3,4,5};

void setup()
{
  for (int i =0;i<4;i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop()
{
  for (int counter =0;counter<=15; counter++)
  {
    displayBinary(counter+1);
    delay(500);
  }
}

void displayBinary(int numToShow)
{
  numToShow=numToShow-8;
  if ((numToShow)>=1)
    {
      digitalWrite(ledPin[3], HIGH);
    }
    else
    {
      digitalWrite(ledPin[3], LOW);
    }
    
    numToShow=numToShow-4;
    if ((numToShow)>=1)
    {
      digitalWrite(ledPin[2], HIGH);
    }
    else
    {
      digitalWrite(ledPin[2], LOW);
    }

     numToShow=numToShow-2;
    if ((numToShow)>=1)
    {
      digitalWrite(ledPin[1], HIGH);
    }
    else
    {
      digitalWrite(ledPin[1], LOW);
    }

    numToShow=numToShow-1;
    if ((numToShow)>=1)
    {
      digitalWrite(ledPin[0], HIGH);
    }
    else
    {
      digitalWrite(ledPin[0], LOW);
    }

    
  

}

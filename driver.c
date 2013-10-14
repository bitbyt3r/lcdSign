#include <stdio.h>
#include <wiringPi.h>

//Sign geometry
#define ROWS 15
#define COLS 112

//Pin selection
#define ROW0 0
#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4
#define CLOCK 5
#define DATA 6

//GPIO Settings
#define LOW 0
#define HIGH 1

void readFile(char buffer[]);
void setRow(int row);
void drawRow(char buffer[], int start, int length);

char buffer[ROWS*COLS];
main()
{
  setupPins();
  while (1==1)
  {
    readFile(buffer);
    int r;
    int i;
    for (i=0; i < ROWS; i++)
    {
      setRow(i);
      drawRow(buffer, (i)*COLS, COLS);
    }
  }
}

void readFile(char buffer[])
{
  FILE *fp;
  fp = fopen("/run/signdata", "rb");
  fread(buffer, ROWS*COLS, 1, fp);
  fclose(fp);
}

void setPin(int pin, int state)
{
  digitalWrite(pin, state);
}

void setupPins()
{
  pinMode(ROW0, OUTPUT);
  pinMode(ROW1, OUTPUT);
  pinMode(ROW2, OUTPUT);
  pinMode(ROW3, OUTPUT);
  pinMode(ROW4, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
}

void setRow(int row)
{
  setPin(ROW0, row%2);
  setPin(ROW1, row%4);
  setPin(ROW2, row%8);
  if (row < 8)
  {
    setPin(ROW3, LOW);
    setPin(ROW4, HIGH);
  }
  else
  {
    setPin(ROW3, HIGH);
    setPin(ROW4, LOW);
  }
}

void drawRow(char buffer[], int start, int length)
{
  int i;
  for (i=0; i<length; i++)
  {
    setPin(CLOCK, LOW);
    if (buffer[start+i] == 0)
    {
      setPin(DATA, HIGH);
    }
    else
    {
      setPin(DATA, LOW);
    }
    setPin(CLOCK, HIGH);
  }
}



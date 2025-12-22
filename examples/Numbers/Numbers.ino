#include "SevenSeg.h"

/*
  Seven Segment display

  Display all numbers from 0-9 using a seven segment display

  An array of integers is passed to the constructor.
  This ordered array maps to the pins for each segment.
  Thus arr[0] = segA, arr[1] = segB, ..., arr[6] = segG, arr[7] = D.P pin

  If D.P is not necessary, an array of seven integers may be safely passed instead
  The size of array is passed as second arg to constructor

*/

int pins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

// SevenSeg::SevenSeg(segPinsArr, arrSize);
SevenSeg seg(pins, 8);

void setup() {
  // Initialize pins
  seg.begin();
}

void loop() {
  for (int i = 0; i < 10; i++) {
    seg.writeDigit(i);
    delay(500)
  }

  //Clear display
  seg.clearDisplay();

  // Display decimal point
  seg.writeDP();
  delay(1000);
}

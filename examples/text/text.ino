#include "SevenSeg.h"

/*
   Seven Segment display

   Write certain ASCII chars
   Supported characters include: A,b,C,d,E,F,H,h,I,J,L,n,O,P,r,S,t,U,y,.,Z,-,'
   A space char is mimicked as a blank display
   A fullstop char requires the D.P segment.

   An array of integers is passed to the constructor.
   This ordered array maps to the pins for each segment.
   Thus arr[0] = segA, arr[1] = segB, ..., arr[6] = segG, arr[7] = D.P pin

   If D.P is not necessary, an array of seven integers may be safely passed instead
   The size of array is passed as second arg to constructor

 */

int pins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

// SevenSeg::SevenSeg(segPinsArr, arrSize);
SevenSeg seg(pins, 8);
char *sentence = "no plan.";

void setup() {
  // Initialize pins
  seg.begin();
}

void loop() {
  for (int i = 0; sentence[i]; i++) {
    seg.writeChar(sentence[i]);
    delay(500);
  }
  seg.clearDisplay();
  delay(1000);
}

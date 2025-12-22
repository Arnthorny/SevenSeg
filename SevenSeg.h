#ifndef SEVENSEG_H
#define SEVENSEG_H
#include "Arduino.h"

class SevenSeg {
    private:
        int *segArr;
        int segArrSize;
    public:
        SevenSeg(int[], int);
        void begin();
        void clearDisplay();
        void writeDigit(int);
        void writeDP();
        void writeChar(char);
};
#endif

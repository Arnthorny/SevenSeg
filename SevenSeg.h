#ifndef SEVENSEG_H
#define SEVENSEG_H
#include "Arduino.h"

#define COMMON_CATHODE 0x1
#define COMMON_ANODE  0x0

class SevenSeg {
    private:
        int *segArr;
        int segArrSize;
        uint8_t _type;
        void __digitalWrite(uint8_t pin, uint8_t val);
    public:
        SevenSeg(int arr[], int arrSize, uint8_t type);
        void begin();
        void clearDisplay();
        void writeDigit(int digit);
        void writeDP();
        void writeChar(char c);
        void displayMask(byte mask);
};
#endif

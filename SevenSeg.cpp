#include "Sevenseg.h"

SevenSeg::SevenSeg(int segments[], int size, uint8_t type) {
    segArr = segments;
    segArrSize = size;
    _type = type;
}

void SevenSeg::begin() {
    for(int i = 0; i < segArrSize; i++) pinMode(segArr[i], OUTPUT);
    clearDisplay();
}

void SevenSeg::__digitalWrite(uint8_t pin, uint8_t val) {
    if (_type == COMMON_CATHODE) {
        digitalWrite(pin, val);
    }
    // Invert logic for common anode
    else {
        digitalWrite(pin, !val);
    }
}

void SevenSeg::displayMask(byte mask) {
    for (int i = 0; i < 7; i++) {
        __digitalWrite(segArr[i], (mask >> i) & 0x01);
    }
}

// Bit patterns for 0-9 (LSB = segment a, Bit 6 = segment g)
void SevenSeg::writeDigit(int num) {
    const byte digits[] = {
        0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F
    };
    
    if (num >= 0 && num <= 9) displayMask(digits[num]);
    else __digitalWrite(segArr[6], HIGH); // Error dash
}

void SevenSeg::writeChar(char c) {
    byte mask = 0;
    switch (toupper(c)) {
        case 'A': mask = 0x77; break;
        case 'B': mask = 0x7C; break;
        case 'C': mask = 0x39; break;
        case 'D': mask = 0x5E; break;
        case 'E': mask = 0x79; break;
        case 'F': mask = 0x71; break;
        case 'G': mask = 0x6F; break;
        case 'H': mask = 0x76; break;
        case 'I': mask = 0x30; break;
        case 'J': mask = 0x0E; break;
        case 'L': mask = 0x38; break;
        case 'N': mask = 0x37; break;
        case 'O': mask = 0x3F; break;
        case 'P': mask = 0x73; break;
        case 'R': mask = 0x31; break;
        case 'S': mask = 0x6D; break;
        case 'T': mask = 0x78; break;
        case 'U': mask = 0x3E; break;
        case 'Y': mask = 0x6E; break;
        case 'Z': mask = 0x5B; break;
        case '-': mask = 0x40; break;
        case '_': mask = 0x08; break;
        case '.': mask = 0x80; break;
        case '\'': mask = 0x20; break;
        case ' ': mask = 0x00; break;
        case '.': mask = 0x80; break;
        default:  mask = 0x40; break;
    }
    displayMask(mask);
}

void SevenSeg::clearDisplay() {
    for(int i = 0; i < segArrSize; i++) __digitalWrite(segArr[i], LOW);
}

void SevenSeg::writeDP() {
    if (segArrSize > 7) __digitalWrite(segArr[7], HIGH);
}

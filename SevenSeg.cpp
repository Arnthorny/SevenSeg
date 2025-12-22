#include "Sevenseg.h"
#include "Arduino.h"

SevenSeg::SevenSeg(int segments[], int size) {
    segArr = segments;
    segArrSize = size;

}

void SevenSeg::begin() {
    for(int i = 0; i < segArrSize; i++) {
        pinMode(segArr[i], OUTPUT);
    }

}

void SevenSeg::clearDisplay() {
    for(int i = 0; i < segArrSize; i++) {
        digitalWrite(segArr[i], LOW);
    }
}
void SevenSeg::writeDP() {
    digitalWrite(segArr[7], HIGH);
}
 
void SevenSeg::writeDigit(int num) {
    clearDisplay();
    switch (num) {
        case 1:
            digitalWrite(segArr[1], HIGH);
            digitalWrite(segArr[2], HIGH);
            break;
        case 2:
            digitalWrite(segArr[0], HIGH);
            digitalWrite(segArr[1], HIGH);
            digitalWrite(segArr[6], HIGH);
            digitalWrite(segArr[4], HIGH);
            digitalWrite(segArr[3], HIGH);
            break;
        case 3:
            digitalWrite(segArr[0], HIGH);
            digitalWrite(segArr[1], HIGH);
            digitalWrite(segArr[6], HIGH);
            digitalWrite(segArr[2], HIGH);
            digitalWrite(segArr[3], HIGH);
            break;
        case 4:
            digitalWrite(segArr[1], HIGH);
            digitalWrite(segArr[2], HIGH);
            digitalWrite(segArr[6], HIGH);
            digitalWrite(segArr[5], HIGH);
            break;
        case 5:
            digitalWrite(segArr[0], HIGH);
            digitalWrite(segArr[5], HIGH);
            digitalWrite(segArr[6], HIGH);
            digitalWrite(segArr[2], HIGH);
            digitalWrite(segArr[3], HIGH);
            break;
        case 6:
            digitalWrite(segArr[0], HIGH);
            digitalWrite(segArr[5], HIGH);
            digitalWrite(segArr[6], HIGH);
            digitalWrite(segArr[2], HIGH);
            digitalWrite(segArr[3], HIGH);
            digitalWrite(segArr[4], HIGH);
 
            break;
        case 7:
            digitalWrite(segArr[0], HIGH);
            digitalWrite(segArr[1], HIGH);
            digitalWrite(segArr[2], HIGH); 
            break;
        case 8:
           digitalWrite(segArr[0], HIGH);
           digitalWrite(segArr[1], HIGH);
           digitalWrite(segArr[2], HIGH);
           digitalWrite(segArr[3], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH); 
           digitalWrite(segArr[6], HIGH); 
           break;
        case 9:
            digitalWrite(segArr[0], HIGH);
            digitalWrite(segArr[5], HIGH);
            digitalWrite(segArr[6], HIGH);
            digitalWrite(segArr[1], HIGH);
            digitalWrite(segArr[2], HIGH);  
            digitalWrite(segArr[3], HIGH);
           break; 
        case 0:
           digitalWrite(segArr[0], HIGH);
           digitalWrite(segArr[1], HIGH);
           digitalWrite(segArr[2], HIGH);
           digitalWrite(segArr[3], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH);
           break;
        default:
           digitalWrite(segArr[6], HIGH); 
    }
}

void SevenSeg::writeChar(char c) {
    clearDisplay();
    switch (c) {
        case 'a':
        case 'A':
           digitalWrite(segArr[0], HIGH);
           digitalWrite(segArr[1], HIGH);
           digitalWrite(segArr[2], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH); 
           digitalWrite(segArr[6], HIGH); 
           break;
        
        case 'B':
        case 'b':
           digitalWrite(segArr[2], HIGH);
           digitalWrite(segArr[3], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH); 
           digitalWrite(segArr[6], HIGH); 
           break;

        case 'c':
        case 'C':
           digitalWrite(segArr[0], HIGH);
           digitalWrite(segArr[3], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH);
           break;
        
        case 'D':
        case 'd':
           digitalWrite(segArr[1], HIGH);
           digitalWrite(segArr[2], HIGH);
           digitalWrite(segArr[3], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[6], HIGH);
           break;

         case 'e':
         case 'E':
           digitalWrite(segArr[0], HIGH);
           digitalWrite(segArr[3], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH); 
           digitalWrite(segArr[6], HIGH); 
           break;

         case 'f':
         case 'F':
           digitalWrite(segArr[0], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH); 
           digitalWrite(segArr[6], HIGH);
           break;
        
        case 'G':
        case 'g':
            digitalWrite(segArr[0], HIGH);
            digitalWrite(segArr[5], HIGH);
            digitalWrite(segArr[6], HIGH);
            digitalWrite(segArr[1], HIGH);
            digitalWrite(segArr[2], HIGH);  
            digitalWrite(segArr[3], HIGH);
           break; 
 
         case 'H':
           digitalWrite(segArr[1], HIGH);
           digitalWrite(segArr[2], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH); 
           digitalWrite(segArr[6], HIGH); 
           break;


        case 'h':
           digitalWrite(segArr[2], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH); 
           digitalWrite(segArr[6], HIGH); 
           break;

        case 'i':
        case 'I':
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH); 
           break;

        case 'j':
        case 'J':
            digitalWrite(segArr[1], HIGH);
            digitalWrite(segArr[2], HIGH);
            digitalWrite(segArr[3], HIGH);
            break;

        case 'l':
        case 'L':
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH);
           digitalWrite(segArr[3], HIGH);
           break;

        case 'n':
        case 'N':
           digitalWrite(segArr[0], HIGH);
           digitalWrite(segArr[1], HIGH);
           digitalWrite(segArr[2], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH); 
           break;

        case 'O':
        case 'o':
           digitalWrite(segArr[0], HIGH);
           digitalWrite(segArr[1], HIGH);
           digitalWrite(segArr[2], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH); 
           digitalWrite(segArr[3], HIGH); 
           break;

        case 'p':
        case 'P':
           digitalWrite(segArr[0], HIGH);
           digitalWrite(segArr[1], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH); 
           digitalWrite(segArr[6], HIGH); 
           break;
        
        case 'R':
        case 'r':
           digitalWrite(segArr[0], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH); 
           break;

        case 's':
        case 'S':
            digitalWrite(segArr[0], HIGH);
            digitalWrite(segArr[5], HIGH);
            digitalWrite(segArr[6], HIGH);
            digitalWrite(segArr[2], HIGH);
            digitalWrite(segArr[3], HIGH);
            break;

        case 'T':
        case 't':
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH);
           digitalWrite(segArr[3], HIGH);
           digitalWrite(segArr[6], HIGH);
           break;

        case 'u':
        case 'U':
           digitalWrite(segArr[1], HIGH);
           digitalWrite(segArr[2], HIGH);
           digitalWrite(segArr[4], HIGH);
           digitalWrite(segArr[5], HIGH); 
           digitalWrite(segArr[3], HIGH); 
           break;

        case 'Y':
        case 'y':
           digitalWrite(segArr[1], HIGH);
           digitalWrite(segArr[2], HIGH);
           digitalWrite(segArr[6], HIGH);
           digitalWrite(segArr[5], HIGH); 
           digitalWrite(segArr[3], HIGH); 
           break;

        case 'z':
        case 'Z':
            digitalWrite(segArr[0], HIGH);
            digitalWrite(segArr[1], HIGH);
            digitalWrite(segArr[6], HIGH);
            digitalWrite(segArr[4], HIGH);
            digitalWrite(segArr[3], HIGH);
            break;

        case '-':
           digitalWrite(segArr[6], HIGH); 
           break;

        case '_':
           digitalWrite(segArr[3], HIGH); 
           break;

        case '.':
           digitalWrite(segArr[7], HIGH); 
           break;

        case '\'':
           digitalWrite(segArr[5], HIGH); 
           break;


        case ' ':
           clearDisplay();
           break;

        default:
           digitalWrite(segArr[6], HIGH); 

    }
}

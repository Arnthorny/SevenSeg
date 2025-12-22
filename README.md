
# SevenSeg Arduino Library

A lightweight, no-nonsense library for controlling 1-digit 7-segment LED displays. It supports digits (0-9), a limited set of alphanumeric characters, and basic punctuation.

## Installation

1. Create a folder named `Sevenseg` in your Arduino `libraries` directory.
2. Drop `Sevenseg.h` and `Sevenseg.cpp` into that folder.
3. Restart your Arduino IDE.

## Segment Mapping

The library assumes a standard 8-pin mapping (7 segments + decimal point). You must provide an array of pins in the following order:
`{a, b, c, d, e, f, g, dp}`

| Index | Segment |
| --- | --- |
| 0 | A (Top) |
| 1 | B (Upper Right) |
| 2 | C (Lower Right) |
| 3 | D (Bottom) |
| 4 | E (Lower Left) |
| 5 | F (Upper Left) |
| 6 | G (Middle) |
| 7 | DP (Decimal Point) |

## Usage

### 1. Initialization

Define your pins and pass them to the constructor. You must call `.begin()` in `setup()`.

```cpp
#include <Sevenseg.h>

// Define pins for segments a, b, c, d, e, f, g, dp
int displayPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; 
SevenSeg myDisplay(displayPins, 8, COMMON_CATHODE); // Use COMMON_ANODE if this is your 7-segment type

void setup() {
    myDisplay.begin();
}

```

### 2. Writing Data

* **`writeDigit(int num)`**: Displays numbers 0-9. Invalid inputs default to a middle dash `-`.
* **`writeChar(char c)`**: Displays supported characters (A-Z, space, dash, underscore, etc.).
* **`writeDP()`**: Manually turns on the decimal point.
* **`clearDisplay()`**: Turns off all segments.

```cpp
void loop() {
    myDisplay.writeDigit(5);  // Shows '5'
    delay(1000);
    myDisplay.writeChar('A'); // Shows 'A'
    delay(1000);
}

```

## Supported Characters

* **Numbers:** `0-9`
* **Letters:** `A, B, C, D, E, F, G, H, I, J, L, N, O, P, R, S, T, U, Y, Z` (Case-insensitive where applicable)
* **Symbols:** `-` (dash), `_` (underscore), `.` (period), `'` (apostrophe), `     ` (space)



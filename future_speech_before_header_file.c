#include <z180.h>
#include <stdio.h>
#include <stdlib.h>
#include "phonemes.h"

// I/O Port Configuration for SCZ180 + SP0256-AL2
#define DATA_PORT  31     // SP0256 data/address input port (A0–A5)
#define CTRL_PORT  30     // Control port for ALD
#define ALD_BIT    0x01   // Bit mask for ALD control
#define LRQ_BIT    0x02   // Bit mask for LRQ ready signal

// Short delay for timing (approx ~10us)
void delay() {
    for (volatile int i = 0; i < 50; i++) {
        __asm__("nop");
    }
}

// Pulse ALD to latch allophone into SP0256
void pulse_ald() {
    z180_outp(CTRL_PORT, z180_inp(CTRL_PORT) & ~ALD_BIT); // ALD low
    delay();
    z180_outp(CTRL_PORT, z180_inp(CTRL_PORT) | ALD_BIT);  // ALD high
    delay();
    z180_outp(CTRL_PORT, z180_inp(CTRL_PORT) & ~ALD_BIT); // ALD low
}

// Wait for LRQ high (ready), then send phoneme
void speak(uint8_t code) {
    while (!(z180_inp(DATA_PORT) & LRQ_BIT)) ;
    z180_outp(DATA_PORT, code & 0x3F);
    pulse_ald();
}

// Allophone list for: "The future is now, tomorrow never sleeps."
int input[] = {
    // "The"
    18,  // /DH1/
    15,  // /AX/
    1,   // PA2

    // "Future"
    40,  // /F/
    49,  // /YY1/
    22,  // /UW1/
    50,  // /CH/
    51,  // /IER1/
    1,   // PA2

    // "Is"
    12,  // /IH/
    43,  // !Zoo (Z)
    1,   // PA2

    // "Now"
    11,  // /NN1/
    32,  // /AW/
    4,   // PA5

    // "Tomorrow"
    17,  // /TT1/
    15,  // /AX/
    16,  // /MM/
    23,  // /AO/
    14,  // /RR1/
    53,  // /fOWl/
    1,   // PA2

    // "Never"
    11,  // /NN1/
    7,  // /EH/
    35,  // /IVV/
    51,  // /IER1/
    1,   // PA2

    // "Sleeps"
    55,  // /SS/
    45,  // /ILLI/
    19,  // /IY/
    9,   // /PP/
    55,  // /SS/
    2    // PA3
};

void main() {
    printf("Speaking...\n");

    int size = sizeof(input) / sizeof(input[0]);

    for (int i = 0; i < size; i++) {
        speak((uint8_t)input[i]);
    }

    printf("Done.\n");
}
// End of future_speech.c

// Note: This code assumes the SP0256-AL2 is connected to the SCZ180
// and that the necessary hardware setup is done correctly.
// The allophone codes used in the input array are based on the SP0256-AL2 documentation.
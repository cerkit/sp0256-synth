#include <z180.h>
#include <stdio.h>
#include <stdlib.h>
#include "phonemes.h"  // Include allophone definitions

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
    AL_DH1, AL_AX, AL_PA2,

    // "Future"
    AL_F, AL_YY1, AL_UW1, AL_CH, AL_ER1, AL_PA2,

    // "Is"
    AL_IH, AL_ZZ, AL_PA2,

    // "Now"
    AL_NN1, AL_AW, AL_PA5,

    // "Tomorrow"
    AL_TT1, AL_AX, AL_MM, AL_AO, AL_RR1, AL_OW, AL_PA2,

    // "Never"
    AL_NN1, AL_EH, AL_VV, AL_ER1, AL_PA2,

    // "Sleeps"
    AL_SS, AL_LL, AL_LY, AL_PP, AL_SS, AL_PA3
};

void main() {
    printf("Speaking...\n");

    int size = sizeof(input) / sizeof(input[0]);

    for (int i = 0; i < size; i++) {
        speak((uint8_t)input[i]);
    }

    printf("Done.\n");
}

// phonemes.h — SP0256-AL2 allophone definitions (decimal only)

#ifndef PHONEMES_H
#define PHONEMES_H

// Pauses
#define AL_PA1     0
#define AL_PA2     1
#define AL_PA3     2
#define AL_PA4     3
#define AL_PA5     4

// Vowels and diphthongs
#define AL_OY      5
#define AL_AY      6
#define AL_EH      7
#define AL_KK3     8
#define AL_PP      9
#define AL_JH      10
#define AL_NN1     11
#define AL_IH      12
#define AL_ITT21   13
#define AL_RR1     14
#define AL_AX      15
#define AL_MM      16
#define AL_TT1     17
#define AL_DH1     18
#define AL_LY      19
#define AL_EY      20
#define AL_001     21
#define AL_UW1     22
#define AL_AO      23
#define AL_AA      24
#define AL_YY2     25
#define AL_AE      26
#define AL_HH1     27
#define AL_BB1     28
#define AL_TH      29
#define AL_UH      30
#define AL_UW2     31
#define AL_AW      32
#define AL_002     33
#define AL_GG3     34
#define AL_VV      35
#define AL_GG1     36
#define AL_SH      37
#define AL_ZH      38
#define AL_RR2     39

// Consonants
#define AL_F       40
#define AL_KK2     41
#define AL_KK1     42
#define AL_ZZ      43
#define AL_NG      44
#define AL_LL      45
#define AL_WW      46
#define AL_XR      47
#define AL_WH      48
#define AL_YY1     49
#define AL_CH      50
#define AL_ER1     51
#define AL_ER2     52
#define AL_OW      53
#define AL_DH2     54
#define AL_SS      55
#define AL_NN2     56
#define AL_HH2     57
#define AL_OR      58
#define AL_AR      59
#define AL_YR      60
#define AL_GG2     61
#define AL_EL      62
#define AL_BB2     63

#endif // PHONEMES_H
// End of phonemes.h

// Note: The above definitions are used to map phonemes to their respective allophone codes.
// These codes are used in the speech synthesis process to generate spoken output based on the phonetic representation of words.
// The phonemes.h file is essential for the speech synthesis functionality of the SP0256-AL2 chip, allowing it to produce intelligible speech by combining these phonemes in various sequences.
// Each phoneme corresponds to a specific sound in the English language, and the definitions provided here are used in conjunction with the speech synthesis code to create spoken words and sentences.

// The phonemes.h file is part of a larger project that includes the SCZ180 microcontroller and the SP0256-AL2 speech synthesis chip.
// The definitions in this file are used to control the speech synthesis process, allowing the microcontroller to produce speech by sending the appropriate allophone codes to the SP0256-AL2 chip.

// The phonemes are defined in a way that allows for easy reference in the speech synthesis code.
// Each phoneme is assigned a unique identifier, which can be used to refer to it in the code.
// This makes it easier to construct sentences and phrases by combining different phonemes together.

// The definitions provided here are based on the SP0256-AL2 documentation and are used in the speech synthesis process to generate intelligible speech.
// The phonemes.h file is essential for the speech synthesis functionality of the SP0256-AL2 chip, allowing it to produce spoken output based on the phonetic representation of words.
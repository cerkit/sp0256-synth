# SP0256-AL2 Speech Synthesizer (Z80 / Z88DK)

A classic, no-nonsense driver and toolchain for driving the General Instrument SP0256-AL2 allophone speech chip from a Z80 CPU, built with the Z88DK toolkit.

---

## 📜 Overview

This project delivers a proven, straightforward implementation of SP0256-AL2 speech synthesis, using:

- **Allophone table** mapping decimal codes (0–63) to phonemes  
- A **C header** (`phonemes.h`) for easy phoneme reference in your Z80 code  
- A **phrase-to-allophone compiler** (C# .NET 8 CLI) to convert text strings into allophone sequences  
- Example Z80 driver code targeting the SCZ180+SP0256-AL2 platform  
- Integration with **Z88DK** for cross-compiling your speech programs

By sticking to time-tested patterns and a clear allophone mapping, you get reliable speech output with minimal runtime overhead.

---

## 🎯 Features

- **Complete allophone mapping**: Decimal values 0–63 → phoneme names (stored in `include/phonemes.h`)
- **C driver** for SP0256-AL2 control and data latching  
- **Phrase compiler** to preprocess text into SP0256-AL2-compatible allophone sequences  
- **Z88DK build scripts** for seamless cross-compilation to Z80 targets  
- **Minimal dependencies**—just a Z80 system, SP0256-AL2, and Z88DK  

---

## 📖 Allophone Table

| Code | Phoneme | Code | Phoneme | Code | Phoneme | Code | Phoneme |
|:----:|:-------:|:----:|:-------:|:----:|:-------:|:----:|:-------:|
|  0   | AL_PA1  | 16   | AL_RR1  | 32   | AL_AW   | 48   | AL_WH   |
|  1   | AL_PA2  | 17   | AL_AX   | 33   | AL_AY   | 49   | AL_YY1  |
|  2   | AL_PA3  | 18   | AL_MM   | 34   | AL_EH   | 50   | AL_CH   |
|  3   | AL_PA4  | 19   | AL_TT1  | 35   | AL_OY   | 51   | AL_ER1  |
|  4   | AL_PA5  | 20   | AL_DH1  | 36   | AL_AO   | 52   | AL_ER2  |
|  5   | AL_OY   | 21   | AL_LY   | 37   | AL_AA   | 53   | AL_OW   |
|  6   | AL_AY   | 22   | AL_EY   | 38   | AL_AE   | 54   | AL_DH2  |
|  7   | AL_EH   | 23   | AL_KK3  | 39   | AL_AH   | 55   | AL_SS   |
|  8   | AL_KK3  | 24   | AL_PP   | 40   | AL_EH1  | 56   | AL_NN2  |
|  9   | AL_PP   | 25   | AL_JH   | 41   | AL_EH2  | 57   | AL_HH2  |
| 10   | AL_JH   | 26   | AL_NN1  | 42   | AL_ER   | 58   | AL_OR   |
| 11   | AL_NN1  | 27   | AL_IH   | 43   | AL_UH1  | 59   | AL_AR   |
| 12   | AL_IH   | 28   | AL_ITT2 | 44   | AL_UH2  | 60   | AL_YR   |
| 13   | AL_ITT2 | 29   | AL_RR2  | 45   | AL_OW1  | 61   | AL_GG2  |
| 14   | AL_RR1  | 30   | AL_AX2  | 46   | AL_OW2  | 62   | AL_EL   |
| 15   | AL_AX   | 31   | AL_MM2  | 47   | AL_AW1  | 63   | AL_BB2  |

*(See `include/phonemes.h` for the full definitions.)*

---

## 🛠️ Prerequisites

- **Z88DK** (Z80 C development toolkit)  
  Clone or install from:  
  https://github.com/z88dk/z88dk

- A **Z80-based target** (e.g., SCZ180, CP/M, custom board) wired to an SP0256-AL2
  
---

## 🚀 Building & Installation

1. **Clone this repo**  
   ```bash
   git clone https://github.com/cerkit/sp0256-synth.git
   cd sp0256-synth
   ```

2. **Build your Z80 firmware**  
   ```bash
   make clean
   make TARGET=scz180
   ```
3. **Upload** the generated binary (`.bin` or `.com`) to your retro computer using XMODEM.

---

## ⚙️ Usage

- **In Z80 code**, include the header and call:
  ```c
  #include "phonemes.h"

  void sp0256_init(void);
  void sp0256_say(uint8_t *allophones);
  ```

---

## 📝 References

- **Z88DK** – Z80 C compiler toolkit  
  https://github.com/z88dk/z88dk
- **General Instrument SP0256-AL2 Datasheet**
- **Allophone definitions** from `include/phonemes.h`

---

## 🤝 Contributing

Traditional, battle-tested code wins. If you spot an error in the phoneme mapping, send a PR against `include/phonemes.h`.

# SP0256-AL2 Speech Synthesizer (Z80 / Z88DK)

A classic, no-nonsense driver and toolchain for driving the General Instrument SP0256-AL2 allophone speech chip from a Z80 CPU, built with the Z88DK toolkit.

This has been tested and is working on the following hardware:

[SC126 z180 computer](https://www.tindie.com/products/tindiescx/sc126-z180-sbcmotherboard-kit-for-rcbus/)

[Speech Synthesizer for RC2014-style computers](https://www.tindie.com/products/mrgelee/mg005-speech-synthesiser-designed-for-rc2014/?pt=ac_prod_search)

Here is a short video that covers this process:

[Tomorrow never sleeps on YouTube](https://youtu.be/zUu2rRYJoMU)

---

## 📜 Overview

This project delivers a proven, straightforward implementation of SP0256-AL2 speech synthesis, using:

- **Allophone table** mapping decimal codes (0–63) to phonemes  
- A **C header** (`phonemes.h`) for easy phoneme reference in your Z80 code  
- Example Z80 driver code targeting the SCZ180+SP0256-AL2 platform  
- Integration with **Z88DK** for cross-compiling your speech programs

By sticking to time-tested patterns and a clear allophone mapping, you get reliable speech output with minimal runtime overhead.

---

## 🎯 Features

- **Complete allophone mapping**: Decimal values 0–63 → phoneme names (stored in `include/phonemes.h`)
- **C driver** for SP0256-AL2 control and data latching  
- **Z88DK build scripts** for seamless cross-compilation to Z80 targets  
- **Minimal dependencies**—just a [Z80 system](https://www.tindie.com/products/tindiescx/sc126-z180-sbcmotherboard-kit-for-rcbus/), [SP0256-AL2](https://www.tindie.com/products/mrgelee/mg005-speech-synthesiser-designed-for-rc2014/?pt=ac_prod_search), and [Z88DK](https://github.com/z88dk/z88dk)  

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
  [https://github.com/z88dk/z88dk](https://github.com/z88dk/z88dk)

- A **Z80-based target** (e.g., SCZ180, CP/M, custom board) wired to an SP0256-AL2
  
---

## 🚀 Building & Installation

1. **Clone this repo**  
   ```bash
   git clone https://github.com/cerkit/sp0256-synth.git
   cd sp0256-synth
   ```
2. Ensure that the Z88DK binaries are in your PATH: `export PATH=${PATH}:${HOME}/z88dk/bin           
export ZCCCFG=${HOME}/z88dk/lib/config`

3. **Build your PROGRAM.bin file**  
   ```bash
   zcc +scz180 -o future future_speech.c -create-app
   ```
4. **Upload** the generated binary (`future.bin` to `future.com`) to your retro computer using XMODEM (I am using the [`serial`](https://apps.apple.com/us/app/serial/id877615577?mt=12)) program for MacOS).
  ``` bash
    c:
    b:xm r future.com
  ```
- Choose to Send File by XMODEM in terminal program
- Upload the future.bin file
    
---

## ⚙️ Usage

- **In Z80 code**, include the headers:
  ```c
  #include <z180.h>
#include <stdio.h>
#include <stdlib.h>
#include "phonemes.h"  // Include allophone definitions
  ```

---

## 📝 References

- **Z88DK** – Z80 C compiler toolkit  
  [https://github.com/z88dk/z88dk](https://github.com/z88dk/z88dk)
- **General Instrument SP0256-AL2 Datasheet**
- **Allophone definitions** from `include/phonemes.h`

---

## 🤝 Contributing

Traditional, battle-tested code wins. If you spot an error in the phoneme mapping, send a PR against `include/phonemes.h`.

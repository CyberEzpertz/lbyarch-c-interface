# LBYARCH C-ASM Interface
This project was created to show the interfacing between C and ASM for our LBYARCH Project. This project additionally shows the difference in execution speed for a function implemented in ASM and in C.

## Project Instructions
Implement a program that converts the grayscale image representation from float based to integer based using C and x86 assembly language. Implement the function imgCvtGrayDoubleToInt().
* Required to use functional scalar SIMD registers
* Required to use functional scalar SIMD floating-point instructions

**Input:** height, width, double float pixel values

**Output:** Integer pixel values

## Setup
To run the program, either use VS2022 or run the following lines of code on your terminal:
```sh
nasm -f win64 asmfunc.asm
gcc -c main.c -o main.obj -m64
gcc asmfunc.obj main.obj -o mp2.exe -m64
mp2.exe
```

## Performance Benchmark & Analysis
### Hardware Specifications
| | |
| --- | --- |
| CPU | Intel i5-8300H |
| RAM | 32GB DDR4 2667MHz |
| OS | Windows 11 |

### Execution Times
> [!NOTE]
> The time shown below is the average of running the respective functions 30 times.

| Input Size | C Exec. Time (ms) | ASM Exec. Time (ms) | % Difference |
| ------------- | -------------: | -------------: | ---: | 
| 10x10 | 0.0000ms | 0.0000ms | ~0% |
| 100x100 | 0.3667ms | 0.0333ms | ~1101% |
| 1000x1000 | 26.9000ms | 2.1333ms | ~1260% |

### Analysis
TBA

## Contributors (LBYARCH S12 - Group 1)
- Murillo, Jan Anthony B.
- Yap, Rafael Subo A.

# LBYARCH C-ASM Interface
This project was created to show the interfacing between C and ASM for our LBYARCH Project. This project additionally shows the difference in execution speed for a function implemented in ASM and in C.

## Group Members (LBYARCH S12 - Group 1)
- Murillo, Jan Anthony B.
- Yap, Rafael Subo A.

## Project Description
Implement a program that converts the grayscale image representation from float based to integer based using C and x86 assembly language. Implement the function imgCvtGrayDoubleToInt().
* Required to use functional scalar SIMD registers
* Required to use functional scalar SIMD floating-point instructions

**Input:** height, width, double float pixel values
```
3 4
0.25 0.35 0.45 0.33
0.55 0.65 0.75 0.33
0.85 0.95 0.15 0.33
```

**Output:** Integer pixel values
```
64, 89, 114, 84
140, 166, 191, 84
216, 242, 38, 84
```

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
| Part | Specification |
| --- | --- |
| CPU | Intel i5-8300H |
| RAM | 32GB DDR4 2667MHz |
| OS | Windows 11 |

### Execution Times
> [!NOTE]
> The time shown below is the average of running the respective functions 30 times.
> The benchmark also shows the time in milliseconds, to show much more detail in the performance.

| Input Size | C Exec. Time (ms) | ASM Exec. Time (ms) |
| ------------- | -------------: | -------------: |
| 10x10 | 0.0000ms | 0.0000ms |
| 100x100 | 0.3667ms | 0.0333ms |
| 1000x1000 | 26.9000ms | 2.1333ms |

### Performance Analysis
From what we can see in the benchmarks, the function implemented in assembly runs much faster than its C counterpart. This performance difference is much more easily seen once the input size grows, but even in small input sizes it's still really visible.

With a 10x10 input size, the function very easily processes the input that it only shows 0.000ms. For the 100x100 input size, it is definitely still fast, only growing by around ~0.0333ms from the 10x10 input size. As for the 1000x1000, it is still incredibly fast, with it only taking 2.1333ms, not even reaching a full second. To put it in perspective, only 2.1ms was added for an increase from 10,000 input values to 1,000,000!

From this we can infer that using C to interface with functions made in assembly can create much faster programs. 

## Program Outputs
### Case 1: Manual Input
![image](https://github.com/user-attachments/assets/f93fb0b8-dea5-43bc-9901-66675ae8eaec)

### Case 2: Randomly Generate Values
![image](https://github.com/user-attachments/assets/e7a9967d-2b5f-418e-9f66-8154d8494fc2)

### Case 3: Generate matrix with 0.5 values
![image](https://github.com/user-attachments/assets/b79f0668-b53c-45d5-bc0e-ec6895d3fafd)

## Demo Video
The file was too large to upload to the GitHub repository or embed into the readme file, so the group uploaded it to Google Drive. Here's the link:
[https://drive.google.com/file/d/1GmGXx8r9pEydxqQc0UokS2SUZdoZNSYc/view?usp=sharing](https://drive.google.com/file/d/1GmGXx8r9pEydxqQc0UokS2SUZdoZNSYc/view?usp=sharing)

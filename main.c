#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void imgCvtGrayFloatToInt(int count, double* img_float, int* img_int);

void imgCvtGrayFloatToInt_C(int count, double* img_float, int* img_int) {
	for (int i = 0; i < count; i++) {
		img_int[i] = (int)(img_float[i] * 255);
	}
}

int main() {
	clock_t start, end;
	double asm_exec_time = 0;
	double c_exec_time = 0;

	int rows, cols;

	scanf_s("%d %d", &rows, &cols);

	double* img_float = malloc((rows * cols) * sizeof(double));
	int* img_int = malloc((rows * cols) * sizeof(int));

	// Initialize Arrays
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			// If ever user input is needed
			scanf_s("%lf", &img_float[i * cols + j]);
			// Initialize with 0.5, the answers should be 128
			//img_float[i * cols + j] = 0.5;
			img_int[i * cols + j] = 0;
		}
	}

	// Run 30 times to get ave. execution time for C
	for (int i = 0; i < 100; i++) {
		start = clock();
		imgCvtGrayFloatToInt_C(rows * cols, img_float, img_int);
		end = clock();
		c_exec_time += ((double)(end - start)) / CLOCKS_PER_SEC;
	}

	printf("C RESULTS\n");

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", img_int[i * cols + j]);
		}
		printf("\n");
	}

	// Run 30 times to get ave. execution time for asm
	for (int i = 0; i < 100; i++) {
		start = clock();
		imgCvtGrayFloatToInt(rows * cols, img_float, img_int);
		end = clock();
		asm_exec_time += ((double)(end - start)) / CLOCKS_PER_SEC;
	}

	printf("ASM RESULTS\n");

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", img_int[i * cols + j]);
		}
		printf("\n");
	}

	asm_exec_time /= 30;
	c_exec_time /= 30;

	printf("Average ASM Execution Time: %fs\n", asm_exec_time);
	printf("Average C Execution Time: %fs\n", c_exec_time);

	free(img_float);
	free(img_int);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void imgCvtGrayFloatToInt(int count, double* img_float, int* img_int);

void imgCvtGrayFloatToInt_C(int count, double* img_float, int* img_int) {
	for (int i = 0; i < count; i++) {
		img_int[i] = (int)(round(img_float[i] * 255));
	}
}

void writeImgFloatVals(int rows, int cols, double* img_float, char* filename) {
	FILE* f = fopen(filename, "w");

	if (f == NULL) {
		printf("Error opening file\n");
		return;
	}


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fprintf(f, "%.2f\t", img_float[i * cols + j]);
		}
		fprintf(f, "\n");
	}

	fclose(f);
}

void writeImgVals(int rows, int cols, int* img_int, char* filename) {
	FILE* f = fopen(filename, "w");

	if (f == NULL) {
		printf("Error opening file\n");
		return;
	}

	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fprintf(f, "%d\t", img_int[i * cols + j]);
		}
		fprintf(f, "\n");
	}

	fclose(f);
}

void printIntValues(int rows, int cols, int* img_int) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (j > 14) {
				printf("...");
				break;
			}
			printf("%d\t", img_int[i * cols + j]);
		}
		printf("\n");

		if (i > 14) {
			printf("Check output files for complete results.\n\n");
			break;
		}
	}
}

int main() {
	clock_t start, end;
	double asm_exec_time = 0;
	double c_exec_time = 0;

	int rows, cols;
	printf("Enter the no. of rows and cols separated by space (e.g. '3 4'): ");
	scanf_s("%d %d", &rows, &cols);

	double* img_float = malloc((rows * cols) * sizeof(double));
	int* img_int = malloc((rows * cols) * sizeof(int));

	int userInput = 0;

	printf("How do you want to input the values?\n");
	printf("[1] Input matrix values manually\n");
	printf("[2] Randomly generate matrix values\n");
	printf("[3] Generate matrix with [0.5] for all values\n");
	scanf_s("%d", &userInput);

	switch (userInput) {
	case 1:
		printf("===ENTER MATRIX VALUES===\n");
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				scanf_s("%lf", &img_float[i * cols + j]);
				img_int[i * cols + j] = 0;
			}
		}
		break;
	case 2:
		printf("===GENERATED VALUES===\n");

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				double rand_val = (double)rand() / (double)RAND_MAX;

				if (j < 15) {
					printf("%.2f\t", rand_val);
				}
				else if (j == 15) {
					printf("...");
				}

				img_float[i * cols + j] = rand_val;
				img_int[i * cols + j] = 0;
			}
			printf("\n");
		};

		printf("Generated values stored to 'generated_vals.txt'\n");
		writeImgFloatVals(rows, cols, img_float, "generated_vals.txt");
		break;
	case 3:
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				// Initialize with 0.5, the answers should be 128
				img_float[i * cols + j] = 0.5;
				img_int[i * cols + j] = 0;
			}
		}
		break;
	default:
		printf("Invalid input. Exiting the program...");
		return;
	}

	printf("\n");

	// Run multiple times to get ave. execution time for C
	for (int i = 0; i < 30; i++) {
		start = clock();
		imgCvtGrayFloatToInt_C(rows * cols, img_float, img_int);
		end = clock();
		c_exec_time += ((double)(end - start)) / CLOCKS_PER_SEC;
	}

	printf("===C RESULTS===\n");
	printIntValues(rows, cols, img_int);

	// Print the results if they got truncated
	writeImgVals(rows, cols, img_int, "c_output.txt");

	// Run multiple times to get ave. execution time for asm
	for (int i = 0; i < 30; i++) {
		start = clock();
		imgCvtGrayFloatToInt(rows * cols, img_float, img_int);
		end = clock();
		asm_exec_time += ((double)(end - start)) / CLOCKS_PER_SEC;
	}

	printf("\n===ASM RESULTS===\n");
	printIntValues(rows, cols, img_int);

	// Print the results if they got truncated
	writeImgVals(rows, cols, img_int, "asm_output.txt");

	asm_exec_time /= 30;
	c_exec_time /= 30;

	asm_exec_time *= 1000;
	c_exec_time *= 1000;

	printf("Average ASM Execution Time (30 Runs): %.4fms\n", asm_exec_time);
	printf("Average C Execution Time (30 Runs): %.4fms\n", c_exec_time);

	free(img_float);
	free(img_int);

	return 0;
}
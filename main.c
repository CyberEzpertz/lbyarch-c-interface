#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void imgCvtGrayFloatToInt(int count, double* img_float, int* img_int);

int main() {

	int rows, cols;

	scanf_s("%d %d", &rows, &cols);

	double* img_float = malloc((rows * cols) * sizeof(double));
	int* img_int = malloc((rows * cols) * sizeof(int));

	// get input array
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			scanf_s("%lf", &img_float[i * cols + j]);
			img_int[i * cols + j] = 0;
		}
	}

	imgCvtGrayFloatToInt(rows * cols, img_float, img_int);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", img_int[i * cols + j]);
		}
		printf("\n");
	}


	free(img_float);
	free(img_int);

	return 0;
}
#include <stdio.h>

int main()
{
  int rows = 1000;
  int cols = 1000;

  printf("%d %d\n", rows, cols);

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("0.5 ");
    }
    printf("\n");
  }
  return 0;
}
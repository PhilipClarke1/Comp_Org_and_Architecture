#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  int n;
  printf("Please enter the size of the square: ");
  if (scanf("%d", &n) == 0) {
    printf("failed to read integer .\n");
  }
  if(n % 2 == 0) {
    exit(0);
  }

  int square[n][n]; 
  
  
for (int l = 0; l < n; l++) {
    for (int j = 0; j < n; j++) {
      square[l][j] = 0;
      }
  }
  
  int row = 0;
  int col = (n + 1) / 2;

  for (int i = 1; i <= n * n; i++) {

    square[row][col] = i;

    int oldrow = row;
    int oldcol = col;

    row -= 1;
    if (row < 0) {
      row = n - 1;
    }

    col += 1;
    if (col > n - 1) {
      col = 0;
    }

    if (square[row][col] > 0) {
      row = oldrow;
      col = oldcol;
      row += 1;
      if (row > n - 1) {
        row = 0;
      }
    }
  }

  // int size = sizeof square / sizeof square[0];

  for (int l = 0; l < n; l++) {
    for (int j = 0; j < n; j++) {
      printf("%i", square[l][j]);
      printf(" ");
    }
    printf("\n");
  }
  return 0;
}
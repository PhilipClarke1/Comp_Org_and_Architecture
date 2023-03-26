#include <stdio.h>
#include <stdlib.h>
/**
 * Implement Polybius square decryption
 */

int main(int argc, char *argv[]) {
  char cipher[5][5] = {{'l', 'a', 'b', 'o', 'r'},
                       {'c', 'd', 'e', 'f', 'g'},
                       {'h', 'i', 'j', 'k', 'm'},
                       {'n', 'p', 's', 't', 'u'},
                       {'v', 'w', 'x', 'y', 'z'}};

  // Open the file
  FILE *f = fopen("file2.txt", "r");

  // Check the return code
  if (f == NULL) {
    perror("fopen");
    exit(1);
  }

  // Declare character buffer
  char buf[50];

  // Loop over the remaining lines that have data
  while (fgets(buf, sizeof(buf), f) != NULL) {

    int kierson = 0;
    int gus = 0;
    while (buf[gus] != '\0') {
      kierson++;
      gus++;
    }

    int i = 0;
    while (i < kierson) {
      int first = buf[i] - '0';
      int second = buf[i + 1] - '0';
      printf("%c", cipher[first][second]);
      i = i + 2;
    }
  }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Implement Polybius square encryption
 */

int main(int argc, char *argv[]) {

  // 2d array for cipher
  char cipher[5][5] = {{'l', 'a', 'b', 'o', 'r'},
                       {'c', 'd', 'e', 'f', 'g'},
                       {'h', 'i', 'j', 'k', 'm'},
                       {'n', 'p', 's', 't', 'u'},
                       {'v', 'w', 'x', 'y', 'z'}};

  // Open the file
  FILE *f = fopen("file.txt", "r");

  // Check the return code
  if (f == NULL) {
    perror("fopen");
    exit(1);
  }

  // Declare character buffer
  char buf[100];

  // Loop over the remaining lines that have data
  while (fgets(buf, sizeof(buf), f) != NULL) {

    // counts the # of indicies in buf[] that have chars in them
    int kierson = 0;
    int gus = 0;
    while(buf[gus] != '\0') {
      kierson++;
      gus++;
    }
    // iterates through buf[] giving the characters the corresp #
    int i = 0;
    while(i < kierson) {
      for (int k = 0; k < 5; k++) {
        for (int j = 0; j < 5; j++) {
          if (buf[i] == 'q') {
            printf("%d", 21);
            i++;
          }
          if (cipher[k][j] == buf[i]) {
            printf("%d", k);
            printf("%d", j);
            break;
          }
        }
      }i++;
    }

    return 0;
  }
}
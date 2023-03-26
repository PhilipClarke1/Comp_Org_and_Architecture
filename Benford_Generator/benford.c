/**
 * Validating Benford's Law for Census data
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  // Open the file
  FILE *f = fopen("co-est2021-alldata.csv", "r");

  // Check the return code
  if (f == NULL) {
    perror("fopen");
    exit(1);
  }

  // Declare character buffer
  char buf[1024];

  int firstLine = 1;

  //initialize array that records how many times each first digit appears
  int counts[10];
  for(int i = 0; i < 10; i++) {
      counts[i] = 0;
    }

  

  // Add the number of lines we read over (made to a float to get decimal answer when dividing with an int)
  float lines = 0;

  
  // Loop over the remaining lines that have data
  while (fgets(buf, sizeof(buf), f) != NULL) {

    // Skip the first line that contains the field names
    if (firstLine) {
      firstLine = 0;
      continue;
    }

    // Print the line
    printf("%s", buf);

    // Use strtok to get the tenth value
    char *token;
    token = strtok(buf, ",");

    for(int i = 0; i < 9; i++) {
      token = strtok(NULL, ",");
      if(i == 8) {
        // printf("%s\n", token);
        
        // Get the first digit
        char firstDigit = *token;

        int value = firstDigit - '0';
    
        // adding 1 to counts[value] for every instance of first digit
        counts[value] = counts[value] + 1;
      }
    }
    lines++;
    }


  
  for(int i = 0; i < 10; i++) {
    // printf("%d\n", counts[i]);
    float fraction = counts[i] / lines;
    printf("Fraction of leading %d's = %f\n", i, fraction);
  }
 
  
}
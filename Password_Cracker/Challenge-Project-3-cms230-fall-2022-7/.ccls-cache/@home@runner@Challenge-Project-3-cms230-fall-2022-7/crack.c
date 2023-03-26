// Tales from the Crypt

#include <stdio.h>
#include <unistd.h>
#include <crypt.h>
#include <string.h>
#include <stdlib.h>


char* cracker(char* x, char* y, int cap, int num) {

  char *salt = "$1$";


  // Reading the dictionary 
  // for each line calculate the hash 
  // compare hash to password
  // return word if hash match
    // Read Input File
  FILE *f = fopen(y, "r");

  if (f == NULL) {
    perror("fopen");
    exit(1);
  }

  char buff[1024];

  while (fgets(buff, sizeof(buff), f) != NULL) {

    buff[strcspn(buff, "\n")] = 0;
    if (cap == 1) {
           buff[0] ^= 32;
     }
    if (num == 1) {
      for (int i = 0; i <= 9; i++) {
        // Convert the number to a string.
        char num[2];
        sprintf(num, "%d", i);
        strcat(buff, num);
        char *hashNum = crypt(buff, salt);
        if (strcmp(hashNum, x) == 0) {
          return strdup(buff);
        }
      }
    }
      char *hash = crypt(buff, salt);
      if (strcmp(hash, x) == 0) {
        return strdup(buff);
      }

    
}
return 0;
}



int main(int argc, char *argv[]) {

  //*** Process input arguments ***//

  char *input = NULL;
  char *output = NULL;
  char *dictionary = NULL;
  
  int n = 0;
  int c = 0;
  char a;
  
  while((a = getopt(argc, argv, "i:o:d:nc")) != -1) {
    switch (a) {
      case 'i' :
        input = optarg;
        break;
      case 'o' :
        output = optarg;
        break;
      case 'd' :
        dictionary = optarg;
        break;
      case 'n' :
        n = 1;
        break;
      case 'c' :
        c = 1;
        break;
    }
  }


  // Read Input File
  FILE *f = fopen(input, "r");
  FILE *w = fopen(output, "w");
  

  if (f == NULL) {
    perror("fopen");
    exit(1);
  }
  if (w == NULL) {
    perror("fopen");
    exit(1);
  }

  char buff[1024];

  while (fgets(buff, sizeof(buff), f) != NULL) {
    
    char *token;
    token = strtok(buff, ":");

    token = strtok(NULL, ":");
  
    token[strcspn(token, "\n")] = 0;
    char* password = strdup(cracker(token, dictionary, c, n));
    int res = fputs(password, w);
    if (res == EOF){
      exit(1);
    }
    fputs("\n", w);
  }
    
  
  //*** You do the rest ***//
  //***       no       ***//
  fclose(f);
  fclose(w);
  return 0;
  }
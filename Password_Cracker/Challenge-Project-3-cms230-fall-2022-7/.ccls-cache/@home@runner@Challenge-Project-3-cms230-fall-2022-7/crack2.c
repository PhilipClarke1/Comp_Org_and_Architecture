// Tales from the Crypt

#include <stdio.h>
#include <unistd.h>
#include <crypt.h>
#include <string.h>
#include <stdlib.h>


char* cracker(char* x, char* y) {

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
    

    char *hash = crypt(buff, salt);
    


    // printf("%d\n", strcmp(hash,x));
    
    if (strcmp(hash, x) == 0) {
      printf("%s", buff);
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

  if (f == NULL) {
    perror("fopen");
    exit(1);
  }

  char buff[1024];

  while (fgets(buff, sizeof(buff), f) != NULL) {
    
    char *token;
    token = strtok(buff, ":");

    token = strtok(NULL, ":");

    token[strcspn(token, "\n")] = 0;

    // printf("%s\n", token);
    cracker(token, dictionary);
    // int value2 = strlen(token);
    // printf("%d\n", value2);
  }
    
  
  //*** You do the rest ***//
  //***       no       ***//
  return 0;
  }
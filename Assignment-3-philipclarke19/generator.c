#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int benfordDigit() {
  
  double r = ((double) rand()) / RAND_MAX;

  if (r < .3010) { // bit more than 30% of values are 1's
  return 1;
} else if (r < .4770) { // An additional 17.6% are 2's
  return 2;
}else if(r < .6020) {
    return 3;
}else if(r < .6990) {
    return 4;
}else if(r < .778) {
    return 5;
}else if(r < .8450) {
    return 6;
}else if(r < .9030) {
    return 7;
}else if(r < .9540) {
    return 8;
}else {
    return 9;
}
}

int uniformDigit() {

    double r = ((double) rand()) / RAND_MAX;

    if (r < .1) { //  more than 30% of values are 1's
      return 1;
    } else if (r < .2) { // An additional 17.6% are 2's
      return 2;
    }else if(r < .3) {
      return 3;
    }else if(r < .4) {
      return 4;
    }else if(r < .5) {
      return 5;
    }else if(r < .6) {
      return 6;
    }else if(r < .7) {
      return 7;
    }else if(r < .8) {
      return 8;
    }else if (r < .9){
      return 9;
    }else {
      return 0;
    }
  
}

int main(int argc, char *argv[]) {

  int numValues = 0;
  int numDigits = 0;

  // Process arguments with getopxtt
  int c;
  while ((c = getopt(argc, argv, "n:d:")) != -1) {
    switch (c) {
      case 'n':
        numValues = atoi(optarg);
        break;
      case 'd':
        numDigits = atoi(optarg);
        break;
    } 
  }

  for (int n = 0; n < numValues; n++) {
    long result = benfordDigit();
  
    for (int d = 0; d < numDigits - 1; d++) {
      result = result * 10 + uniformDigit();
  }
  
  printf("%ld\n", result);

}
  
}
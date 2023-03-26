/**
 * Treblecross
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int n;
  printf("Plese enter the size of the gameboard: ");
  if (scanf("%d", &n) == 0) {
    printf("Failed to read integer. \n");
  } else if (n < 0) {
    exit(0);
  }

  char gameboard[n];

  for (int i = 0; i < n; i++) {
    gameboard[i] = 'o';
  }

  bool gamerun = true;
  int player = 1;

  while (gamerun == true) {

    for (int i = 0; i < n; i++) {
      if (i == 0) {
        printf("|%c|", gameboard[i]);
      } else {
        printf("%c|", gameboard[i]);
      }
    }

    int playerMove;

    printf("\nPlayer %d enter your postion: ", player);

    if (scanf("%d", &playerMove) == 1) {
      gameboard[playerMove - 1] = 'X';
    } else {
      printf("Failed to read integer.\n");
    }

    for (int i = 0; i < n; i++) {
      if (gameboard[i] == 'X' && gameboard[i + 1] == 'X' &&
          gameboard[i + 2] == 'X') {
        for (int i = 0; i < n; i++) {
          if (i == 0) {
            printf("|%c|", gameboard[i]);
          } else {
            printf("%c|", gameboard[i]);
          }
        }
        printf("\n");
        printf("Player %d Wins!", player);
        gamerun = false;
        break;
      }
    }

    if (player == 1) {
      player = 2;
    } else {
      player = 1;
    }
  }
  return 0;
}
// Demonstration of the crypt() function

// Compile this program using: 
//     gcc -Wall -o example example.c -lcrypt
//
// -lcrypt is required to link in the crypt library

#include <stdio.h>
#include <unistd.h>
#include <crypt.h>

int main() {
    
    char *key = "allergic";
    char *salt = "$1$";  // Always use "$1$" for the salt string
    char *hash = crypt(key, salt);

    char ch1[26];
    strcpy(ch1, hash);
    char check[26]  = ("$1$$JCsoZ55UHyLk22.lqSA2U0");
    int comp = strcmp(ch1, hash);
    printf("%d", comp);
    printf("%s\n", hash);
    
    return 0;
}
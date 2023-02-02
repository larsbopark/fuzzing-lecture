#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char output[32];
    char operation_buf[32];
    char input[64];

    printf("Welcome to the ROT13 coder/decoder!\n");
    printf("ROT13 is a simple substitution cipher.\n"
           "It is much like a ceasar cipher, where ROT13\n"
           "is a specific case. Try write some thing you \n"
           "want encoded. MAX 32 chars!\n\n");

    fgets(input, sizeof(input), stdin);

    strncpy(operation_buf, input, 32);

    for(int i = 0;i < strlen(operation_buf) - 1; i++){
        output[i] = ((((operation_buf[i] - 97) + 13) % 26) +97);
    }


    printf("Your string: %s\n", input);
    printf("Encoded: %s\n", output);
0
    return 0;
}



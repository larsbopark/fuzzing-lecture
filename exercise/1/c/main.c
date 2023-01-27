#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int nbOfChars = 0;
    char input_buffer[20];
    char output_buffer[20];

    printf("Enter Words:\n");
    fgets(input_buffer, sizeof(input_buffer), stdin); // Read 20 bytes to input_buffer

    printf("Enter number of chars to be kept:\n");
    scanf("%d", &nbOfChars); // Get number of chars

    strncpy(output_buffer, input_buffer,nbOfChars); // Write the number of chars to output_buffer

    printf("Original: %s\n", input_buffer); // print original
    printf("Result: %s\n",output_buffer); // print result


    if(strcmp(input_buffer, "FUZZing is bad")==0) abort(); // `abort()` crashes a program
    return 0;
}
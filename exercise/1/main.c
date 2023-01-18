#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int output = 0;
    char input_buffer[64];

    gets(input_buffer); // read stdin to `input_buffer`

    if(strcmp(input_buffer, "FUZZing is bad")==0) abort(); // `abort()` crashes a program

    printf("%s\n", input_buffer); // display input
    return output;
}
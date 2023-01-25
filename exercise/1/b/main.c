#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char input_buffer[20];

    scanf("%s", input_buffer); // read from stdin to `input_buffer`
    printf("%s\n", input_buffer); // display input


    if(strcmp(input_buffer, "FUZZing is bad")==0) abort(); // `abort()` crashes a program
    return 0;
}
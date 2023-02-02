#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printer(char *arg){
    printf("%s", arg);
}

int main() {
    void (*fun_ptr)(char *arg) = &printer; // Initialize a function pointer
    char buffer[42];

    scanf("%s",buffer); // Get input
    (*fun_ptr)(buffer); // Print input using the function pointer
    
    if(strcmp(buffer, "FUZZing is bad") == 0) abort();

    return 0;
}



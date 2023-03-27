#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


uint8_t tab[0x1ff + 1];

uint8_t check(int32_t value){
    int32_t i = value * 0x1ff / 0xffff;
    printf("tab[%d] looks safe because %d is between [0;%d[\n", i, i, (int) sizeof(tab));
    return tab[i];
}

// Stupid Hash Function
int32_t hash(char* str){
    int32_t hash = 1;
    int c;
    while ((c = *str++)){
        hash *=c;
    }
    return hash;
}

int main(){
    char buf[1024];
    int value;
    printf("Enter a word to access a tab: ");
    if (!fgets(buf, sizeof(buf),stdin)) return -1;
    value = hash(buf);

    return check(value);
}
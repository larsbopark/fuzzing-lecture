#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char tab[0x1ff + 1];

char f(int32_t x)
{
        int32_t i = x * 0x1ff / 0xffff;
        printf("tab[%d] looks safe because %d is between [0;%d[\n", i, i, (int) sizeof(tab));
        return tab[i];
}


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

    fgets(buf, sizeof(buf),stdin);
    value = hash(buf);

    printf("%d\n",value);
    printf("%c",f(value));

    return 0;

}
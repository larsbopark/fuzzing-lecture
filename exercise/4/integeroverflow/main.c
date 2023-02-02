#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t tab[0x1ff + 1];

uint8_t f(int32_t x)
{
        int32_t i = x * 0x1ff / 0xffff;
        printf("tab[%d] looks safe because %d is between [0;%d[\n", i, i, (int) sizeof(tab));
        return tab[i];
}

int main()
{
    int input;
    scanf("%d", &input);

    return f(input);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char shield[64] = {0};
    char buffer[8];

    // Read input
    scanf("%s", buffer);

    // Print input
    printf("buffer: %s\n", buffer);


    // Never going to execute this since the shield is never changed
    if(strlen(shield) > 0) {
        printf("shield: %s",shield);

        if(strcmp(shield, "FUZZing is bad")) abort();
    }

    return 0;
}

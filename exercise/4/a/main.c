#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

// This function handle inputs and ensure that the input is valid
// if not valid just return 0 and the application will exit
// without crashing
int process_input(char *buf){
    // TODO!!


    // I have already implemented the first check
    if (strcmp(buf, "FUZZing is bad") == 0){
        printf("Input is invalid!\n"
               "Exit gracefully!\n");
        return 0;
    }
    return 1;
}

void timer();

int main () {
    char buf[1024];
    printf("Welcome to the Mirror Application\n"
           "Show me something and I will reflect it back to you\n"
           ": ");
    fgets(buf, sizeof(buf), stdin);

    printf("Let me just process:\n");
    timer();

    // Check input
    if(!process_input(buf)) return 0;

    // ----------------------------------------------------------------
    // Asserts! Only for testing purposes, remove in release build!
    // ----------------------------------------------------------------
    assert((strlen(buf) >= 0));
    assert((strlen(buf) < 364));
    for (int i = 0; i < strlen(buf) - 1 ; i++){
        assert(isprint(buf[i]) != 0);
        assert(islower(buf[i]) != 0 || (buf[i] == ' '));
    }
    assert(strcmp(buf, "fuzzing is bad\n") != 0);
    // ----------------------------------------------------------------


    printf("Okay, i processed the input here it is:\n");
    printf("%.364s", buf);
    return 0;
}

// patience is a virtue
void timer(){
    printf(".\n");
    sleep(1);
    printf("..\n");
    sleep(1);
    printf("...\n");
}

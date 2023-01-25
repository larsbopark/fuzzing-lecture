#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Item {
    unsigned int index;
    char name[32];
    int price;
};

struct Item inventory[] = {
        {1, "Cola", 5},     {2, "Lemon", 5},        {3, "Beer", 8},     {4, "Water", 3},
        {5, "Chips", 2},    {6, "Gummy Bears", 2},  {7, "Lolipop", 1},  {8, "Cheese", 4},
        {9, "Banana", 1},   {10, "Orange", 2},      {11, "Apple", 2},   {0, "Test Item", -1},

};

void dots();
void listItems();
void purchase(unsigned int*, char*);

void dispense(struct Item*);

int main () {
    unsigned int balance = 10;
    char input_buffer[32];

    printf("Welcome to the Fuzztastic Vending Machine \n");

    while (1) {
        // Present the possible options
        printf("\n");
        printf("Here is your current balance: %i dkk\n", balance);
        printf("Press a number to continue:\n"
               "1. List items\n"
               "2. Purchase items\n"
               "3. Deposit currency\n"
               "4. Exit\n\n");

        // Get user input
        fgets(input_buffer, sizeof(input_buffer), stdin);

        switch (input_buffer[0]) {
            case 49: listItems(); break;
            case 50: purchase(&balance, input_buffer); break;
            case 51: printf("This is not implemented yet, please try again later\n\n"); break;
            case 52: return 1;
            default:
                printf("Not a valid option, try again\n");
        }

        if(strcmp(input_buffer, "FUZZing is bad")==0) abort();
    }
}

void listItems(){
    // Listing the inventory -- except Test Item
    for (int i = 0; i < 11; i++){
        struct Item item = inventory[i];
        printf("Index: %02i: %-12s  price: %2i dkk\n", item.index, item.name, item.price);
    }
}

void purchase(unsigned int* balance, char* input_buffer) {
    int new_balance;
    int index;
    char sub_buffer[8];

    // Checking if the user already supplied and ID
    if (strlen(input_buffer) < 3) {

        // If not prompt for one
        printf("Please enter the ID of the item you desire\n");
        fgets(sub_buffer, 3, stdin);
    } else {
        memcpy(sub_buffer, &input_buffer[2], sizeof(input_buffer));
    }


    // Converting the string to an integer
    index = atoi(sub_buffer);

    // Check if index is negative!
    if (index < 0) {
        printf("Please enter a valid positive index!");
    } else {
        // Check if the balance goes negative, if so cancel otherwise update balance
        new_balance = *balance - inventory[index-1].price;
        if (new_balance < 0) {
            printf("Not enough balance to purchase\n");
        } else {
            *balance = new_balance;
            dispense(&inventory[index-1]);
        }
    }

}


void dispense(struct Item* item){
    printf("Here you go! %s!\n", item->name);
}

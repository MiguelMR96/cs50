#include <stdio.h>

int main(void) 
{
    long card_number;
    int temp;
    int scanned;
    int digits;
    int single_digit[16];
    int product_digit[16];
    int splitted_product[16];

    // Print for user credit card number input
    printf("Number: ");
    scanned = scanf("%lu", &card_number);

    // Checks if the input entered by the user is a valid integer
    if (scanned == 0) {
        printf("Enter a valid number.\n");
        return 1;
    }

    // Counts the digits of the credit card's input
    temp = card_number;
    for (digits = 0; temp != 0; digits++) {
        temp /= 10;
    }

    // Checks that the lenght of the credit card's input is more than 10 digits long
    if (digits < 10) {
        printf("Enter a valid number without hyphens or special characters.\n");
        return 1;
    }

    card_number /= 10;
    for (int i = 0; i < 17; i++) {
        single_digit[i] = card_number % 10;
        product_digit[i] = single_digit[i] * 2;
        if (product_digit[i] > 0) {
            for (int j = 0; product_digit[i] > 0; j++) {
                splitted_product[j] = product_digit[j] % 10;
                product_digit[i] /= 10;
                printf("splitted_product value is: %d\n", splitted_product[j]);
            }
        }
        card_number /= 100;
        printf("product_digit value is: %d\n", product_digit[i]);
    }

    for (int i = 0; i > 16; i++) {
        if (product_digit[i] > 0) {
            for (int j = 0; product_digit[j] > 0; j++) {
                splitted_product[j] = product_digit[j] % 10;
                product_digit[j] /= 10;
                printf("splitted_product value is: %d\n", splitted_product[j]);
            }
        }
        printf("Not entering here");
    }
    return 0;
}
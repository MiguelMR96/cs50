#include <stdio.h>
#include <stdbool.h>

int sum_card_numbers(int digit);

int main(void) 
{
    long card_number;
    long temp;
    long temp_card;
    int scanned;
    int digits;
    int digit;
    bool other_digit = false;
    int sum = 0;
    int other_sum = 0;
    int total = 0;

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
    for (digits = 0; temp > 0; digits++) {
        temp /= 10;
    }

    // Checks that the lenght of the credit card's input is more than 10 digits long
    if (digits < 10) {
        printf("Enter a valid number without hyphens or special characters.\n");
        return 1;
    }

    temp_card = card_number;
    while (temp_card > 0) {
        if (other_digit == true) {
            digit = temp_card % 10;
            temp = sum_card_numbers(digit);
            sum += temp;
        } else {
            other_sum += temp_card % 10;
        }
        temp_card /= 10;
        other_digit = !other_digit;
    }
    total = sum + other_sum;
    if (total % 10 == 0) {
        if (digits == 16) {
            int first_two_digits = card_number / 100000000000000;
            if (first_two_digits / 10 == 4) {
                printf("VISA\n");
            } else if (first_two_digits < 56 || first_two_digits > 50) {
                printf("MASTERCARD\n");
            }
        } else if (digits == 13) {
            printf("VISA\n");
        } else if (digits == 15) {
            printf("AMEX\n");
        }
    } else {
        printf("INVALID\n");
    }

    return 0;
}

int sum_card_numbers(int digit) {
    int sum = 0;
    int number;

    digit *= 2;

    while (digit > 0) {
        number = digit % 10;
        sum += number;
        digit /= 10;
    }

    return sum;
}
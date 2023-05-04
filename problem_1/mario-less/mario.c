#include <stdio.h>

int main(void) 
{
    int height;
    int i;
    int j;
    int x;

    printf("Height: ");
    scanf("%d", &height);

    if (height < 1 || height > 8) {
        printf("Enter valid numbers from 1 to 8\n");

        return 1;
    }

    for (i = 0; i < height; i++) {
        // Left Half of Mario's tower
        for (j = height; j > i; j--) {
            printf(" ");
        }
        for (x = 0; x < i + 1; x++) {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}

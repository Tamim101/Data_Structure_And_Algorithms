#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    char *symbols[] = {
        "M", "CM", "D", "CD", "C", "XC",
        "L", "XL", "X", "IX", "V", "IV", "I"
    };
    int values[] = {
        1000, 900, 500, 400, 100, 90,
        50, 40, 10, 9, 5, 4, 1
    };

    char *result = malloc(32 * sizeof(char));  // safer size
    result[0] = '\0'; // Initialize as empty string

    for (int i = 0; i < 13 && num > 0; i++) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }

    return result;
}

int main() {
    int number = 3749;

    char* roman = intToRoman(number);
    printf("Input: %d\n", number);
    printf("Output: %s\n", roman);

    free(roman);
    return 0;
}

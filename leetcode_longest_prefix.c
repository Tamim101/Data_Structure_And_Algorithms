#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compare function for qsort
int cmp(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// Function to find longest common prefix
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    qsort(strs, strsSize, sizeof(char*), cmp);

    char* first = strs[0];
    char* last = strs[strsSize - 1];

    int i = 0;
    while (first[i] && last[i] && first[i] == last[i]) {
        i++;
    }

    char* result = (char*)malloc(i + 1);
    strncpy(result, first, i);
    result[i] = '\0';

    return result;
}

int main() {
    int strsSize;
    printf("Enter number of strings: ");
    scanf("%d", &strsSize);
    getchar(); // flush newline

    char* strs[100]; // up to 100 strings

    for (int i = 0; i < strsSize; i++) {
        char buffer[100];
        printf("Enter string %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);

        // remove newline
        buffer[strcspn(buffer, "\n")] = '\0';

        // allocate memory and copy string
        strs[i] = (char*)malloc(strlen(buffer) + 1);
        strcpy(strs[i], buffer);
    }

    char* prefix = longestCommonPrefix(strs, strsSize);
    printf("Longest Common Prefix: %s\n", prefix);

    // Free allocated memory
    free(prefix);
    for (int i = 0; i < strsSize; i++) {
        free(strs[i]);
    }

    return 0;
}

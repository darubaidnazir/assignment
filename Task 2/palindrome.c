#include <stdio.h>
#include <string.h>

int isPalindrome(char* str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

char* longestPalindrome(char* str) {
    int n = strlen(str);
    int maxLength = 1;
    int start = 0;


    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isPalindrome(str, i, j) && j - i + 1 > maxLength) {
                maxLength = j - i + 1;
                start = i;
            }
        }
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isPalindrome(str, i, j) && j - i + 1 > maxLength) {
                maxLength = j - i + 1;
                start = i;
            }
        }
    }

    char* palindrome = (char*)malloc(maxLength + 1);
    for (int i = 0; i < maxLength; i++) {
        palindrome[i] = str[start + i];
    }
    palindrome[maxLength] = '\0';

    return palindrome;
}

int main() {
    char str[] = "cbbd";
    char* palindrome = longestPalindrome(str);
    printf("Longest palindrome: %s\n", palindrome);
    free(palindrome);
    return 0;
}

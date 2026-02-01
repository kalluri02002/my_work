#include <stdio.h>
#include <ctype.h>

int main() {
    int charCount = 0, lineCount = 0, wordCount = 0;
    int inWord = 0; // Flag to track if we're inside a word
    char ch;

    printf("Enter text (press Ctrl+D to stop on Linux, Ctrl+Z on Windows):\n");

    while ((ch = getchar()) != EOF) {
        charCount++;

        if (ch == '\n') {
            lineCount++;
        }

        if (isspace(ch)) {
            if (inWord) {
                inWord = 0; // End of a word
                wordCount++;
            }
        } else {
            inWord = 1; // Inside a word
        }
    }

    // If the last character is part of a word
    if (inWord) {
        wordCount++;
    }

    printf("Character count : %d\n", charCount);
    printf("Line count : %d\n", lineCount);
    printf("Word count : %d\n", wordCount);

    return 0;
}

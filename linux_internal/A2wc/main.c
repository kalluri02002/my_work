#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

void count_wc(FILE *fp, int *line_count, int *word_count, int *char_count) {
    char ch;
    int in_word = 0;
    
    *line_count = *word_count = *char_count = 0;
    
    while ((ch = fgetc(fp)) != EOF) {
        (*char_count)++;

        if (ch == '\n')
            (*line_count)++;

        if (isspace(ch))
            in_word = 0;
        else if (!in_word) {
            in_word = 1;
            (*word_count)++;
        }
    }
}

int main(int argc, char *argv[]) {
    int l_flag = 0, w_flag = 0, c_flag = 0;
    char ch;
    
    while ((ch = getopt(argc, argv, "lwc")) != -1) {
        switch (ch) {
            case 'l': l_flag = 1; break;
            case 'w': w_flag = 1; break;
            case 'c': c_flag = 1; break;
            default:
                fprintf(stderr, "Usage: %s [-l] [-w] [-c] [file...]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (!(l_flag || w_flag || c_flag)) {  // If no option is provided, enable all options by default
        l_flag = w_flag = c_flag = 1;
    }

    int total_lines = 0, total_words = 0, total_chars = 0;
    int file_count = 0;

    if (optind >= argc) {  // No files provided, read from standard input
        int lines, words, chars;
        count_wc(stdin, &lines, &words, &chars);
        
        printf("Lines: %d, Words: %d, Characters: %d (stdin)\n", lines, words, chars);
    } else {
        for (int i = optind; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                perror(argv[i]);
                continue;
            }
            
            int lines, words, chars;
            count_wc(fp, &lines, &words, &chars);
            fclose(fp);

            printf("Lines: %d, Words: %d, Characters: %d %s\n", lines, words, chars, argv[i]);

            total_lines += lines;
            total_words += words;
            total_chars += chars;
            file_count++;
        }

        if (file_count > 1) {  // Display total count if multiple files are provided
            printf("Lines: %d, Words: %d, Characters: %d total\n", total_lines, total_words, total_chars);
        }
    }

    return 0;
}


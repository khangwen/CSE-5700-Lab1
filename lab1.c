// CSE-5700 Lab 1
// Alan Nguyen

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Driver code
int main()
{
    // variables
    char var[1000];
    int char_count = 0;
    int ws_count = 0; // white space count
    int line_count = 0;
    int white_space = 0;
    bool prev_space_white = false;
    FILE *text;

    // scan to  file
    text = fopen("/test.txt", "w+");
    fprintf(text, "My name is Alan Nguyen.    \nI love Computer Science.");
    fclose(text);

    // open file and make counts
    text = fopen("/test.txt", "r");
    while (fgets(var, 1000, (FILE *)text))
    {
        for (int i = 0; i < strlen(var); i++)
            char_count++; // includes white spaces

        for (int i = 0; i < strlen(var); i++)
        {
            white_space = isspace(var[i]);
            if (white_space != 0) // check if white space
            {
                if (!prev_space_white)
                {
                    ws_count++;
                    prev_space_white = true;
                }
            }
            else
                prev_space_white = false;
        }
        line_count++;
    }

    // print statements
    printf("Number of characters: %d\n", char_count);
    printf("Number of words: %d\n", ws_count + 1); // initially 1 word -> new white space -> another word
    printf("Number of lines: %d\n", line_count);

    return 0;
}
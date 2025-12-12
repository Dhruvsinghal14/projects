#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    char text_prompt[1000];

    printf("Enter text for evaluation: ");
    fgets(text_prompt, sizeof(text_prompt), stdin);

    int total_length = strlen(text_prompt);

    int letter_count = 0;
    int word_count = 1;
    int sentence_count = 0;

    for (int n = 0; n < total_length; n++)
    {
        if (isalpha(text_prompt[n]))
        {
            letter_count++;
        }
        if (isspace(text_prompt[n]))
        {
            word_count++;
        }
        if (text_prompt[n] == '!' || text_prompt[n] == '?' || text_prompt[n] == '.')
        {
            sentence_count++;
        }
    }

    float L = (100.0 * letter_count) / word_count;
    float S = (100.0 * sentence_count) / word_count;
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    if (index > 16)
        printf("Grade 16+\n");
    else if (index < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %d\n", index);

    return 0;
}

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scramble_text(char *plaintext, int key);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    char plaintext[1000];
    printf("Plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    scramble_text(plaintext, key);

    printf("Ciphertext: %s\n", plaintext);

    return 0;
}

void scramble_text(char *plaintext, int key)
{
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            plaintext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        }
    }
}

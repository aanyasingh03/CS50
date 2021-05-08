#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!(isdigit(argv[1][i])))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }

    string plaintext = get_string("plaintext: ");

    int key = atoi(argv[1]);

    string ciphertext = "";

    printf("ciphertext: ");

    for (int j = 0, k= strlen(plaintext); j < k; j++)
    {
        if (isalpha(plaintext[j]) && isupper(plaintext[j]))
        {
            printf("%c", ((((plaintext[j]-65) + key) % 26) + 65));
        }

        else if (isalpha(plaintext[j]) && islower(plaintext[j]))
        {
            printf("%c", ((((plaintext[j]-97 + key) % 26) + 97)));
        }

        else
        {
            printf("%c", plaintext[j]);
        }

    }

    printf(" \n");
}

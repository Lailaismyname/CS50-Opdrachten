//this is a program that creates simple encryption. 
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //verklaar integers
    string key = argv[1];

    //checked of er niet meer dan 1 cli arg is.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //print error als key geen getal is
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Fatal error invalid key\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext:  \n");

    int k = atoi(key);
    printf("ciphertext:  ");
    //print de ciphertext per letter uit.
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            //printf("%c", (((plaintext[i] - 65) + k) % 26) + 65);
            printf("%c", (((plaintext[i] - 'A') + k) % 26) + 'A');
        }
        else if (islower(plaintext[i]))
        {
            //printf("%c", (((plaintext[i] - 97) + k) % 26) + 97);
            printf("%c", (((plaintext[i] - 'a') + k) % 26) + 'a');
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

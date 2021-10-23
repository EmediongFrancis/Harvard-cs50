#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>


/**
 *
 * Program to encrypt plaintext to Caesar's cyphertext.
 *
 **/

int main(int argc, string argv[])
{

    // check that cl args are 2.
    if (argc != 2)
    {
        printf("Please provide one argument\n.");
        return 1;
        exit(1);
    }
    else
    {
        // check if argumnt is digit.
        string key = argv[1];
         for (int j = 0; j < strlen(key); j++)
            if (isdigit(key[j]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
                exit(1);
            }
            else
            {
                // convert argument to integer.
                int myKey = atoi(key);
                // get plaintext from user.
                string plaintext = get_string("Plaintext: ");
                // convert plaintext to cipher.
                 for (int i = 0; i < strlen(plaintext); i++)
        {
            if (isupper(plaintext[i]))
            {
                plaintext[i] = (plaintext[i] - 65);
                plaintext[i] = (plaintext[i] + myKey) % 26;
                plaintext[i] = (plaintext[i] + 65);
            }
            if (islower(plaintext[i]))
            {
                plaintext[i] = (plaintext[i] - 97);
                plaintext[i] = (plaintext[i] + myKey) % 26;
                plaintext[i] = (plaintext[i] + 97);
            }
            if (isalpha(plaintext[i]) == 0)
            {
                plaintext[i] = plaintext[i];
            }
        }
        printf("ciphertext: %s", plaintext);
        printf("\n");
            }
    }
}

#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

/**
 *
 * Program to encrypt sentences via substitution provided by user as key.
 *
 **/

 int main (int argc, string argv[])
 {
     const int N = 26;
     const string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     int i, j, n, k, l, m;
     int letters[N];

     // check that two arguments were provided.
     if (argc != 2)
     {
         printf("Provide one command line argument.\n");
         return 1;
     }
        else
       {
         // check that key is exactly 26 characters long.
         string key = argv[1];
         if (strlen(key) != N)
         {
             printf("Enter exactly 26 characters.\n");
             return 1;
         }
         // check that key contains just alphabets.
         else
         {
             for (i = 0, n = strlen(key); i < n; i++)
             {
                 if (!((key[i] >= 'a' && key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z')))
             {
                printf("Key must contain only letters.\n");
                return 1;
             }
             // convert key to uppercase.
             else if (key[i] >= 'a' && key[i] <= 'z')
             {
                key[i] = toupper(key[i]);
             }
             // check for repeated letters.
             for (j = 0; j < N; j++)
            {
                if (key[i] == letters[j])
                {
                    printf("Key must not contain repeated letters.\n");
                    return 1;
                }
            }
                letters[i] = key[i];
             }

             // get plaintext from user.
             string plaintext = get_string("plaintext: ");
             int p = strlen(plaintext);
             char ciphertext[p + 1];


             // convert plaintext to ciphertext.
             for (k = 0; k < p; k++)
            {
                // Check if uppercase.
                if (isupper(plaintext[k]) != 0)
                {
                    for (l = 0; l < N; l++)
                    {
                        if (plaintext[k] == alphabets[l])
                        {
                            ciphertext[k] = key[l];
                            break;
                        }
                    }
                }
                // check if lowercase.
                else if (islower(plaintext[k]) != 0)
                {
                    for (m = 0; m < strlen(alphabets); m++)
                    {
                        if (plaintext[k] == tolower(alphabets[m]))
                        {
                            ciphertext[k] = tolower(key[m]);
                            break;
                        }
                    }
                }
                else
                {
                    ciphertext[k] = plaintext[k];
                }
             }
             // add null char to make it a string.
            ciphertext[p] = '\0';

            // print result and exit.
            printf("ciphertext: %s\n", ciphertext);
            return 0;
        }
    }
 }
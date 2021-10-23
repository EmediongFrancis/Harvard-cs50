#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>


int main(void)
{
    // declare variables
    int i, j, k, t, u, v;

    // get text from user.
    string text = get_string("Text: ");

    // count number of letters
    float letter_count = 0;
    for (i = 0, t = strlen(text); i < t; i++)
    if ((text[i] >= 97 && text[i] <= 122) || (text[i] >= 65 && text[i] <= 90))
    {
        letter_count++;
    }

    // count number of words
    float word_count = 1;
    for (j = 0, u = strlen(text); j < u; j++)
    if (text[j] == 32)
    {
        word_count++;
    }
    //count number of sentences based on termianal punctuations.
    float sentence_count = 0;
    for (k = 0, v = strlen(text); k < v; k++)
    if (text[k] == 46 || text[k] == 33 || text[k] == 63)
    {
        sentence_count++;
    }

    // compute avg letters and sentences per 100 words
    float L = 100 * (letter_count / word_count);
    float S = 100 * (sentence_count / word_count);

    // calculating coleman-lieu index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // print result
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

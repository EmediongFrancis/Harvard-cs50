#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int lines, hashes, height, spaces, opphash;
    // get height from user
    do
    {
        height = get_int("Input height: ");
    }
    while (height < 1 || height > 8);
    //printf("%i\n", height);

// make lines
    for (lines = 0; lines < height; lines++)
    {
        // make spaces
        for (spaces = height - lines; spaces > 1; spaces--)
        {
            printf(" ");
        }
        // make hashes
        for (hashes = 0; hashes <= lines; hashes++)
        {
            printf("#");
        }
        //make space in-between pyramid halves
        printf("  ");
        // make opposite hashes
        for (opphash = 0; opphash <= lines; opphash++)
        {
            printf("#");
        }
        printf("\n");
    }
}
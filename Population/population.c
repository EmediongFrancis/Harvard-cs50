#include <stdio.h>
#include <cs50.h>

// get_int: receives integer input from user
int main()
{
    // TODO: Prompt for start size
    int startsize, endsize, numyears;
    numyears = 0;
    do
    {
        
        startsize = get_int ("Enter start size: ");
    }
    while (startsize < 9);
    printf("Start size: %i\n", startsize);

    // TODO: Prompt for end size
    do
    {
        endsize = get_int ("Enter end size: ");
    }
    while (endsize < startsize);
    printf("End size: %i\n", endsize);

    // TODO: Calculate number of years until we reach threshold
    while (startsize < endsize)
    {
    startsize = startsize + (startsize / 3) - (startsize / 4);
     numyears++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", numyears);
    return (0);
}
#include <stdio.h>
#include <cs50.h>
#include <math.h>

// become a cashier.

int main(void)
{
    int denom[4] = {25, 10, 5, 1}; int coins = 0; int i; int cents;
    // get dollars.
    float dollars;
    do
    {
      dollars =  get_float("How much change? ");

    }
    while(dollars < 0);
    // convert dollar to cents

   cents = round(dollars * 100);

    //start making change
    for(i = 0; i < 4; i++)
    {
   while (cents >= denom[i])
   {
       coins += cents / denom[i];
       cents %= denom[i];
   }
    }
   {
   printf("%i\n", coins);
}
}
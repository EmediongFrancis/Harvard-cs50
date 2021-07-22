#include <stdio.h>
#include <cs50.h>

// program to check if credit card number is valid or invalid
// and print the card type if valid using Luhn's algorithm.

int main(void)
{
    // get card number from user.

    long cardNumber;
    do
    {
        cardNumber = get_long("Input card number: ");
    }
    while (cardNumber < 1);

    // get length of card number.

    int count = 0;
    long numLength = cardNumber;
    do
    {
        count++;
        numLength = numLength / 10;

    }
    while (numLength > 0);

    // check length.

    if (count == 13 || count == 15 || count == 16 || count == 18)
    {
       // calculate checksum.

        long checkSum = cardNumber;
        int ext1 = 0;
        int mul, preExt, a, b;
        int ext2 = 0;
        do
       {
           // extract last digit and update automatically.

            ext1 = ext1 + checkSum % 10;

            // update checkSum.

            checkSum = checkSum / 10;

            // extract second-to-last digit, multiply by 2,
            // break apart, add, and update.

           preExt = checkSum % 10;
            preExt = preExt * 2;
            a = preExt % 10;
            b = preExt / 10;
            ext2 = ext2 + a + b;

           // update checksum for next iteration.

            checkSum = checkSum / 10;
       }
       while (checkSum > 0);

        // add extractions.

        int checkSumTotal = ext1 + ext2;

       // validate checksum.

        if (checkSumTotal % 10 != 0)
        {
           printf("INVALID\n");
        }
       else
       {
            long cBrand = cardNumber;
            do
            {
               cBrand = cBrand / 10;
            }
            while(cBrand > 99);

            // print card brand.

            if (cBrand == 51 || cBrand == 52 || cBrand == 53 || cBrand == 54 || cBrand == 55)
           {
               printf("MASTERCARD\n");
           }
            else if(cBrand == 34 || cBrand == 37)
            {
               printf("AMEX\n");
            }
            else if(cBrand / 10 == 4)
           {
               printf("VISA\n");
           }
           else if (cBrand == 50)
           {
               printf("VERVE\n");
           }
           else
           {
               printf("INVALID\n");
           }
       }
    }
    else
   {
        printf("INVALID\n");
   }
}
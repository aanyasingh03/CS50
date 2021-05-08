#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Get user's input
    long number = get_long("Number: ");

    int length = 0;
    long cc = number;

    //Calculate length
    do
    {
        cc = cc/10;
        length++;

    }
    while (cc > 0);

    //Check if length is valid
    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    //Calculate CheckSum
    int sum1 = 0;
    int sum2 = 0;
    long x = number;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;

    do
    {
        //Remove last digits and add to sum1
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;

        //Remove second last digit
        mod2 = x % 10;
        x = x / 10;

        //Double second last digit and add digits to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 /10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);

    total = sum1 + sum2;

    //Checking Luhn's Algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //Get Starting 2 digits
    long start = number;
    do
    {
        start = start/10;
    }
    while (start > 100);

    //Checking for mastercard 51,52,52,54,55
    if ((start/10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }

    //Checking for AMEX; 34 or 37
    else if ((start/10 == 3) && (start%10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }

    //Checking for Visa; 4
    else if (start/10 == 4)
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}


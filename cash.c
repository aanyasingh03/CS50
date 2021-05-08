#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float change = 0.0;
    float quarter = 0.25;
    float dime = 0.10;
    float nickel = 0.05;
    float penny = 0.01;
    int coins = 0;

    do
    {
        change = get_float("Change owed: ");
    }
    while (change <= 0);

    if (change >= quarter)
    {
        do
        {
            change = (change - quarter);
            coins++;
        }
        while (change >= quarter);
    }

    printf("%f\n", change);

    if (change >= dime)
    {
        do
        {
            change = (change - dime);
            coins++;
        }
        while (change >= dime);
    }

    printf("%f\n", change);

    if ( change >= nickel)
    {
        do
        {
            change = (change - nickel);
            coins++;
        }
        while (change >= nickel);

    }
    printf("%f\n", change);

    if (change > 0)
    {
        do
        {
            change = (change - penny);
            coins++;
        }
        while (change > 0);


    }

    printf("%f\n", change);

    printf("%i\n", coins);
}

#include<math.h>
#include<cs50.h>
#include<stdio.h>
int main(void)
{
    float dollars;                                       // Declaration of variable
    int cents, remain = 0, i = 0, j = 0, k = 0, l = 0;   // Declaration of variables

    // Take cash as input from the user
    do
    {
        dollars = get_float("Change owed: ");

    }
    while ((dollars < 0));

    // Convert dollars to cents
    cents = round(dollars * 100);

    //Check number of 25 cents required for the change
    if (cents != 0)
    {
        do
        {
            cents = cents - (remain * 25);
            remain = cents / 25;
            i = remain + i;
        }
        while (remain != 0);
    }

    remain = 0;

    //Check number of 10 cents required for the change
    if (cents != 0)
    {
        do
        {
            cents = cents - (remain * 10);
            remain = cents / 10;
            j = remain + j;
        }
        while (remain != 0);
    }

    remain = 0;

    //Check number of 5 cents required for the change
    if (cents != 0)
    {
        do
        {
            cents = cents - (remain * 5);
            remain = cents / 5;
            k = remain + k;
        }
        while (remain != 0);
    }

    remain = 0;

    //Check number of 1 cents required for the change
    if (cents != 0)
    {
        do
        {
            cents = cents - (remain * 1);
            remain = cents / 1;
            l = remain + l;
        }
        while (remain != 0);
    }

    // Total number of possible denominations of all four types of cents
    printf("%d\n", i + j + k + l);

}
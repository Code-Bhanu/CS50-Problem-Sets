#include<math.h>
#include<cs50.h>
#include<stdio.h>
int main(void)
{
    int i = 1, valid = 0, first_sum = 0, product_sum = 0, last_digit = 0, two_digit = 0;  // Declaration of variables
    long int number = 0, card = 0; // Declaration of credit card variables
    number = get_long("Number: ");
    card = number;
    //checksum calculation
    do
    {
        if (i % 2  != 0)
        {
            first_sum = first_sum + (number % 10);
            number = number / 10 ;
        }
        else
        {
            last_digit = number % 10;
            number = number / 10;
            last_digit = last_digit * 2;
            // In case of a two digit number , add two of its digits
            if (last_digit / 10 != 0)
            {
                two_digit = last_digit % 10;
                two_digit = two_digit + ((last_digit) / 10);
                product_sum = product_sum + two_digit;
            }
            else
            {
                product_sum = product_sum + last_digit;
            }
        }
        i++;
    }
    while (number != 0);

    // Find the total checksum
    int total = first_sum + product_sum ;
    // Checksum validity check
    if (total % 10 == 0)
    {
        valid = 1;
    }
    else
    {
        valid = 0;
    }

    if (valid == 1)
    {
        //Check type of card
        switch (i - 1)
        {
            case 15 :  // American express card validation
                card = card / (pow(10, 13));
                if ((card == 34) || (card == 37))
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 16 : // Master card validation
                card = card / (pow(10, 14));
                if ((card == 51) || (card == 52) || (card == 53) || (card == 54) || (card == 55))
                {
                    printf("MASTERCARD\n");
                }
                else if (card / 10 == 4)   // Visa card validation
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 13 :
                card = card / (pow(10, 12));
                if (card == 4)  // Visa card validation
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            default:
                printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

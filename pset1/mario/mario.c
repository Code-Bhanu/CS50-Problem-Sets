#include<cs50.h>
#include<stdio.h>
int main(void)
{
    int height, i, j, k, l; // Declaration of variables
    // Take height as input from the user
    do
    {
        height = get_int("Height: ");
    }
    while ((height < 1) || (height > 8));

    l = height;

    //i indicates the number of rows
    for (i = 0; i < height; i++)
    {
        //k indicates the number of spaces in each row
        for (k = l - 1; k > 0; k--)
        {
            printf(" ");
        }

        //j indicates the number of left hashes in each row
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

        //this j indicates the number of right hashes in each row
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
        l--;
    }
}
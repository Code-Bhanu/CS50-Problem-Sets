#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start, end, num = 0, i = 0;
    // TODO: Prompt for start size
    do
    {
        start = get_int("Start size:");

    }
    while ((start < 1) || (start < 9));

    // TODO: Prompt for end size
    do
    {
        end = get_int("End size:");

    }
    while ((end < 1) || (end < start));

    // TODO: Calculate number of years until we reach threshold

    num = start;
    while (end > num)
    {
        num = num + (num / 3) - (num / 4);
        i++;
    }

    // TODO: Print number of years
    printf("Years: %i", i);
}
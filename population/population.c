#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start, end, n = 0;

    // TODO: Prompt for start size
    do
    {
        start = get_int("Start size of population: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    do
    {
        end = get_int("End size of population: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        n++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", n);
}

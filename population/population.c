#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for start size. Note the starting size needs to be >= 9
    int startSize;
    do
    {
        startSize = get_int("Start Size (must be greater than 9): ");
    }
    while (startSize < 9);

    // TODO: Prompt for end size. Note: end population must be > startSize
    int endSize;
    do
    {
        endSize = get_int("End Size (must be greater than start size): ");
    }
    while (endSize < startSize);

    // Calculates number of years until we reach threshold (+ n/3, - n/4 (truncated) per year)
    int years = 0;
    int n = startSize;
    while (n < endSize)
    {
        n = n + trunc(n / 3) - trunc(n / 4);
        years++;
    }

    // Prints number of years
    printf("Years: %i\n", years);
}

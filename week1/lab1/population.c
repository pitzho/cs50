#include <cs50.h>
#include <stdio.h>

int get_start_size(void);
int get_end_size(int x);
int calc_years(int x, int y);

int main(void)
{
    // Each year, n / 3 new llamas are born,
    // n / 4 llamas pass away.

    // Prompt for start size
    int x = get_start_size();

    // Prompt for end size
    int y = get_end_size(x);

    // Calculate number of years until we reach threshold
    int n = calc_years(x, y);

    // Print number of years
    printf("Years: %i\n", n);
}

int get_start_size(void)
{
    int x;
    do
    {
        x = get_int("Start size: ");
    }
    while (x < 9);
    return x;
}

int get_end_size(int x)
{
    int y;
    do
    {
        y = get_int("End size: ");
    }
    while (y < x);
    return y;
}

int calc_years(int x, int y)
{
    int n = 0;
    if (x == y)
    {
        return n;
    }
    else
    {
        do
        {
            x += x / 12;
            n++;
        }
        while (x < y);
        return n;
    }
}
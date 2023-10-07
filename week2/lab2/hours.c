#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char func);

int main(void)
{
    // User's input of weeks
    int weeks = get_int("Number of weeks taking CS50: ");
   
    // User's input of hours on each week
    int hours[weeks];
    for (int i = 0; i < weeks; i++)
    {
        do
        {
            hours[i] = get_int("Hours taken on week %i: ", i);
        } while (hours[i] < 0);
    }
        
    // Prompt for an Average or Total hours
    char func;
    do
    {
        func = get_char("Enter T for total hours or A for average: ");
        func = tolower(func);
    }
    while (func != 'a' && func != 't');

    // Print number of hours
    printf("%.1f hours\n", calc_hours(hours, weeks, func));
}

float calc_hours(int hours[], int weeks, char func)
{
    float total_hours = 0;
    for (int i = 0; i < weeks; i++)
    {
        total_hours += hours[i];
    }
    
    if (func == 't')
    {
        return total_hours;
    }
    else if (func == 'a')
    {
        float average = total_hours / weeks;
        return average;
    }
    return 0;
}
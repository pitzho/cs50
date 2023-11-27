#include <cs50.h>
#include <stdio.h>

int factorial(int number);

int main(void)
{
    // Prompt the user for a number
    int n = get_int("Enter the number: ");
    
    // Print output
    printf("%i\n", factorial(n));

    return 0;
}

int factorial(int number)
{
    if (number == 1)
    {
        return 1;
    }
    
    return number * factorial(number - 1);
}

// or get rid of curly braces!

// int factorial(int number)
// {
//     if (number == 1)
//          return 1;
//     else
//          return number * factorial(number - 1);
// }
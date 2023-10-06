#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for a size of an array.
    int size;
    do
    {
        size = get_int("Size of array: ");
    } while (size < 1);
    
    // Dynamically create the array of that size,
    // where each element is 2 times the previous one.
    // Start the array at 1.
    int array[size];
    array[0] = 1;
    for (int i = 1; i < size; i++)
    {
        array[i] = array[i - 1] * 2;
    }
    
    // Print the array, integer by integer.
    for (int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
    return 0;
}
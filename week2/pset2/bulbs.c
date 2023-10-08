#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Prompt for user input
    string message = get_string("Message: ");

    // Converts string into a series of 8-bit binary numbers, one for each character of the string.
    
    // Convert each char of string into int
    int len = strlen(message);
    int chars_as_int[len];
    for (int i = 0; i < len; i++)
    {
        chars_as_int[i] = message[i]; // String to int in ASCII
    }

    // Now we have an array with int for every char in string
    int switcher[] = {0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < len; i++) // To all array of chars_as_int[]
    {
        // Tuning switcher
        for (int j = 0; j < 8; j++) 
        {
            if (chars_as_int[i] == 1)
            {
                switcher[7 - j] = 1;
                break;
            }
            else if (chars_as_int[i] % 2 == 0)
            {
                switcher[7 - j] = 0;
                chars_as_int[i] /= 2;
            }
            else if (chars_as_int[i] % 2 == 1)
            {
                switcher[7 - j] = 1;
                chars_as_int[i] /= 2;
            }
        }

        // Print bulbs
        for (int x = 0; x < 8; x++)
        {
            print_bulb(switcher[x]);
        }
        
        printf("\n");

        // Reset switcher
        for (int y = 0; y < 8; y++)
        {
            switcher[y] = 0;
        }
    }
    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
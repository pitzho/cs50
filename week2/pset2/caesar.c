#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Check if key  consists of only digits
bool only_digits(string key);
// Function to rotate a char
char rotate(char letter, int key);

int main(int argc, string argv[])
{
    // Program accept single non-negative int arg
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if argv is an integer
    bool check = only_digits(argv[1]);
    if (!(check))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert key from string to integer
    int key = atoi(argv[1]);

    // Get plaintext for conversion
    string plaintext = get_string("plaintext:  ");
    char cipher_char;

    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        cipher_char = rotate(plaintext[i], key);
        printf("%c", cipher_char);
    }
    printf("\n");

    return 0;
}

bool only_digits(string key)
{
    // Key is a string, and it's just an array of chars
    // This function checks if key consists only of digits
    bool output = true;
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!(isdigit(key[i])))
        {
            output = false;
        }
    }
    return output;
}

char rotate(char letter, int key)
{
    char new_letter;
    if (letter >= 65 && letter <= 90)
    {
        // A to Z
        if (letter + (key % 26) > 90)
        {
            new_letter = letter + (key % 26) - 26;
        }
        else
        {
            new_letter = letter + (key % 26);
        }
    }
    else if (letter >= 97 && letter <= 122)
    {
        // a to z
        if (letter + (key % 26) > 122)
        {
            new_letter = letter + (key % 26) - 26;
        }
        else
        {
            new_letter = letter + (key % 26);
        }
    }
    else
    {
        new_letter = letter;
    }
    return new_letter;
}
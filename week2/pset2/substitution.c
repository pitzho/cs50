#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Check if key consists of only chars
bool only_chars(string key);

// Check if key contains every char only once
bool only_once(string key);

// Function for char substitution
char char_substitution(string key, char letter);

int main(int argc, string argv[])
{
    string key = argv[1];
    
    // Check if only one argument
    if (!(argc == 2))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    // Check if key contains 26 chars
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    
    // Check if key contains only chars
    bool check_chars = only_chars(key);
    if (!(check_chars))
    {
        printf("Key must contain only characters.\n");
        return 1;
    }
    
    // Check if key contains every char only once  
    bool check_once = only_once(key);
    if (!(check_once))
    {
        printf("Key must contain every character only once.\n");
        return 1;
    } 
    
    // Prompt for plaintext
    string plaintext = get_string("plaintext:  ");
    
    // Output ciphertext
    printf("ciphertext: ");    
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        printf("%c", char_substitution(key, plaintext[i]));
    }
    printf("\n");
    return 0;
}

bool only_chars(string key)
{
    bool output = true;
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!(isalpha(key[i])))
        {
            output = false;
            break;
        }
    }
    return output;
}

bool only_once(string key)
{
    int len = strlen(key);
    int count;
    for (int i = 0; i < len; i++)
    {
        count = 0;
        for (int j = 0; j < len; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                count++;
            }
        }
        if (count > 1)
        {
            return false;
        }
    }
    return true;    
}

char char_substitution(string key, char letter) 
{
    char new_letter;
    // A to Z
    if (letter >= 65 && letter <= 90)
    {
        new_letter = toupper(key[letter - 65]);
    }
    // a to z
    else if (letter >= 97 && letter <= 122)
    {
        new_letter = tolower(key[letter - 97]);
    }
    // Don't change non-alphabetical characters
    else
    {
        new_letter = letter;
    }
    
    return new_letter;
}
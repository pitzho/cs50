#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    // Check if only one string as argument to main
    if(argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    printf("%s\n", replace(argv[1]));
    // argv[1] is replaced too because byRef
    return 0;
}

string replace(string word)
{
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        switch (word[i])
        {
            case 'a':
                word[i] = '6';
                break;
            
            case 'e':
                word[i] = '3';
                break;

            case 'i':
                word[i] = '1';
                break;
            
            case 'o':
                word[i] = '0';
                break;
            
            default:
                break;
        }
    }
    return word;
}
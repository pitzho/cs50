#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");
    // Check if a lowercase string's characters are in alphabetical order
    // If yes, print "Yes", and vise versa.

    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        word[i] = tolower(word[i]);
    }
    
    // This is my solution
    
    // int tracker = 0; 
    // for (int i = 1; i < len; i++)
    // {
    //     if (word[i] < word[i-1])
    //     {
    //         tracker++;
    //     }
    // }

    // if (tracker > 0)
    // {
    //     printf("No\n");
    // }
    // else
    // {
    //     printf("Yes\n");
    // }

    for (int i = 0; i < len - 1; i++)
    {
        if (word[i] > word[i + 1])
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
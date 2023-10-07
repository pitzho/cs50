#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool check(string password);

int main(void)
{
    // Prompt user for password
    string password = get_string("Enter your password: ");

    // Validate it and print result
    if (check(password))
    {
        printf("Your password is valid!\n");
        return 0;
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol!\n");
        return 1;
    }
}

bool check(string password)
{
    bool is_lower_case = false;
    bool is_upper_case = false;
    bool is_number = false;
    bool is_symbol = false;

    for (int i = 0, len = strlen(password); i < len; i++)
    {
        if (password[i] >= 33 && password[i] <= 47)
        {
            is_symbol = true;
        }
        else if (password[i] >= 48 && password[i] <= 57)
        {
            is_number = true;
        }
        else if (password[i] >= 58 && password[i] <= 64)
        {
            is_symbol = true;
        }
        else if (password[i] >= 65 && password[i] <= 90)
        {
            is_upper_case = true;
        }
        else if (password[i] >= 91 && password[i] <= 96)
        {
            is_symbol = true;
        }
        else if (password[i] >= 97 && password[i] <= 122)
        {
            is_lower_case = true;
        }
        else if (password[i] >= 123 && password[i] <= 125)
        {
            is_symbol = true;
        }
    }

    if (is_lower_case && is_upper_case && is_number && is_symbol)
    {
        return true;
    }
    else
    {
        return false;
    }
}

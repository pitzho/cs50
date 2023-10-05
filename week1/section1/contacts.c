#include <cs50.h>
#include <stdio.h>

int get_info();

int main(void)
{
    char answer = 'n';

    do
    {
        answer = get_info();
    }
    while (answer == 'n');

    printf("Thank you. Goodbye! \n\n");
}

int get_info()
{
    string name = get_string("\n\nEnter your name: ");
    int age = get_int("Enter your age: ");
    flong phone = get_long("Enter your phone number: ");

    printf("You entered these info:\n");
    printf("Your name is %s\n", name);
    printf("Your age is %i\n", age);
    printf("Your phone number is %li\n", phone);
    char answer = get_char("Is this info correct? (y/n): ");
    return answer;
}
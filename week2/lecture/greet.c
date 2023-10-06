#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // string name = get_string("What's your name? ");
    // printf("Hello, %s\n", name);

    // printf("Hello, %s\n", argv[1]); // $./greet.out Nick

    if (argc == 2)
    {
        printf("Hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}
#include <cs50.h>
#include <stdbool.h>

int main(void)
{
    int i = 0;
    while (i < 3)
    {
        printf("Meow!\n");
        i++;
    }

    for (int n = 0; n < 3; n++)
    {
        printf("Woof!\n");
    }

    while (true)
    {
        printf("Eternity!\n");
    }
}
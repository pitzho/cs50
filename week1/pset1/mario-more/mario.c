#include <cs50.h>
#include <stdio.h>

int get_size(void);
void pyramids(int size);

int main(void)
{
    // Prompt from user, how tall are pyramids.
    // They must be between 1 and 8 inclusive bricks tall.
    // Gap between hashes is 2

    int size = get_size();
    // printf("%i\n", size);
    pyramids(size);
}

int get_size(void)
{
    int size;
    do
    {
        size = get_int("Height: ");
    }
    while (size < 1 || size > 8);
    return size;
}

void print_space(int size, int level)
{
    for (int i = 0; i < (size - level); i++)
    {
        printf(" ");
    }
}

void print_hash(int level)
{
    for (int i = 0; i < level; i++)
    {
        printf("#");
    }
}

void pyramids(int size)
{
    int level = 1;
    for (int i = 0; i < size; i++)
    {
        print_space(size, level);
        print_hash(level);
        printf("  ");
        print_hash(level);
        printf("\n");
        level++;
    }
}
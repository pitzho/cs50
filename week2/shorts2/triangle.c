#include <cs50.h>
#include <stdio.h>

bool valid_triangle(float side[]);

int main(void)
{
    float side[3];
    for (int i = 0; i < 3; i++)
    {
        side[i] = get_float("Enter the length of side %i: ", i+1);
    }
    
    bool answer = valid_triangle(side);
    if (answer)
    {
        printf("It's a valid triangle.\n");
    }
    else
    {
        printf("You can't make a triangle with these sides.\n");
    }
    return 0;
}

bool valid_triangle(float side[])
{
    // Check for all positive sides
    if (side[0] < 0 || side[1] < 0 || side[2] <0)
    {
        return false;
    }

    // Check that sum of any two sides greater than third
    if ((side[0] + side[1] <= side[2]) || (side[0] + side[2] <= side[1]) || (side[1] + side[2] <= side[0]))
    {
        return false;
    }

    // If passed both tests, we're good!
    return true;
}


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // int score1 = 72;
    // int score2 = 73;
    // int score3 = 33;
    
    int scores[3];
    // scores[0] = get_int("Score 1: ");
    // scores[1] = get_int("Score 2: ");
    // scores[2] = get_int("Score 3: ");

    for (int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", (float) (scores[0] + scores[1] + scores[2]) / 3);
}
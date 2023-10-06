#include <cs50.h>
#include <stdio.h>

// const int N = 3; // Global constant

float average(int length, int array[]);

int main(void)
{
    // int score1 = 72;
    // int score2 = 73;
    // int score3 = 33;
    const int N = get_int("Number of scores: ");
    int scores[N];
    
    // scores[0] = get_int("Score 1: ");
    // scores[1] = get_int("Score 2: ");
    // scores[2] = get_int("Score 3: ");

    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // printf("Average: %f\n", (float) (scores[0] + scores[1] + scores[2]) / 3);
    printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return (float) sum / length;
}
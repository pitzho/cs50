#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
// clang readability.c -o readability.out -lcs50 -lm

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int count_grade(int letters, int words, int sentences);

int main(void)
{
    // Prompt user for a string
    string text = get_string("Text: ");

    // Count number of letters, words and sentences in the text
    int letters = count_letters(text);
    // printf("%i letters\n", letters);

    int words = count_words(text);
    // printf("%i words\n", words);

    int sentences = count_sentences(text);
    // printf("%i sentences\n", sentences);

    int grade = count_grade(letters, words, sentences);
    // printf("Grade %i\n", grade);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

    return 0;
}

int count_letters(string text)
{
    int counter = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            counter++;
        }
    }
    return counter;
}

int count_words(string text)
{
    int counter = 0;
    int len = strlen(text);

    for (int i = 1; i < len; i++)
    {
        // Check spaces, tabs and punctuation marks
        if (isblank(text[i]) || ispunct(text[i]) || isspace(text[i]))
        {
            // Check these symbols before it
            if (!(isblank(text[i - 1]) || ispunct(text[i - 1]) || isspace(text[i - 1])))
            {
                // Don't count these symbols
                if (text[i] != '\'' && text[i] != '-')
                {
                    counter++;
                }
            }
        }

        // Are any symbols in text?
        int letters = count_letters(text);
        if (letters == 0)
        {
            counter = 0;
        }
    }

    // Check last symbol to count a word, if there's no punctuation in the end of text
    if (isalpha(text[len - 1]))
    {
        counter++;
    }
    return counter;
}

int count_sentences(string text)
{
    int counter = 0;
    int len = strlen(text);

    for (int i = 1; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            if (!(isblank(text[i - 1]) || ispunct(text[i - 1]) || isspace(text[i - 1])))
            {
                counter++;
            }
        }
    }

    // Check last symbol to count a sentence, if there's no punctuation in the end of text
    if (isalpha(text[len - 1]))
    {
        counter++;
    }
    return counter;
}

int count_grade(int letters, int words, int sentences)
{
    // L is the average number of letters per 100 words in the text
    float L = letters / ((float) words / 100);
    // S is the average number of sentences per 100 words in the text
    float S = sentences / ((float) words / 100);
    int index = (int) round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}

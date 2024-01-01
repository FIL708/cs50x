#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);

    int words = count_words(text);

    int sentences = count_sentences(text);

    double avrWords = letters / (double) words * 100;

    double avrSentences = sentences / (double) words * 100;

    double index = 0.0588 * avrWords - 0.296 * avrSentences - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text)
{
    int sum = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            sum++;
        }
    }

    return sum;
}

int count_words(string text)
{
    int sum = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isblank(text[i]))
        {
            sum++;
        }
    }

    return sum;
}

int count_sentences(string text)
{
    int sum = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] == '.' || text[i] == '!' || text[i] == '?') && isalpha(text[i - 1]))
        {
            sum++;
        }
    }

    return sum;
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string input);
int count_words(string input);
int count_sentences(string input);

int main(void)
{
    //get input
    string s = get_string("Text: ");
    //call functions
    int letters = count_letters(s);
    int words = count_words(s);
    int sentences = count_sentences(s);

    //count grade level
    float index = 0.0588 * ((100*letters)/words) - 0.296 * ((100*sentences)/words) - 15.8;
    int grade = round(index);

    //Printing the grade

    if ( grade >= 16)
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

}

int count_letters(string input)
{
    int letter_count = 0;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if(((65 <= input[i]) && (input[i] <= 90)) || ((97 <= input[i]) && (input[i] <= 122)))
        {
            letter_count++;
        }
    }

    return letter_count;
}

int count_words(string input)
{
    int words_count = 1;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (input[i] == 32)
        {
            words_count++;
        }
    }

    return words_count;
}

int count_sentences(string input)
{
    int sentences_count = 0;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if ((input[i] == 46) || (input[i] == 33) || (input[i] == 63))
        {
            sentences_count++;
        }
    }

    return sentences_count;
}

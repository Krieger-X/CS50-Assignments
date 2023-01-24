#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    //gets user input for text
    string text = get_string("Text: ");

    float l, s;
    int x;
    //function assigns the value to variable letter_count
    int letter_count = count_letters(text);
    //function assigns the value to variable word_count
    int word_count = count_words(text);
    //function assigns the value to variable sentence_count
    int sentence_count = count_sentences(text);

    //all the formulas to find Grade
    l = letter_count / (float)word_count * 100;
    s = sentence_count / (float)word_count * 100;
    x = round(0.0588 * l - 0.296 * s - 15.8);

    //prints grade according to X's value
    if (x < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (x >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", x);
    }
}

//counts the letters by extracting the alphabets in the text
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letters++;
        }
    }
    return letters;
}

//counts words depending on how many spaces in between words + 1
int count_words(string text)
{
    //words' initial value start with 1, because there are n + 1 spaces between words
    int words = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    return words;
}

//counts sentences by checking every single periods, excalamation marks, question marks in the text
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}
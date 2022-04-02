//This program calculates the grade level of text, based on the coleman liau formula.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//verklaar de functies.
int count_letters(string);
int count_words(string);
int count_sentences(string);
int calculate_index(int, int, int);
void print_index(int);

int main(void)
{
//Vraag input
    string text = get_string("text: ");

//Tel de letters
    int letters = count_letters(text);
//Tel de woorden
    int words = count_words(text);
//Tel de zinnen
    int sentences = count_sentences(text);
//bereken de index
    int grade = calculate_index(words, letters, sentences);
//print de index
    //void print_index(grade);
    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}


int count_letters(string text)
{
    int l = 0;
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            l++;
        }
    }
    return l;
}

int count_words(string text)
{
    int w = 1;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ')
        {
            w++;
        }
    }
    return w;
}

int count_sentences(string text)
{
    int s = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            s++;
        }
    }
    return s;
}

int calculate_index(int words, int letters, int sentences)
{
//Coleman-Liau Formula.
    int l = (float)letters / words * 100;
    int s = (float)sentences / words * 100;
    int index = round(0.0588 * l - 0.296 * s - 15.8);
    return index;
}



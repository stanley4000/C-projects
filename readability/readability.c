#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

// calculate variables for Coleman-Liau index for reading level of input text
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
// Use get_string() for input
    string text = get_string("Text: ");
    int letter_count = count_letters(text);
    // printf("%i\n", letter_count);
    int word_count = count_words(text);
    // printf("%i\n", word_count);
    int sentence_count = count_sentences(text);
    // printf("%i\n", sentence_count);

// Calculates index (<1 = "Before Grade 1"; >=16 = "Grade 16+")
    // average letters per 100 words
    float x = ((float)letter_count / word_count) * 100;
    // printf("Average letters per 100 words: %d\n", x);

    // average sentences per 100 words
    float y = (((float)sentence_count / word_count) * 100);
    // printf("Average sentences per 100 words: %f\n", y);

    int round_index = round((x * 0.0588) - (y * 0.296) - 15.8);

    // Print ouput as "Grade x"
    if (round_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (round_index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", round_index);
    }
}

//count total number of letters, words, and sentences
int count_letters(string text)
{
    int letter_count = 0, n = 0;
    while (text[n] != '\0')
    {
        // convert to lower case
        text[n] = tolower(text[n]);
        // tests if character at text[n] is a letter. // The ASCII value of the lowercase alphabet is from 97 to 122.
        if (text[n] >= 97 && text[n] <= 122)
        {
            letter_count++;
        }
        n++;
    }

    return letter_count;
}

int count_words(string text)
{
    // count number of spaces in text. The ASCII code for a blank space is the decimal number 32.
    int word_count = 1, n = 0;
    while (text[n] != '\0')
    {
        if (text[n] == 32)
        {
            word_count++;
        }
        n++;
    }

    return word_count;
}

int count_sentences(string text)
{
    // counts ending punctuation. period = 46, ? = 63, ! = 33.
    int sentence_count = 0, n = 0;
    while (text[n] != '\0')
    {
        if (text[n] == 46 || text[n] == 63 || text[n] == 33)
        {
            sentence_count++;
        }
        n++;
    }

    return sentence_count;
}
// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string word;
string replace(string input);

int main(int argc, string argv[])
{
    // Throws error message if one command line argument not entered.
    if (argc != 2)
    {
        printf("Enter one command line argument.");
        return 1;
    }
    else
    {
        word = argv[1];

        printf("%s\n", replace(word));
    }
}
// replaces vowels with symbols as defined. Returns output.
string replace(string input)
{
    string output = input;
    // Counts number of characters up until '\0' (aka NUL); records length
    int n = 0;
    while (word[n] != '\0')
    {
        n++;
    }
    int length = n;

    for (int i = 0; i < length; i++)
    {
        switch (output[i])
        {
            case 'a':
                output[i] = '6';
                break;

            case 'e':
                output[i] = '3';
                break;

            case 'i':
                output[i] = '1';
                break;

            case 'o':
                output[i] = '0';
                break;

            default:
                break;
        }
    }

    return output;
}
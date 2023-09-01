#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{

    int length = strlen(input);
    if (length == 1)
    {
        //base case
        return (int)input[0] - 48;
    }
    // Get value at last digit
    char char_digit = input[length - 1];
    int digit = (int)char_digit - 48;
    //eliminate last digit, return value + 10 * input
    input[length - 1] = '\0';
    return digit + 10 * convert(input);
}



    // note: acii values of numberals 0-9 are 48-57: subtract 48 from ascii value for int value

    // // NOTE: The following codew works, but it doesn't use recursion. recode.
    // for (int i = 0; i < length; i++)
    // {
        // // get char at last digit, multiply by 10 ^ i, add to number
        // char char_digit = input[length - 1 - i];
        // int digit = (int)char_digit - 48;
        // printf("%i\n", digit);
        // printf("%i\n", i);
        // printf("%i\n", (int)pow(10, i));
        // number += digit * (int)(pow(10, i));
    // }
    // return number;

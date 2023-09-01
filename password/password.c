// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // Counts number of characters up until '\0' (aka NUL); records length
    int n = 0;
    while (password[n] != '\0')
    {
        n++;
    }
    int length = n, uppercase = 0, lowercase = 0, symbol = 0, number = 0;
    // Checks each character for type, adds to count for each type
    for (int i = 0; i < length; i++)
    {
        int character = password[i];
        if (ispunct(character))
        {
            symbol++;
        }
        else if (isdigit(character))
        {
            number++;
        }
        else if (islower(character))
        {
            lowercase++;
        }
        else if (isupper(character))
        {
            uppercase++;
        }
    }
    // Checks if conditions are meant, returns true if they are.
    if (uppercase >= 1 && lowercase >= 1 && symbol >= 1 && number >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

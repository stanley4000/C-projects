#include <stdio.h>
#include <cs50.h>

int main(void)
// prompts for user's name and replies with hello using name
{
    string name = get_string("What's your name? ");
    printf("Hello, %s\n", name);
}



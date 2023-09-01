#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Name: ");
    int age = get_int("Age: ");
    string number = get_string("Phone Number: ");

    printf("Age = %i. Name = %s. Number = %s.\n", age, name, number);
}
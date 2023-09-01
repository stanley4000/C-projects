#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cc = get_long("Credit card number: ");
    int is_every_other = -1; // this value will alternate -1/1 each time last digit is sliced
    int sum = 0, card_type = 0, i = 0;

    while (cc > 0) // Note: no valid card numbers start with '0'
    {
        i++; //counter to check that cc is at least 13 digits
        long last_dig = cc % 10;
        if (is_every_other > 0 && 2 * last_dig < 10)
        {
            sum += (2 * last_dig);
        }
        else if (is_every_other > 0 && 2 * last_dig >= 10)
        {
            sum += ((2 * last_dig) % 10) + 1;
        }
        else
        {
            sum += last_dig;
        }
        cc /= 10; // decimal value will be truncated by int type
        is_every_other *= -1;
        //Checks first number to return card type
        if (cc == 34 || cc == 37)
        {
            card_type = 1; // Amex
        }
        if (50 < cc && 56 > cc)
        {
            card_type = 2; //MasterCard
        }
        if (cc == 4)
        {
            card_type = 3; //Visa
        }
    }

    if (sum % 10 == 0)
    {
        if (i < 13)
        {
            printf("INVALID");
        }
        else if (card_type == 1)
        {
            printf("AMEX");
        }
        else if (card_type == 2)
        {
            printf("MASTERCARD");
        }
        else if (card_type == 3)
        {
            printf("VISA");
        }
        else
        {
            printf("INVALID");
        }
    }
    else
    {
        printf("INVALID");
    }
    printf("\n");
    // printf ("%d", sum);
    // printf ("%ld\n", last_dig);
    // printf ("%ld\n", second_last);

}
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: \n");
    // convert characters in message to decimal numbers
    int length = strlen(message), decimal_message[length], bin_char[BITS_IN_BYTE], bin_value[BITS_IN_BYTE] = {127, 63, 31, 15, 7, 3, 1, 0};
    int byte_array[length][BITS_IN_BYTE];

    // Initializing byte_array with zeros
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            byte_array[i][j] = 0;
        }
    }

    for (int i = 0; i < length; i++) // Cycles through all values of decimal_message[]
    {
        //converts each character to ascii (decimal)
        decimal_message[i] = (int)message[i];
        // printf("%i\n", decimal_message[i]);

        // Updates 8 bits of bin_char[] to 1 (if necessary), subtracts bin_value from decimal
        for (int j = 0; j < BITS_IN_BYTE; j++)

        {
            // initializes bit to 0
            bin_char[j] = 0;
            if (decimal_message[i] > bin_value[j])
            {
                bin_char[j] = 1;
                decimal_message[i] -= (bin_value[j] + 1);
            }
        }

        // // prints 8-bit character for testing:
        // for (int k = 0; k < BITS_IN_BYTE; k++)
        // {
        //     printf("%d ", bin_char[k]);
        // }
        // printf("\n");

        // adds 8-bit bin_char to array byte_array[]
        for (int k = 0; k < BITS_IN_BYTE; k++)
        {
            byte_array[i][k] = bin_char[k];
        }
        // // prints for testing:
        // for (int k = 0; k < 8; k++)
        // {
        //     printf("%d ", byte_array[i][k]);
        // }
        // printf("\n");

        // prints as bulbs:
        for (int k = 0; k < 8; k++)
        {
            print_bulb(byte_array[i][k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

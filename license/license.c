#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers: array stores a list of 8 7-digit licenses
    char plates[8][7];

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // NOTE: plates[] was only recording 8 characters, program currently calls for 8 strings of 7 chars each.
    // Pointer status removed to store strings.

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        for (int i = 0; i < 7; i++)
        {
            // Replace '\n' with '\0'
            buffer[6] = '\0';

            // Save plate number in array NOTE: no longer using pointers here.
            plates[idx][i] = buffer[i];
        }
        idx++;
    }
    fclose(infile);

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }
}

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage (eg, ./reverse input.wav output.wav)
    if (argc != 3)
    {
        printf("Usage: ./reverse infile outfile\n");
        return 1;
    }

    // Define file name
    char *infile = argv[1];

    // Open input file for reading (argv[1])
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    // Read infile's WAVFILEHEADER
    WAVHEADER wh;
    fread(&wh, sizeof(WAVHEADER), 1, inptr);

    // Use check_format to ensure WAV format (NOTE: check_format returns 0 if wave fileheader not confirmed)
    if (check_format(wh) == 0)
    {
        printf("Unsupported file format.\n");
        fclose(inptr);
        return 1;
    }

    // define output file
    char *outfile = argv[2];
    // Open output file for writing
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        printf("Could not create %s.\n", outfile);
        fclose(inptr);
        return 1;
    }

    // Write outfile's WAVFILEHEADER
    fwrite(&wh, sizeof(WAVHEADER), 1, outptr);

    // Use get_block_size to calculate size of block
    // NOTE: get_block_size(wh) returns the size (in bytes) of the audio data present in the data block.
    int size = get_block_size(wh);

    // TODO: code the input/output for each block of audio data
    // // Write reversed audio to file
    // BYTE buffer[size];
    // while (ftell(inptr) - size > sizeof(header))
    // {
    //     fread(buffer, size, 1, inptr);
    //     fwrite(buffer, size, 1, outptr);
    // }

    // // Note: data starts at Byte offset 44
    // for (int i = 44; i < size + 43; i++)
    // {
    //     tempbyte =
    // }


    // Close files
    fclose(inptr);
    fclose(outptr);
    return 0;

}

int check_format(WAVHEADER header)
{

    if (header.format[0] != 'W' || header.format[1] != 'A' || header.format[2] != 'V' ||
        header.format[3] != 'E')
    {
        //returns false if WAVE format not confirmed in header
        return 0;
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // int size = header.subchunk2Size;
    // NOTE: above line is not adequate, as it does not account for number of channels.
    int size = header.numChannels * header.bitsPerSample / 8;
    // if (size != header.subchunk2Size / 8)
    // {
    //     printf("You were wrong. Subchunk 2 does not return size in bytes of audio chunk.\n");
    // }
    return size;
}
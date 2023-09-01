#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    // loop through each row
    for (int i = 0; i < height; i++)
    {
        // apply to each pixel
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtRed == 0x00)
            {
                image[i][j].rgbtRed = 0xff;
            }
        }
    }
}

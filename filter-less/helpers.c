#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // iterates each row
    for (int i = 0; i < height; i++)
    {
        // iterates over pixels in row
        for (int j = 0; j < width; j++)
        {
            // determines average value of r, g, and b
            int value = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            // sets r, g, b equal to average value
            image[i][j].rgbtBlue = value;
            image[i][j].rgbtGreen = value;
            image[i][j].rgbtRed = value;
        }
    }
    return;
}

// Convert image to sepia
/* Note algorithm: sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
  sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
  sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue */
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // iterates each row
    for (int i = 0; i < height; i++)
    {
        // iterates over pixels in row
        for (int j = 0; j < width; j++)
        {
            // stores original values of r, g, and b
            int orig_red = image[i][j].rgbtRed;
            int orig_green = image[i][j].rgbtGreen;
            int orig_blue = image[i][j].rgbtBlue;
            // stores new value of r, g, and b according to algorithm
            int sepia_blue = round(.272 * orig_red + .534 * orig_green + .131 * orig_blue);
            int sepia_green = round(.349 * orig_red + .686 * orig_green + .168 * orig_blue);
            int sepia_red = round(.393 * orig_red + .769 * orig_green + .189 * orig_blue);
            if (sepia_blue > 255)
            {
                sepia_blue = 255;
            }
            if (sepia_green > 255)
            {
                sepia_green = 255;
            }
            if (sepia_red > 255)
            {
                sepia_red = 255;
            }
            // Changes pixel to sepia color
            image[i][j].rgbtBlue = sepia_blue;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtRed = sepia_red;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // iterates each row
    for (int i = 0; i < height; i++)
    {
        // iterates over pixels in first half of row

        for (int j = 0; j < (int) ((width) / 2); j++)
        {
            // temporary variable for swap
            RGBTRIPLE temp = image[i][j];
            // swaps left and right sides
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int red_total = 0, green_total = 0, blue_total = 0, red_average, green_average, blue_average;
    // temporary image for storing blurred pixels
    RGBTRIPLE temp_image[height][width];
    // iterates each row
    for (int i = 0; i < height; i++)
    {
        // iterates over pixels in row
        for (int j = 0; j < width; j++)
        {
            // calculates total r, g, and b values for all adjacent pixels (cases not on edges)
            if (i != 0 && i != height - 1 && j != 0 && j != width - 1)
            {
                for (int x = -1; x < 2; x++)
                {
                    for (int y = -1; y < 2; y++)
                    {
                        red_total += image[i + y][j + x].rgbtRed;
                        green_total += image[i + y][j + x].rgbtGreen;
                        blue_total += image[i + y][j + x].rgbtBlue;
                    }
                }
                // divides totals by 9 (cases not on edge of image)
                red_average = round((float) red_total / 9);
                green_average = round((float) green_total / 9);
                blue_average = round((float) blue_total / 9);
                // resets totals
                red_total = 0;
                green_total = 0;
                blue_total = 0;
            }
            else if (i == 0)
            {
                if (j != 0 && j != width - 1)
                {
                    // total for all adjacent pixels (top edge, no corners)
                    for (int x = -1; x < 2; x++)
                    {
                        for (int y = 0; y < 2; y++)
                        {
                            red_total += image[i + y][j + x].rgbtRed;
                            green_total += image[i + y][j + x].rgbtGreen;
                            blue_total += image[i + y][j + x].rgbtBlue;
                        }
                    }
                    // divides totals by 6 (cases on edge of image, not corners)
                    red_average = round((float) red_total / 6);
                    green_average = round((float) green_total / 6);
                    blue_average = round((float) blue_total / 6);
                    // resets totals
                    red_total = 0;
                    green_total = 0;
                    blue_total = 0;
                }

                else if (j == 0)
                {
                    // total for adjacent pixels (top left corner)
                    for (int x = 0; x < 2; x++)
                    {
                        for (int y = 0; y < 2; y++)
                        {
                            red_total += image[i + y][j + x].rgbtRed;
                            green_total += image[i + y][j + x].rgbtGreen;
                            blue_total += image[i + y][j + x].rgbtBlue;
                        }
                    }
                    red_average = round((float) red_total / 4);
                    green_average = round((float) green_total / 4);
                    blue_average = round((float) blue_total / 4);
                    // resets totals
                    red_total = 0;
                    green_total = 0;
                    blue_total = 0;
                }

                else if (j == width - 1)
                {
                    // total for adjacent pixels (top right corner)
                    for (int x = -1; x < 1; x++)
                    {
                        for (int y = 0; y < 2; y++)
                        {
                            red_total += image[i + y][j + x].rgbtRed;
                            green_total += image[i + y][j + x].rgbtGreen;
                            blue_total += image[i + y][j + x].rgbtBlue;
                        }
                    }
                    red_average = round((float) red_total / 4);
                    green_average = round((float) green_total / 4);
                    blue_average = round((float) blue_total / 4);
                    // resets totals
                    red_total = 0;
                    green_total = 0;
                    blue_total = 0;
                }
            }
            else if (i == height - 1)
            {
                if (j != 0 && j != width - 1)
                {
                    // total for all adjacent pixels (bottom edge, no corners)
                    for (int x = -1; x < 2; x++)
                    {
                        for (int y = -1; y < 1; y++)
                        {
                            red_total += image[i + y][j + x].rgbtRed;
                            green_total += image[i + y][j + x].rgbtGreen;
                            blue_total += image[i + y][j + x].rgbtBlue;
                        }
                    }
                    // divides totals by 6 (cases on edge of image, not corners)
                    red_average = round((float) red_total / 6);
                    green_average = round((float) green_total / 6);
                    blue_average = round((float) blue_total / 6);
                    // resets totals
                    red_total = 0;
                    green_total = 0;
                    blue_total = 0;
                }

                else if (j == 0)
                {
                    // total for adjacent pixels (bottom left corner)
                    for (int x = 0; x < 2; x++)
                    {
                        for (int y = -1; y < 1; y++)
                        {
                            red_total += image[i + y][j + x].rgbtRed;
                            green_total += image[i + y][j + x].rgbtGreen;
                            blue_total += image[i + y][j + x].rgbtBlue;
                        }
                    }
                    red_average = round((float) red_total / 4);
                    green_average = round((float) green_total / 4);
                    blue_average = round((float) blue_total / 4);
                    // resets totals
                    red_total = 0;
                    green_total = 0;
                    blue_total = 0;
                }

                else if (j == width - 1)
                {
                    // total for adjacent pixels (bottom right corner)
                    for (int x = -1; x < 1; x++)
                    {
                        for (int y = -1; y < 1; y++)
                        {
                            red_total += image[i + y][j + x].rgbtRed;
                            green_total += image[i + y][j + x].rgbtGreen;
                            blue_total += image[i + y][j + x].rgbtBlue;
                        }
                    }
                    red_average = round((float) red_total / 4);
                    green_average = round((float) green_total / 4);
                    blue_average = round((float) blue_total / 4);
                    // resets totals
                    red_total = 0;
                    green_total = 0;
                    blue_total = 0;
                }
            }
            else if ((j == 0 && i != 0) || (j == 0 && i != height - 1)) // left edge (excudes corners)
            {
                // total for all adjacent pixels (left edge, no corners)
                for (int x = 0; x < 2; x++)
                {
                    for (int y = -1; y < 2; y++)
                    {
                        red_total += image[i + y][j + x].rgbtRed;
                        green_total += image[i + y][j + x].rgbtGreen;
                        blue_total += image[i + y][j + x].rgbtBlue;
                    }
                }
                // divides totals by 6 (cases on edge of image, not corners)
                red_average = round((float) red_total / 6);
                green_average = round((float) green_total / 6);
                blue_average = round((float) blue_total / 6);
                // resets totals
                red_total = 0;
                green_total = 0;
                blue_total = 0;
            }

            else if ((j == width - 1 && i != 0) || (j == width - 1 && i != height - 1)) // right edge (excludes corners)
            {
                // total for all adjacent pixels (right edge, no corners)
                for (int x = -1; x < 1; x++)
                {
                    for (int y = -1; y < 2; y++)
                    {
                        red_total += image[i + y][j + x].rgbtRed;
                        green_total += image[i + y][j + x].rgbtGreen;
                        blue_total += image[i + y][j + x].rgbtBlue;
                    }
                }
                // divides totals by 6 (cases on edge of image, not corners)
                red_average = round((float) red_total / 6);
                green_average = round((float) green_total / 6);
                blue_average = round((float) blue_total / 6);
                // resets totals
                red_total = 0;
                green_total = 0;
                blue_total = 0;
            }
            // sets r, g, and b of pixel in temporary image to average value

            temp_image[i][j].rgbtRed = red_average;
            temp_image[i][j].rgbtGreen = green_average;
            temp_image[i][j].rgbtBlue = blue_average;
        }
    }
    // copy all pixels of temp_image to image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp_image[i][j];
        }
    }
    return;
}

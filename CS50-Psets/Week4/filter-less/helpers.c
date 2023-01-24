#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //get the color of each pixel
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            //implement greyscale formula
            int average = round((red + blue + green) / 3.0);

            //assign the values to each pixel
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            //implement sepia formula
            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);

            if (sepiaRed >= 256)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen >= 256)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue >= 256)
            {
                sepiaBlue = 255;
            }

            //assign RGB values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through each row
    for (int i = 0; i < height; i++)
    {
        //loop through width / 2 size of the column and swap the pixels
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int totalRed = 0, totalBlue = 0, totalGreen = 0;
            float divideBy = 0;

            if (i - 1 >= 0 && j - 1 >= 0)
            {
                // get upper left pixel value
                totalRed += copy[i - 1][j - 1].rgbtRed;
                totalBlue += copy[i - 1][j - 1].rgbtBlue;
                totalGreen += copy[i - 1][j - 1].rgbtGreen;
                divideBy++;
            }
            if (i - 1 >= 0)
            {
                // gets upper middle pixel's value
                totalRed += copy[i - 1][j].rgbtRed;
                totalBlue += copy[i - 1][j].rgbtBlue;
                totalGreen += copy[i - 1][j].rgbtGreen;
                divideBy++;
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                //gets upper right pixel's value
                totalRed += copy[i - 1][j + 1].rgbtRed;
                totalBlue += copy[i - 1][j + 1].rgbtBlue;
                totalGreen += copy[i - 1][j + 1].rgbtGreen;
                divideBy++;
            }
            if (j - 1 >= 0)
            {
                //left pixel
                totalRed += copy[i][j - 1].rgbtRed;
                totalBlue += copy[i][j - 1].rgbtBlue;
                totalGreen += copy[i][j - 1].rgbtGreen;
                divideBy++;
            }
            if (j + 1 < width)
            {
                // right pixel
                totalRed += copy[i][j + 1].rgbtRed;
                totalBlue += copy[i][j + 1].rgbtBlue;
                totalGreen += copy[i][j + 1].rgbtGreen;
                divideBy++;
            }
            if (i + 1 < height && j - 1 >= 0)
            {
                // lower left
                totalRed += copy[i + 1][j - 1].rgbtRed;
                totalBlue += copy[i + 1][j - 1].rgbtBlue;
                totalGreen += copy[i + 1][j - 1].rgbtGreen;
                divideBy++;
            }
            if (i + 1 < height)
            {
                // lower middle
                totalRed += copy[i + 1][j].rgbtRed;
                totalBlue += copy[i + 1][j].rgbtBlue;
                totalGreen += copy[i + 1][j].rgbtGreen;
                divideBy++;
            }
            if (i + 1 < height && j + 1 < width)
            {
                // lower right
                totalRed += copy[i + 1][j + 1].rgbtRed;
                totalBlue += copy[i + 1][j + 1].rgbtBlue;
                totalGreen += copy[i + 1][j + 1].rgbtGreen;
                divideBy++;
            }

            //middle pixel
            totalRed += copy[i][j].rgbtRed;
            totalBlue += copy[i][j].rgbtBlue;
            totalGreen += copy[i][j].rgbtGreen;
            divideBy++;

            // calculate average and assign the values
            image[i][j].rgbtRed = round(totalRed / divideBy);
            image[i][j].rgbtBlue = round(totalBlue / divideBy);
            image[i][j].rgbtGreen = round(totalGreen / divideBy);

        }
    }
    return;
}
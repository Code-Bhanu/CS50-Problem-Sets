#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdint.h>
//blur value calculation function definition
float value(int i, int j, int height, int width, RGBTRIPLE image2[height][width], char color);


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average = 0;

    for (int i = 0; i < height ; i++)
    {
        for (int j = 0; j < width ; j++)
        {
            //formula for greyscale
            average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0 ;

            image[i][j].rgbtBlue = (int)round(average);
            image[i][j].rgbtGreen = (int)round(average);
            image[i][j].rgbtRed = (int)round(average);
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    double sepiaRed = 0, sepiaGreen = 0, sepiaBlue = 0, originalRed = 0, originalGreen = 0, originalBlue = 0;

    for (int i = 0; i < height ; i++)
    {
        for (int j = 0; j < width ; j++)
        {
            originalRed = image[i][j].rgbtRed ;
            originalGreen = image[i][j].rgbtGreen ;
            originalBlue = image[i][j].rgbtBlue;

            //formula for sepia
            sepiaRed = (.393 * originalRed) + (.769 * originalGreen) + (.189 * originalBlue);
            sepiaGreen = (.349 * originalRed) + (.686 * originalGreen) + (.168 * originalBlue);
            sepiaBlue = (.272 * originalRed) + (.534 * originalGreen) + (.131 * originalBlue);

            //capping the max value of color to 255
            image[i][j].rgbtBlue = (round(sepiaBlue) > 255) ? 255 : round(sepiaBlue) ;
            image[i][j].rgbtGreen = (round(sepiaGreen) > 255) ? 255 : round(sepiaGreen);
            image[i][j].rgbtRed = (round(sepiaRed) > 255) ? 255 : round(sepiaRed);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int w = width - 1;
    int temp = 0;

    for (int i = 0; i < height ; i++)
    {

        for (int j = 0; j < width / 2 ; j++)
        {
            if (j != w)
            {
                // Swapping pixels on both halves of image
                temp = image[i][w - j].rgbtBlue;
                image[i][w - j].rgbtBlue = image[i][j].rgbtBlue;
                image[i][j].rgbtBlue = temp;


                temp = image[i][w - j].rgbtGreen;
                image[i][w - j].rgbtGreen = image[i][j].rgbtGreen;
                image[i][j].rgbtGreen = temp;

                temp = image[i][w - j].rgbtRed;
                image[i][w - j].rgbtRed = image[i][j].rgbtRed;
                image[i][j].rgbtRed = temp ;


            }

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    //copy of pixel
    RGBTRIPLE image1[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //making a copy of the pixel 2D array
            image1[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //blur value calculations
            image[i][j].rgbtRed =  round(value(i, j, height, width, image1, 'R'));
            image[i][j].rgbtGreen = round(value(i, j, height, width, image1, 'G'));
            image[i][j].rgbtBlue = round(value(i, j, height, width, image1, 'B'));
        }
    }


    return;
}

// calculates average of RGB values within 1 row and column of orginal pixel
float value(int i, int j, int height, int width, RGBTRIPLE image2[height][width], char color)
{
    float count = 0;
    int tot = 0;

    // 1 row before and after
    for (int k = i - 1; k < (i + 2); k++)
    {
        // 1 column before and after
        for (int l = j - 1; l < (j + 2); l ++)
        {
            if (k < 0 || l < 0 || k >= height || l >= width)
            {
                continue;
            }
            if (color == 'R')
            {
                tot += image2[k][l].rgbtRed;
            }
            else if (color == 'G')
            {
                tot += image2[k][l].rgbtGreen;
            }
            else if (color == 'B')
            {
                tot += image2[k][l].rgbtBlue;
            }
            count++;

        }
    }
    return  tot / count;
}
#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double sepiaR = image[i][j].rgbtBlue * 0.189 + image[i][j].rgbtGreen * 0.769 + image[i][j].rgbtRed * 0.393;

            double sepiaG = image[i][j].rgbtBlue * 0.168 + image[i][j].rgbtGreen * 0.686 + image[i][j].rgbtRed * 0.349;

            double sepiaB = image[i][j].rgbtBlue * 0.131 + image[i][j].rgbtGreen * 0.534 + image[i][j].rgbtRed * 0.272;

            image[i][j].rgbtBlue = sepiaB > 255 ? 255 : (int) round(sepiaB);
            image[i][j].rgbtGreen = sepiaG > 255 ? 255 : (int) round(sepiaG);
            image[i][j].rgbtRed = sepiaR > 255 ? 255 : (int) round(sepiaR);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp;
            temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE orginal[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            orginal[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            float sumR = 0, sumG = 0, sumB = 0;

            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    if (k < 0 || k > height - 1 || l < 0 || l > width - 1)
                    {
                        continue;
                    }

                    count++;
                    sumR += orginal[k][l].rgbtRed;
                    sumG += orginal[k][l].rgbtGreen;
                    sumB += orginal[k][l].rgbtBlue;
                }

                image[i][j].rgbtRed = (int) round(sumR / count);
                image[i][j].rgbtGreen = (int) round(sumG / count);
                image[i][j].rgbtBlue = (int) round(sumB / count);
            }
        }
    }
    return;
}

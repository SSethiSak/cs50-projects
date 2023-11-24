#include "helpers.h"
#include <stdio.h>
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avrg = 0;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {

           //calculate the average of all 3 rgb pre greyscale and then set the greyscale to that average

          avrg = (float)(image[row][col].rgbtBlue + image[row][col].rgbtRed + image[row][col].rgbtGreen) / 3;
          avrg = round(avrg);
            //need to convert all 3 rgb to the same color value

            image[row][col].rgbtBlue = avrg;
            image[row][col].rgbtRed = avrg;
            image[row][col].rgbtGreen = avrg;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float SepiaRed,SepiaGreen,SepiaBlue;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
             SepiaRed = (float)(.393 * image[row][col].rgbtRed + .769 * image[row][col].rgbtGreen + .189 * image[row][col].rgbtBlue);
             SepiaGreen = (float)(.349 * image[row][col].rgbtRed + .686 * image[row][col].rgbtGreen + .168 * image[row][col].rgbtBlue);
             SepiaBlue = (float)(.272 * image[row][col].rgbtRed + .534 * image[row][col].rgbtGreen + .131 * image[row][col].rgbtBlue);

             SepiaRed = round(SepiaRed);
             SepiaGreen = round(SepiaGreen);
             SepiaBlue = round(SepiaBlue);
            //if the value is more than 255 cap it at 255
            if (SepiaRed > 255)
            {
                SepiaRed = 255;
            }

            if (SepiaGreen > 255)
            {
                SepiaGreen = 255;
            }

            if (SepiaBlue > 255)
            {
                SepiaBlue =255;
            }

            image[row][col].rgbtRed = SepiaRed;
            image[row][col].rgbtGreen = SepiaGreen;
            image[row][col].rgbtBlue = SepiaBlue;
            }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    if (width % 2 == 0)//if width is even
    {
        for (int row = 0; row < height; row++)
        {
            for (int col = 0; col < (width / 2); col++)
            {
                int tRed = image[row][col].rgbtRed;
                int tGreen = image[row][col].rgbtGreen;
                int tBlue = image[row][col].rgbtBlue;

                int col2 = width - col - 1;

                 image[row][col].rgbtRed = image[row][col2].rgbtRed;
                 image[row][col2].rgbtRed = tRed;

                 image[row][col].rgbtGreen = image[row][col2].rgbtGreen;
                 image[row][col2].rgbtGreen = tGreen;

                 image[row][col].rgbtBlue = image[row][col2].rgbtBlue;
                 image[row][col2].rgbtBlue = tBlue;

            }
        }
    }
   else for (int row = 0; row < height; row++)
   {
    for (int col = 0; col < (width + 1) / 2; col++)
    {
            int tRed = image[row][col].rgbtRed;
            int tGreen = image[row][col].rgbtGreen;
            int tBlue = image[row][col].rgbtBlue;
            int col2 = (width - 1 - col);

            image[row][col].rgbtRed = image[row][col2].rgbtRed;
            image[row][col2].rgbtRed = tRed;

            image[row][col].rgbtGreen = image[row][col2].rgbtGreen;
            image[row][col2].rgbtGreen = tGreen;

            image[row][col].rgbtBlue = image[row][col2].rgbtBlue;
            image[row][col2].rgbtBlue = tBlue;
    }
   }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    float SumRed, SumGreen, SumBlue;
    for (int rowcopy = 0; rowcopy < height; rowcopy++)
    {
        for (int colcopy = 0; colcopy < width; colcopy++)
        {
            copy[rowcopy][colcopy].rgbtRed = image[rowcopy][colcopy].rgbtRed;
            copy[rowcopy][colcopy].rgbtGreen = image[rowcopy][colcopy].rgbtGreen;
            copy[rowcopy][colcopy].rgbtBlue = image[rowcopy][colcopy].rgbtBlue;
        }

    }


    for (int row = 0; row < height; row++)// row is i
    {
        for (int col = 0; col < width; col++)//col is j
        {
            if (row == 0 && col == 0)//if top left
            {
                SumRed = (float)(copy[row][col].rgbtRed + copy[row][col + 1].rgbtRed + copy[row + 1][col].rgbtRed + copy[row + 1][col + 1].rgbtRed) / 4;
                 SumGreen = (float)(copy[row][col].rgbtGreen + copy[row][col + 1].rgbtGreen + copy[row + 1][col].rgbtGreen + copy[row + 1][col + 1].rgbtGreen) / 4;
                  SumBlue = (float)(copy[row][col].rgbtBlue + copy[row][col + 1].rgbtBlue + copy[row + 1][col].rgbtBlue + copy[row + 1][col + 1].rgbtBlue) / 4;
            }
            else if (row == 0 && col == (width - 1))//if top right

            {
                SumRed = (float)(copy[row][col].rgbtRed + copy[row][col - 1].rgbtRed + copy[row + 1][col - 1].rgbtRed + copy[row + 1][col].rgbtRed) / 4;
                 SumGreen = (float)(copy[row][col].rgbtGreen + copy[row][col - 1].rgbtGreen + copy[row + 1][col - 1].rgbtGreen + copy[row + 1][col].rgbtGreen) / 4;
                  SumBlue = (float)(copy[row][col].rgbtBlue + copy[row][col - 1].rgbtBlue + copy[row + 1][col - 1].rgbtBlue + copy[row + 1][col].rgbtBlue) / 4;
            }

            else if (row == (height - 1) && col == 0)// if bottom left
            {
                SumRed = (float)(copy[row][col].rgbtRed + copy[row - 1][col].rgbtRed + copy[row - 1][col + 1].rgbtRed + copy[row][col + 1].rgbtRed) / 4;
                SumGreen = (float)(copy[row][col].rgbtGreen + copy[row - 1][col].rgbtGreen + copy[row - 1][col + 1].rgbtGreen + copy[row][col + 1].rgbtGreen) / 4;
                SumBlue = (float)(copy[row][col].rgbtBlue + copy[row - 1][col].rgbtBlue + copy[row - 1][col + 1].rgbtBlue + copy[row][col + 1].rgbtBlue) / 4;

            }

            else if (row == (height - 1) && col == (width - 1))//if bottom right
            {
                SumRed = (float)(copy[row][col].rgbtRed + copy[row - 1][col - 1].rgbtRed + copy[row - 1][col].rgbtRed + copy[row][col - 1].rgbtRed) / 4;
                 SumGreen = (float)(copy[row][col].rgbtGreen + copy[row - 1][col - 1].rgbtGreen + copy[row - 1][col].rgbtGreen + copy[row][col - 1].rgbtGreen) / 4;
                  SumBlue = (float)(copy[row][col].rgbtBlue + copy[row - 1][col - 1].rgbtBlue + copy[row - 1][col].rgbtBlue + copy[row][col - 1].rgbtBlue) / 4;

            }


           else if (row == 0)//if its the top of the image
            {
                 SumRed = (float)(copy[row][col - 1].rgbtRed + copy[row][col].rgbtRed + copy[row][col + 1].rgbtRed + copy[row + 1][col - 1].rgbtRed + copy[row + 1][col].rgbtRed + copy[row + 1][col + 1].rgbtRed) / 6;
                 SumGreen = (float)(copy[row][col - 1].rgbtGreen + copy[row][col].rgbtGreen + copy[row][col + 1].rgbtGreen + copy[row + 1][col - 1].rgbtGreen + copy[row + 1][col].rgbtGreen + copy[row + 1][col + 1].rgbtGreen) / 6;
                 SumBlue = (float)(copy[row][col - 1].rgbtBlue + copy[row][col].rgbtBlue + copy[row][col + 1].rgbtBlue + copy[row + 1][col - 1].rgbtBlue + copy[row + 1][col].rgbtBlue + copy[row + 1][col + 1].rgbtBlue) / 6;

            }

           else if (row == (height - 1))//if its bottom of image
            {
                 SumRed = (float)(copy[row - 1][col - 1].rgbtRed + copy[row - 1][col].rgbtRed + copy[row - 1][col + 1].rgbtRed + copy[row][col - 1].rgbtRed + copy[row][col].rgbtRed + copy[row][col + 1].rgbtRed) / 6;
                 SumGreen = (float)(copy[row - 1][col - 1].rgbtGreen + copy[row - 1][col].rgbtGreen + copy[row - 1][col + 1].rgbtGreen + copy[row][col - 1].rgbtGreen + copy[row][col].rgbtGreen + copy[row][col + 1].rgbtGreen) / 6;
                 SumBlue = (float)(copy[row - 1][col - 1].rgbtBlue + copy[row - 1][col].rgbtBlue + copy[row - 1][col + 1].rgbtBlue + copy[row][col - 1].rgbtBlue + copy[row][col].rgbtBlue + copy[row][col + 1].rgbtBlue) / 6;


            }

           else if (col == 0)//if its most left of pixel
            {
                 SumRed = (float)(copy[row - 1][col].rgbtRed + copy[row - 1][col + 1].rgbtRed + copy[row][col].rgbtRed + copy[row][col + 1].rgbtRed + copy[row + 1][col].rgbtRed + copy[row + 1][col + 1].rgbtRed) / 6;
                 SumGreen = (float)(copy[row - 1][col].rgbtGreen + copy[row - 1][col + 1].rgbtGreen + copy[row][col].rgbtGreen + copy[row][col + 1].rgbtGreen + copy[row + 1][col].rgbtGreen + copy[row + 1][col + 1].rgbtGreen) / 6;
                 SumBlue = (float)(copy[row - 1][col].rgbtBlue + copy[row - 1][col + 1].rgbtBlue + copy[row][col].rgbtBlue + copy[row][col + 1].rgbtBlue + copy[row + 1][col].rgbtBlue + copy[row + 1][col + 1].rgbtBlue) / 6;

            }

           else if (col == (width - 1))//if its most right of pixel
            {
            SumRed = (float)(copy[row - 1][col - 1].rgbtRed + copy[row - 1][col].rgbtRed + copy[row][col - 1].rgbtRed + copy[row][col].rgbtRed + copy[row + 1][col - 1].rgbtRed + copy[row + 1][col].rgbtRed) / 6;
            SumGreen = (float)(copy[row - 1][col - 1].rgbtGreen + copy[row - 1][col].rgbtGreen + copy[row][col - 1].rgbtGreen + copy[row][col].rgbtGreen + copy[row + 1][col - 1].rgbtGreen + copy[row + 1][col].rgbtGreen) / 6;
            SumBlue = (float)(copy[row - 1][col - 1].rgbtBlue + copy[row - 1][col].rgbtBlue + copy[row][col - 1].rgbtBlue + copy[row][col].rgbtBlue  + copy[row + 1][col - 1].rgbtBlue + copy[row + 1][col].rgbtBlue) / 6;

            }

            else //if pixel can form 3 x 3 grid
            {
            SumRed = (float)(copy[row - 1][col - 1].rgbtRed + copy[row - 1][col].rgbtRed + copy[row - 1][col + 1].rgbtRed + copy[row][col - 1].rgbtRed + copy[row][col].rgbtRed + copy[row][col + 1].rgbtRed + copy[row + 1][col - 1].rgbtRed + copy[row + 1][col].rgbtRed + copy[row + 1][col + 1].rgbtRed) / 9;

            SumGreen = (float)(copy[row - 1][col - 1].rgbtGreen + copy[row - 1][col].rgbtGreen + copy[row - 1][col + 1].rgbtGreen + copy[row][col - 1].rgbtGreen + copy[row][col].rgbtGreen + copy[row][col + 1].rgbtGreen + copy[row + 1][col - 1].rgbtGreen + copy[row + 1][col].rgbtGreen + copy[row + 1][col + 1].rgbtGreen) / 9;

            SumBlue = (float)(copy[row - 1][col - 1].rgbtBlue + copy[row - 1][col].rgbtBlue + copy[row - 1][col + 1].rgbtBlue + copy[row][col - 1].rgbtBlue + copy[row][col].rgbtBlue + copy[row][col + 1].rgbtBlue + copy[row + 1][col - 1].rgbtBlue + copy[row + 1][col].rgbtBlue + copy[row + 1][col + 1].rgbtBlue) / 9;


            }
            SumRed = round(SumRed);
            SumGreen = round(SumGreen);
            SumBlue = round(SumBlue);


            image[row][col].rgbtRed = SumRed;
            image[row][col].rgbtGreen = SumGreen;
            image[row][col].rgbtBlue = SumBlue;
        }
    }
  return;
  }

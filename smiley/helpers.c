#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int pixrow = 0; pixrow < width; pixrow++)
    {
        for (int pixcol = 0; pixcol < height; pixcol++)
        {
            if (image[pixrow][pixcol].rgbtBlue == 0 && image[pixrow][pixcol].rgbtRed == 0 && image[pixrow][pixcol].rgbtGreen == 0)
            {
                image[pixrow][pixcol].rgbtBlue = 255;
                image[pixrow][pixcol].rgbtRed = 255;
            }

        }
    }
}

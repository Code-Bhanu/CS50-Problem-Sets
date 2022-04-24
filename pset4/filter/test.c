

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int w = 0;
    BYTE temp = 0;

    for(int i=0; i< height ; i++)
    {
        w = width - 1;
        for(int j=0; j< width ; j++)
        {
            if (j!=w)
            {
            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][w].rgbtBlue;
            image[i][w].rgbtBlue = temp;

            temp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][w].rgbtGreen;
            image[i][w].rgbtGreen = temp;

            temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][w].rgbtRed;
            image[i][w].rgbtRed = temp;
            }
            w--;

         }
    }


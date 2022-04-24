#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;
//check for jpg function declaration
int checkbuffer(BYTE buf[]);
int cntr = 0;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: Enter only one file as argument");
        return 1;
    }

    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    //buffer to store 512 bytes of data
    BYTE buffer[512];
    int ret = 0 ;
    ret = fread(buffer, sizeof(BYTE), 512, inptr);
    char filename[7] ;
    FILE *optr;

    //loop through the raw file 512 bytes at a time
    while (fread(buffer, sizeof(BYTE), 512, inptr) != 0)
    {
        if (checkbuffer(buffer) == 1)
        {
            if (cntr == 1)
            {
                // if it is first jpg
                optr = fopen("000.jpg", "w");
                if (optr == NULL)
                {
                    printf("Could not open out.jpeg.\n");
                    return 3;
                }
                fwrite(buffer, sizeof(BYTE), 512, optr);
            }
            else
            {
                //if it is other than first jpg
                fclose(optr);
                sprintf(filename, "%03i.jpg", cntr - 1);
                optr = fopen(filename, "w");
                if (optr == NULL)
                {
                    printf("Could not open out.jpeg.\n");
                    return 3;
                }
                fwrite(buffer, sizeof(BYTE), 512, optr);

            }

        }
        else if (cntr != 0)
        {
            //if it same jpg and needs to be appended
            fwrite(buffer, sizeof(BYTE), 512, optr);
        }



    }

    fclose(inptr);
    return 0;

}

//function that checks for jpg file
int checkbuffer(BYTE buf[])
{

    //check for first 4 bytes condition for jpg file
    if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] & 0xf0) == 0xe0)
    {
        cntr ++;
        return 1;
    }
    return 0;
}
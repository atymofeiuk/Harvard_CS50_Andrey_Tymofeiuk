/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet4: Resize (both "for less comfortable" + "for more comfortable"/"hacker edition")

    NB: PSet4/Resize file with Andrey Tymofeiuk's code is resize.c (all the variations of this file in the folder),
    other additional files contain distribution code provided by Harvard CS50 staff

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2018

**/


#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // Andrey Tymofeiuk: Getting the scale from the user
    int n = atoi(argv[1]);

    // Andrey Tymofeiuk: Getting file names from the user
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Andrey Tymofeiuk: Saving info about old file width and height
    int old_biWidth = bi.biWidth;
    int old_biHeight = bi.biHeight;

    // Andrey Tymofeiuk: Changes in BITMAPINFOHEADER
    bi.biWidth = bi.biWidth * n;
    bi.biHeight = bi.biHeight * n;
    int new_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biSizeImage = (sizeof(RGBTRIPLE) * bi.biWidth + new_padding) * abs(bi.biHeight);

    // Andrey Tymofeiuk: Changes in BITMAPFILEHEADER
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(old_biHeight); i < biHeight; i++)
    {
        int count = 1;
        while (count <= n)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < old_biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int k = 0; k < n; k++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // Andrey Tymofeiuk: Adding the padding
            for (int k = 0; k < new_padding; k++)
            {
                fputc(0x00, outptr);
            }

            fseek(inptr, -(old_biWidth * 3 + padding), SEEK_CUR);
            count++;
        }

        fseek(inptr, old_biWidth * 3 + padding, SEEK_CUR);

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}

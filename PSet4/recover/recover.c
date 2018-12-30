/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet4: Recover

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2018

**/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Andrey Tymofeiuk: Ensuring proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    char *card = argv[1];

    // Andrey Tymofeiuk: Opening card file and sanity check
    FILE *card_ptr = fopen(card, "r");
    if (card_ptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", card);
        return 2;
    }

    // Andrey Tymofeiuk: Creation of a buffer of 512 bytes
    char *buffer = malloc(512);
    int file_number = 0;

    // Andrey Tymofeiuk: Main while loop (going by a step of a block of 512 bytes)
    while (fread(buffer, 512, 1, card_ptr) == 1)
    {
        // Andrey Tymofeiuk: Check whether the photo is detected
        if (((buffer[0] == (char) 0xff) && (buffer[1] == (char) 0xd8) && (buffer[2] == (char) 0xff)
             && (buffer[3] & (char) 0xf0) == (char) 0xe0))
        {
            char filename[9];
            sprintf(filename, "%03i.jpg", file_number);
            file_number++;

            FILE *img = fopen(filename, "w");
            if (img == NULL)
            {
                return 3;
            }

            // Andrey Tymofeiuk: writing info until the next photo is detected
            while (1)
            {
                fwrite(buffer, 512, 1, img);
                if (fread(buffer, 512, 1, card_ptr) != 1)
                {
                    break;
                }
                if (((buffer[0] == (char) 0xff) && (buffer[1] == (char) 0xd8) && (buffer[2] == (char) 0xff)
                     && (buffer[3] & (char) 0xf0) == (char) 0xe0))
                {
                    break;
                }
            }

            fseek(card_ptr, -512, SEEK_CUR);

            fclose(img);
        }
    }

    free(buffer);
    fclose(card_ptr);
}
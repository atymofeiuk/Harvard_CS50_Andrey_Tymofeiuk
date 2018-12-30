/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet3: Music

    NB: PSet3/Music file with Andrey Tymofeiuk's code is helpers.c,
    other additional files contain distribution code provided by Harvard CS50 staff

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2018

**/

// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>

#include "helpers.h"

// Andrey Tymofeiuk: This function was written by me
// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    char c_num = '0', c_denom = '0';

    c_num = fraction[0];
    c_denom = fraction[2];

    if ((c_num == '1') && (c_denom == '8'))
    {
        return 1;
    }

    else if ((c_num == '1') && (c_denom == '4'))
    {
        return 2;
    }

    else if ((c_num == '3') && (c_denom == '8'))
    {
        return 3;
    }

    else
    {
        return 4;
    }

}

// Andrey Tymofeiuk: Written by me
// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // Andrey Tymofeiuk: Determining the frequency of C4 note which is the key to calculate
    float freqA4 = 440;
    float freqC4 = freqA4 * pow(2, - ((float) 9 / 12));

    // Andrey Tymofeiuk: Case when the note is without seminotes
    if ((note[1] != 'b') && (note[1] != '#'))
    {
        // Andrey Tymofeiuk: 67 is the ASCII value of 'C'
        int note_dif_raw = (int) note[0] - 67;
        int note_dif = 0;
        if (note_dif_raw >= 0)
        {
            note_dif = note_dif_raw;
        }
        // Andrey Tymofeiuk: Little bit weird approach due to the fact that octave starts with C, not with A
        else if (note[0] == 'A')
        {
            note_dif = 3 - note_dif_raw;
        }

        else
        {
            note_dif = 5 - note_dif_raw;
        }

        int check_flag = 0;

        if (note_dif > 2)
        {
            check_flag = 1;
        }

        int note_skew = 2 * note_dif - check_flag;

        // Andrey Tymofeiuk: 52 is the ASCII value of '4', the octave of our initial value
        int octave_dif = (int) note[1] - 52;

        int new_freq = round(freqC4 * pow(2, octave_dif) * pow(2, (float) note_skew / 12));

        return new_freq;
    }

    else
    {
        int note_dif_raw = (int) note[0] - 67;
        int note_dif = 0;
        if (note_dif_raw >= 0)
        {
            note_dif = note_dif_raw;
        }

        else if (note[0] == 'A')
        {
            note_dif = 3 - note_dif_raw;
        }

        else
        {
            note_dif = 5 - note_dif_raw;
        }

        int check_flag = 0;
        if (note_dif > 2)
        {
            check_flag = 1;
        }

        int note_skew = 0;
        if (note[1] == 'b')
        {
            note_skew = 2 * note_dif - check_flag - 1;
        }
        else
        {
            note_skew = 2 * note_dif - check_flag + 1;
        }

        int octave_dif = (int) note[2] - 52;

        int new_freq = round(freqC4 * pow(2, octave_dif) * pow(2, (float) note_skew / 12));

        return new_freq;
    }
}

// Andrey Tymofeiuk: Written by me
// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

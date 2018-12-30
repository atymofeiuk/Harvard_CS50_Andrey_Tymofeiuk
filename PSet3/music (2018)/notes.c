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

// Prints frequencies of and outputs WAV file with all notes in an octave

#include <cs50.h>
#include <stdio.h>
#include <string.h>

#include "helpers.h"
#include "wav.h"

// Notes in an octave
const string NOTES[] = {"C", "C#", "D", "D#", "E", "F",
                        "F#", "G", "G#", "A", "A#", "B"
                       };

// Default octave
#define OCTAVE 4

int main(int argc, string argv[])
{
    // Override default octave if specified at command line
    int octave = OCTAVE;
    if (argc == 2)
    {
        octave = atoi(argv[1]);
        if (octave < 0 || octave > 8)
        {
            fprintf(stderr, "Invalid octave\n");
            return 1;
        }
    }
    else if (argc > 2)
    {
        fprintf(stderr, "Usage: notes [OCTAVE]\n");
        return 1;
    }

    // Open file for writing
    song s = song_open("notes.wav");

    // Add each semitone
    for (int i = 0, n = sizeof(NOTES) / sizeof(string); i < n; i++)
    {
        // Append octave to note
        char note[4];
        sprintf(note, "%s%i", NOTES[i], octave);

        // Calculate frequency of note
        int f = frequency(note);

        // Print note to screen
        printf("%3s: %i\n", note, f);

        // Write (eighth) note to file
        note_write(s, f, 1);
    }

    // Close file
    song_close(s);
}

/**

    CS50: Introduction to Computer Science (course by Harvard University, taken via edX.org)

    PSet4: Whodunit

    NB: PSet4/Whodunit file with Andrey Tymofeiuk's code is whodunit.c (all the variationss of this file in the folder),
    other additional files contain distribution code provided by Harvard CS50 staff

    @author: Andrey Tymofeiuk

    Important: This code is placed at GitHub to track my progress in programming and
    to show my way of thinking. Also I will be happy if somebody finds my solution
    interesting. But I do respect The Honor Code and I ask you to respect it also - please
    don't submit this solution to the CS50 grader and do not copy it.

    (c) 2018

**/

# Questions

## What's `stdint.h`?

It is a special header, which contains the new types of integers.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To get 8-bit integer

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE: 8-bit
DWORD: 32-bit
LONG: 32-bit
WORD: 16-bit

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

14, 40 or 255, 216

## What's the difference between `bfSize` and `biSize`?

bfSize is the size, in bytes, of the file. biSize is a number of bytes required by the structure.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

No permission or file is absent or no memory

## Why is the third argument to `fread` always `1` in our code?

To equal the number of bytes transferred

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

0

## What does `fseek` do?

The fseek() function sets the file position indicator for the stream pointed to by stream.

## What is `SEEK_CUR`?

Current location of a cursor

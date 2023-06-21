#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void print_char_11x16(char c)
{
  c -= 0x20;
  for (char row = 0; row < 11; row++) {
    /* This short is pulling in one 16 bit binary number or row of the character */
    unsigned short rowBits = font_11x16[c][row];
    for (char col = 0; col < 16; col++) {
      /* makes makes a binary number of needed length to compare the current bit of rowBits to a 1 bit */
      unsigned short colMask = 1 << (15-col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}

void print_char_8x12(char c)
{
  c -= 0x20;
  /* This font is oriented differently than the other files which changes how the for loops work.
  Needs to run all 12 rows and then read through 8 bits of info to make the character */
  
  for (char row = 0; row < 12; row++) {
    unsigned short rowBits = font_8x12[c][row];
    for (char col = 0; col < 8; col++) {
      /*This is shifting the bits to the left by adding zeros to the right.Compares bit by bit */
      unsigned short colMask = 1 << (7-col);
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}

void print_char_5x7(char c)
{
  c -= 0x20;
  for (char row = 0; row < 5; row++) {
    unsigned short rowBits = font_5x7[c][row];
    /* Using 7 instead of 8 here because the 8th most bit is not used */
    for (char col = 0; col < 7; col++) {
      unsigned short colMask = 1 << (6-col);
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}

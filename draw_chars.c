#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void print_char_11x16(char c)
{
  c -= 0x20;
  for (char row = 0; row < 11; row++) {
    //This short could be moved into the for loop below depending on how the font is put together
    unsigned short rowBits = font_11x16[c][row];
    for (char col = 0; col < 16; col++) {
      //makes a binary string of 1s and compares them with rowbits to see when both are 1s
      unsigned short colMask = 1 << (15-col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}

void print_char_8x12(char c)
{
  c -= 0x20;
  //used 10 instead of 8 because of dead space in font
  for (char row = 0; row < 10; row++) {
    unsigned short rowBits = font_8x12[c][row];
    for (char col = 0; col < 12; col++) {
      //This is shifting the bits to the left by adding zeros to the right
      unsigned short colMask = 1 << (11-col); /* mask to select bit associated with bit */
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
    for (char col = 0; col < 7; col++) {
      unsigned short colMask = 1 << (6-col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}

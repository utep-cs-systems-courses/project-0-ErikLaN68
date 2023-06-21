#include <stdio.h>
#include "draw.h" // project-related declarations

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Triangle = t, Square = s, Arrow = a, Chars11x16 = c, Chars8x12 = f, Chars5x7 = p) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'a':
      puts("You selected arrow:");
      print_arrow(4,6);
      break;
    case 'c':
      puts("You selected chars11x16:");
      for (char c = 'A'; c < 'G'; c++)
	print_char_11x16(c);
      break;
    case 'f':
      puts("You selected chars8x12:");
      for (char c = 'A'; c < 'G';c++)
	print_char_8x12(c);
      break;
    case 'p':
      puts("You selected chars5x7:");
      for (char c = 'A'; c < 'G';c++)
	print_char_5x7(c);
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}

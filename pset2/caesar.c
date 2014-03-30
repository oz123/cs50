/* vim: set expandtab ts=2 sw=2 sts=2 ai: */

/* Encrypt a message using Caesar's cipher */

/* The program accepts a single command line argument: a non-negative integer 
 * This argument is called `k`. 
 * If no argument or more then one argument are give, the program should notify
 * the user and exist with status 1.
 * Otherwise, the program should prompt the user for a string of plain text
 * and then output the text encrypted where each character is rotated by k).
 * Non-alphabetical characters should be outputed unchanged.
 * After outputting the cipher text the program should exist with status 0.
 * 
 * The program should preseve the case of letters. 
 *
 * The formula for encrypting a char is:
 *
 *
 * ci = (pi + k) % 26
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <limits.h>
#include <errno.h>

const char ascii_lower = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char ascii_upper = "abcdefghijklmnopqrstuvwxyz";

/* 
 * a -> 97
   z -> 122

   A -> 65
   Z -> 90
  */

int get_key(char * argk){
  int base = 10;
  char *endptr;
  long k = 13;
  errno = 0;    /* To distinguish success/failure after call */
  k = strtol(argk, &endptr, base);

  /* Check for various possible errors */

  if ((errno == ERANGE && (k == LONG_MAX || k == LONG_MIN))
          || (errno != 0 && k == 0)) {
      perror("strtol");
      exit(EXIT_FAILURE);
  }

  if (endptr == argk) {
      return -1;
  }

  return k;

}


int main(int argc, string argv[]){
  
  if (argc > 2){
    printf("You gave to many arguments\n");
    printf("Usage: %s <integer>\n", argv[0]);
    return 1;
  } else if (argc == 1) {
    printf("You gave to few arguments\n");
    printf("Usage: %s <integer>\n", argv[0]);
    return 1;
  }
  
  int k = 13;

  k = get_key(argv[1]);
  if (k < 0) {
    fprintf(stderr, "No digits were found\n");
    printf("Usage: %s <integer>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  printf("%d\n", k);
  
  return 0;
}

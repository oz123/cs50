/* vim: set expandtab ts=2 sw=2 sts=2 ai: */

/*
Write, in a file called mario.c in your ~/Dropbox/pset1 directory, 
a program that recreates this half-pyramid using hashes (#) for blocks. 
However, to make things more interesting, first prompt the user for the 
half-pyramid's height, a non-negative integer no greater than 23.
(The height of the half-pyramid pictured above happens to be 8.) 
If the user fails to provide a non-negative integer no greater than 23, 
you should re-prompt for the same again. 
Then, generate (with the help of printf and one or more loops) the 
desired half-pyramid. 
Take care to align the bottom-left corner of your half-pyramid with the 
left-hand edge of your terminal window, as in the sample output below, 
wherein underlined text represents some user's input.
*/

#include <stdio.h>
#include <cs50.h>

int main(void){
    
  int height = -1 ; 
  
  while (height < 0 || height > 23) 
  {
    fputs("Height:", stdout);
    height = GetInt();
  } 
  
  int lspace = height - 1;
  int rspace = 2 ;
  for (int i = 0; i < height; i++){
    for (int j = 0 ; j < lspace; j++)
      printf(" ");
    for (int j = 0 ; j < rspace; j++)
      printf("#");
    
    lspace--;
    rspace++;
    printf("\n");
  }
  
  return 0;
}

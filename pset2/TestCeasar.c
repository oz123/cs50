#define _POSIX_C_SOURCE  2
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <cs50.h>
#include "CuTest.h"

#define DATA_SIZE 512
 
const char *ascii_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *ascii_lower = "abcdefghijklmnopqrstuvwxyz";

char rotate(int key, char in){
  int idx;
  if (islower(in)){
    idx= (int)in - 97;
    printf("ascii_lower[idx]: %c", ascii_lower[idx]);
    return ascii_lower[(idx+key)%26];
  }
  if (isupper(in)){
    idx= (int)in - 65;
    //printf("ascii_upper[idx]: %c\n", ascii_upper[idx]);
    //printf("ascii_upper[idx+key]: %c\n", ascii_upper[idx+key]);
    return ascii_upper[(idx+key)%26];
  }
  else
    return in;
}


void TestCipher(CuTest *tc) {
  CuAssertTrue(tc, rotate(13*3, 'c') == 'p');
  CuAssertTrue(tc, rotate(13*3, 'C') == 'P');
  CuAssertTrue(tc, rotate(13*3, ' ') == ' ');
  CuAssertTrue(tc, rotate(13, 'C') == 'P');
  CuAssertTrue(tc, rotate(13, ' ') == ' ');
}


CuSuite * StrUtilGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestCipher);
  return suite;
}

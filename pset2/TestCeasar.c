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
 

char* StrToUpper(char* str) {
  int i = 0;
  while ( str[i] != '\0'){
    str[i] = toupper(str[i]);
    i++;
    }
  return str;
}

char rotate(int key, char thechar){
  
  

  return 'C';


}


void TestCipher(CuTest *tc) {
  // char *input = "hello world";
  // This is implicit const char *input!
  // This is why it will cause segmentation fault
  // We can't change a const variable
  CuAssertTrue(tc, rotate(13, 'C') == 'P');
}


CuSuite * StrUtilGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestCipher);
  return suite;
}

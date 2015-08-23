// bit-count.c - Return number of non-zero binary bits in an integer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_INPUT 1
#define TOO_LONG 2

static int getLine(char *prompt, char *buffer, size_t size);
static char *intToBinary(int n, char *buffer, size_t size);
static int countChars(char *in, char find);

int main() {
  int valueCount;
  char valueCount_Buffer[10];

  valueCount = getLine("number to process > ", valueCount_Buffer, 10);
  if (valueCount == NO_INPUT) {
    printf("error: input was too long! : [%s]\n", valueCount_Buffer);
    return 1;
  }

  int intvar;
  if ( sscanf(valueCount_Buffer, "%i", &intvar) != 1 ) {
    printf("error: not an integer!\n");
    return 1;
  }

  char binary_Buffer[30];
  binary_Buffer[29] = '\0';
  intToBinary(intvar, binary_Buffer, 29);

  int bitCount = countChars(binary_Buffer, '1');

  printf("binary form of your number is %s\n", binary_Buffer);
  printf("bit count of your number is %d\n", bitCount);

  return 0;
}

static int getLine(char *prompt, char *buffer, size_t size) {
  int chr, extra;

  if (prompt != NULL) {
    printf("%s", prompt);
    fflush(stdout);
  }

  if ( fgets(buffer, size, stdin) == NULL ) {
    return NO_INPUT;
  }

  if ( buffer[ strlen(buffer) - 1 ] != '\n' ) {
    extra = 0;
    while ( ( (chr = getchar()) != '\n' ) && (chr != EOF) ) {
      extra = 1;
    }
    return extra == 1 ? TOO_LONG : 0;
  }

  buffer[ strlen(buffer) - 1 ] = '\0';
  return 0;
}

static char *intToBinary(int n, char *buffer, size_t size) {
  buffer += (size - 1);

  for (int i = 31; i >= 0; i--) {
    *buffer-- = (n & 1) + '0';
    n >>= 1;
  }

  return buffer;
}

static int countChars(char *in, char find) {
  const char *p = in;
  int count = 0;

  do {
    if (*p == find) {
      count++;
    }
  } while ( *(p++) );

  return count;
}


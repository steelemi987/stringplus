#include "../s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *res = dest;
  do {
    *dest = *src;
    dest++;
    src++;
  } while (*src != '\0');
  *dest = *src;
  return res;
}
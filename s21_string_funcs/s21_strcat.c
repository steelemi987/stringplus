#include "../s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  char *end = dest + s21_strlen(dest);
  ;
  char *tmp = (char *)src;

  for (long unsigned int i = 0; tmp[i] != '\0'; i++) {
    *end = tmp[i];
    end++;
  }
  *end = '\0';

  return dest;
}
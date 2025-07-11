#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *end = dest + s21_strlen(dest);
  ;
  char *tmp = (char *)src;

  for (long unsigned int i = 0; (i < n) && (tmp[i] != '\0'); i++) {
    *end = tmp[i];
    end++;
  }
  *end = '\0';

  return dest;
}
#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  int i = -1;
  do {
    i++;
  } while (str[i] != '\0' && str[i] != c);

  return c == str[i] ? (char *)str + i : s21_NULL;
}
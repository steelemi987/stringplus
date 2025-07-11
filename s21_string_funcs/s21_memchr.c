#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *res = (char *)str;
  int flag = 0;

  for (long unsigned int i = 0; (!flag) && (res) && (i < n); i++) {
    if (res[i] == c) {
      flag = 1;
      res += i;
    }
  }
  if (!flag)
    res = s21_NULL;
  else
    res = (void *)res;

  return res;
}
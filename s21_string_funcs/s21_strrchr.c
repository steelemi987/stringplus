#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res;
  char *tmp = (char *)str;
  int flag = 0;
  s21_size_t len = s21_strlen(str) + 1;
  for (int i = len - 1; (!flag) && (i >= 0); i--) {
    if (tmp[i] == c) {
      res = &tmp[i];
      flag = 1;
    }
  }

  if (!flag) res = s21_NULL;

  return res;
}
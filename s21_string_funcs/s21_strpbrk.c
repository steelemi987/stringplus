#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res;
  char *tmp = (char *)str1;
  int flag = 0;
  for (int i = 0; (!flag) && (tmp[i] != '\0'); i++) {
    for (int j = 0; (!flag) && (str2[j] != '\0'); j++) {
      if (str1[i] == str2[j]) {
        res = &tmp[i];
        flag = 1;
      }
    }
  }
  if (!flag) res = s21_NULL;

  return res;
}
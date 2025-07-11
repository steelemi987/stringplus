#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  char *tmp1 = (char *)str1;
  char *tmp2 = (char *)str2;
  int flag = 0;
  for (int i = 0; (!flag) && (tmp1[i] != '\0'); i++) {
    for (int j = 0; (!flag) && (tmp2[j] != '\0'); j++) {
      if (tmp1[i] == tmp2[j]) {
        flag = 1;
      }
    }
    if (!flag) res++;
  }

  return res;
}
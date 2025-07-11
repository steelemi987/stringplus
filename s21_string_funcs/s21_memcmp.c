#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  char *tmp = (char *)str1;

  for (long unsigned int i = 0; (!res) && (tmp) && i < n; i++) {
    res = tmp[i] - ((char *)str2)[i];
  }
  return res;
}
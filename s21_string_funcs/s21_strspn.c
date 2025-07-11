#include "../s21_string.h"

s21_size_t s21_strspn(const char* str1, const char* str2) {
  s21_size_t res = 0;
  int to_search = 1;

  for (int i = 0; (to_search) && (str1[i] != '\0'); i++) {
    int flag = 0;
    for (int j = 0; (!flag) && (str2[j] != '\0'); j++) {
      if (str1[i] == str2[j]) {
        res++;
        flag = 1;
      }
    }
    if (!flag) to_search = 0;
  }

  return res;
}
#include "../s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  int res = 0;
  int flag = 0;

  for (long unsigned int i = 0; (!flag) && (str1) && (str2); i++) {
    res = str1[i] - str2[i];
    if ((res != 0) || (str1[i] == '\0') || (str2[i] == '\0')) flag = 1;
  }

  return res;
}
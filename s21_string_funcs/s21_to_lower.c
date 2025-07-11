#include "../s21_string.h"

void* s21_to_lower(const char* str) {
  char* res;
  if (str == s21_NULL)
    res = s21_NULL;
  else {
    int size = s21_strlen(str);
    res = (char*)malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++) {
      if (str[i] > 64 && str[i] < 91)
        res[i] = str[i] + 32;
      else
        res[i] = str[i];
    }
    res[size] = '\0';
  }
  return (void*)res;
}
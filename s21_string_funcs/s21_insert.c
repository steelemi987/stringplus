#include "../s21_string.h"

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  char* res;
  if (src == s21_NULL)
    res = s21_NULL;
  else if (str == s21_NULL) {
    res = s21_NULL;
  } else {
    int check = (int)s21_strlen(src);
    if (check < (int)start_index || (int)start_index < 0)
      res = s21_NULL;
    else {
      int size = (int)s21_strlen(src) + (int)s21_strlen(str);
      res = (char*)malloc(sizeof(char) * (size + 1));
      char* tmp_1 = (char*)src;
      char* tmp_2 = (char*)str;
      int i;
      for (i = 0; i < (int)start_index; i++) {
        res[i] = tmp_1[i];
      }
      int c = i;
      int k = 0;
      for (i = start_index; str[k] != '\0'; i++, k++) {
        res[i] = tmp_2[k];
      }
      for (int j = i; tmp_1[c] != '\0'; j++, c++) {
        res[j] = tmp_1[c];
      }
      res[size] = '\0';
    }
  }
  return (void*)res;
}
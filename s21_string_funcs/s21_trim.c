#include "../s21_string.h"

void* s21_trim(const char* src, const char* trim_chars) {
  char* defolt = " \t\n\v\r\f";
  char* res;
  if (src == s21_NULL)
    res = s21_NULL;
  else {
    char* tmp = (char*)src;
    int size = s21_strlen(src);
    char* end_src = (char*)malloc(sizeof(char) * size + 1);
    int k = 0;
    for (int i = size - 1; i >= 0; i--) {
      end_src[k] = src[i];
      k++;
    }
    end_src[size] = '\0';
    int start_size, end_size;
    if (trim_chars == s21_NULL || trim_chars[0] == '\0') {
      start_size = (int)s21_strspn(src, defolt);
      end_size = (int)s21_strspn(end_src, defolt);
    } else {
      start_size = (int)s21_strspn(src, trim_chars);
      end_size = (int)s21_strspn(end_src, trim_chars);
    }
    free(end_src);
    int res_size = size - start_size - end_size;
    res = (char*)malloc(sizeof(char) * res_size + 1);
    for (int i = 0; i < res_size; i++) {
      res[i] = tmp[start_size];
      start_size++;
    }
    res[res_size] = '\0';
  }
  return (void*)res;
}
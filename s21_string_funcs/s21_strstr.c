#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  int temp = 0;
  int j = 0;
  int size = (int)s21_strlen(haystack);
  for (int i = 0; i < size && j != (int)s21_strlen(needle); i++) {
    temp = i;
    j = 0;
    while (haystack[i + j] == needle[j] && haystack[i + j] != '\0') {
      j++;
    }
  }
  return (((temp + 1) != size) && (haystack[0] != '\0' || needle[0] == '\0')) ||
                 (s21_strlen(needle) == 1 && j != 0)
             ? (char *)haystack + temp
             : s21_NULL;
}
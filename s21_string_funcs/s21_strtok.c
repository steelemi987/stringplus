#include "../s21_string.h"

char* s21_strtok(char* str, const char* delim) {
  static char* next = NULL;
  if (str != NULL) {
    next = str;
  }
  char* res = next;
  if (res != NULL) {
    next += s21_strspn(next, delim);
    res = next;
    next += s21_strcspn(next, delim);
    if (*next != '\0') {
      *next = '\0';
      next++;
    } else {
      next = NULL;
    }
    if (*res == '\0') res = NULL;
  }
  return res;
}

// char* s21_strtok(char* str, const char* delim) {
//   static char* next;
//   if (str != s21_NULL) {
//     next = str;
//   }
//   char* res = next;
//   if (res != s21_NULL) {
//     next += s21_strspn(next, delim);
//     res = next;
//     next += (s21_strcspn(next, delim));
//     if ((next != s21_NULL) && (*next != '\0')) {
//       *next = '\0';
//       next++;
//     } else
//       *next = '\0';
//     if (*res == '\0') res = s21_NULL;
//   }

//   return res;
// }
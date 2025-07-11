#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (long unsigned int i = 0; i < n; i++) {
    ((char *)dest)[i] = ((char *)src)[i];
  }
  char *end = dest + s21_strlen(dest);
  *end = '\0';
  return dest;
}
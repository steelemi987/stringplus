#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string.h"  // Тест лежит в src, а если в tests/ то "../s21_string.h"

START_TEST(test_memchr_loop) {
  char str[5][20] = {"This is test", "This is test", "This is test", "abc", ""};
  char s[5] = {'e', 'e', 'e', ' ', '\0'};
  s21_size_t l[5] = {0, 3, 13, 3, 1};
  if (!_i) printf("\033[45m-=S21_MEMCHR=-\033[0m\n");
  printf("TEST_MEMCHR_%d | INPUT: str= '%s' c= '%c' len= %ld|", _i, str[_i],
         s[_i], l[_i]);
  printf(" string.h: '%s' | s21_string.h: '%s'\n",
         (char *)memchr(str[_i], s[_i], l[_i]),
         (char *)s21_memchr(str[_i], s[_i], l[_i]));
  ck_assert_ptr_eq(memchr(str[_i], s[_i], l[_i]),
                   s21_memchr(str[_i], s[_i], l[_i]));
}
END_TEST

START_TEST(test_memcmp_loop) {
  char str[6][20] = {"This is\ttest", "This is\ttest", "This is\ttest",
                     "This is\ttest", "This is\ttest", ""};
  char sub[6][20] = {"This is\ttest", "This is\ttest", "This is\t####",
                     "ABC",           "This",          ""};
  s21_size_t l[6] = {0, 13, 8, 3, 4, 1};
  if (!_i) printf("\033[45m-=S21_MEMCMP=-\033[0m\n");
  printf("TEST_MEMCMP_%d | INPUT: str1= '%s' str2= '%s' len= %ld|", _i, str[_i],
         sub[_i], l[_i]);
  printf(" string.h: '%d' | s21_string.h: '%d'\n",
         memcmp(str[_i], sub[_i], l[_i]), s21_memcmp(str[_i], sub[_i], l[_i]));
  int n1 = memcmp(str[_i], sub[_i], l[_i]);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(str[_i], sub[_i], l[_i]);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}

END_TEST
START_TEST(test_memcpy_loop) {
  char s1[14] = "Hello, world!";
  char s2[14] = "Hello, world!";
  char s3[6][15] = {"Good", "Good", "Good", "Good", "LO", "\0"};
  s21_size_t n[6] = {0, 3, 4, 5, 10, 1};
  if (!_i) printf("\033[45m-=S21_MEMCRY=-\033[0m\n");
  printf("TEST_MEMCPY_loop_%d | INPUT: dst= '%s' src= '%s' len= %ld|\n", _i, s1,
         s3[_i], n[_i]);
  ck_assert_str_eq(memcpy(s1, s3[_i], n[_i]), s21_memcpy(s2, s3[_i], n[_i]));
  printf("%18d | OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", _i, s1, s2);
}
END_TEST

START_TEST(test_memcpy_pust) {
  char s1[2] = "";
  char s2[2] = "";
  char s3[2][15] = {"G", "\0"};
  s21_size_t n[2] = {1, 1};
  printf("TEST_MEMCPY_pust_%d | INPUT: dst= '%s' src= '%s' len= %ld|\n", _i, s1,
         s3[_i], n[_i]);
  ck_assert_str_eq(memcpy(s1, s3[_i], n[_i]), s21_memcpy(s2, s3[_i], n[_i]));
  printf("%18d | OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", _i, s1, s2);
}
END_TEST

START_TEST(test_memset_loop) {
  char s1[14] = "Hello, world!";
  char s2[14] = "Hello, world!";
  s21_size_t n[4] = {0, 1, 6, 13};
  int ch[4] = {'@', '\0', '@', '#'};
  if (!_i) printf("\033[45m-=S21_MEMSET=-\033[0m\n");
  printf("TEST_MEMSET_loop_%d | INPUT: str1= '%s' symb= '%c' len= %ld|", _i, s1,
         ch[_i], n[_i]);
  ck_assert_str_eq(memset(s1, ch[_i], n[_i]), s21_memset(s2, ch[_i], n[_i]));
  printf(" string.h: '%s' | s21_string.h: '%s'\n", s1, s2);
}
END_TEST

START_TEST(test_memset_pust) {
  char s1[2] = "";
  char s2[2] = "";
  s21_size_t n[2] = {1, 1};
  int ch[2] = {'#', '\0'};
  printf("TEST_MEMSET_pust_%d | INPUT: str1= '%s' symb= '%c' len= %ld|", _i, s1,
         ch[_i], n[_i]);
  ck_assert_str_eq(memset(s1, ch[_i], n[_i]), s21_memset(s2, ch[_i], n[_i]));
  printf(" string.h: '%s' | s21_string.h: '%s'\n", s1, s2);
}
END_TEST

START_TEST(test_strcat_loop) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[4][30] = {"Hello, world!", "TEST", "\0", "Hello, world!test"};
  if (!_i) printf("\033[45m-=S21_STRCAT=-\033[0m\n");
  printf("TEST_STRCAT_loop_%d | INPUT: str1= '%s' str2= '%s'|\n", _i, s1,
         s3[_i]);
  ck_assert_pstr_eq(strcat(s1, s3[_i]), s21_strcat(s2, s3[_i]));
  printf("%18d | OUTPUT string.h: '%s' | s21_string.h: '%s'\n", _i, s1, s2);
}
END_TEST

START_TEST(test_strcat_pust) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[2][30] = {"\0", "Hello, \0world!"};
  printf("TEST_STRCAT_pust_%d | INPUT: str1= '%s' str2= '%s'|\n", _i, s1,
         s3[_i]);
  ck_assert_pstr_eq(strcat(s1, s3[_i]), s21_strcat(s2, s3[_i]));
  printf("%18d | OUTPUT string.h: '%s' | s21_string.h: '%s'\n", _i, s1, s2);
}
END_TEST

START_TEST(test_strchr_loop) {
  char s[] = "Hello, world!";
  int ch[] = {'h', 'z', 'H', 'w', '!', '\0'};
  if (!_i) printf("\033[45m-=S21_STRCHR=-\033[0m\n");
  printf(
      "TEST_STRCHR | INPUT: str= '%s' c= '%c'| string.h: '%s' | s21_string.h: "
      "'%s'\n",
      s, ch[_i], strchr(s, ch[_i]), s21_strchr(s, ch[_i]));
  ck_assert_pstr_eq(strchr(s, ch[_i]), s21_strchr(s, ch[_i]));
}
END_TEST

START_TEST(test_strchr_pust) {
  char s[] = "";
  int ch[] = {'h', '\0'};
  printf(
      "TEST_STRCHR | INPUT: str= '%s' c= '%c'| string.h: '%s' | s21_string.h: "
      "'%s'\n",
      s, ch[_i], strchr(s, ch[_i]), s21_strchr(s, ch[_i]));
  ck_assert_pstr_eq(strchr(s, ch[_i]), s21_strchr(s, ch[_i]));
}
END_TEST

START_TEST(test_strcpy_loop) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[4][30] = {"Hello, world!", "TEST", "\0", "Hello, world!test"};
  if (!_i) printf("\033[45m-=S21_STRCPY=-\033[0m\n");
  printf("TEST_STRCPY_loop_%d | INPUT: str1= '%s' str2= '%s'|", _i, s1, s3[_i]);
  ck_assert_pstr_eq(strcpy(s1, s3[_i]), s21_strcpy(s2, s3[_i]));
  printf(" OUTPUT string.h: '%s' | s21_string.h: '%s'\n", s1, s2);
}
END_TEST

START_TEST(test_strcpy_pust) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[2][30] = {"\0", "Hello, \0world!"};
  printf("TEST_STRCPY_pust_%d | INPUT: str1= '%s' str2= '%s'|\n", _i, s1,
         s3[_i]);
  ck_assert_pstr_eq(strcpy(s1, s3[_i]), s21_strcpy(s2, s3[_i]));
  printf(" OUTPUT string.h: '%s' | s21_string.h: '%s'\n", s1, s2);
}
END_TEST

START_TEST(test_strcspn_loop) {
  char s1[14] = "Hello, world!";
  char s2[4][20] = {"world!", "0o$", "qz&", ""};
  if (!_i) printf("\033[45m-=S21_STRCSPN=-\033[0m\n");
  printf(
      "TEST_STRCSPN | INPUT: str1= '%s' str2= '%s'| string.h: '%ld' | "
      "s21_string.h: '%ld'\n",
      s1, s2[_i], strcspn(s1, s2[_i]), s21_strcspn(s1, s2[_i]));
  ck_assert_int_eq(strcspn(s1, s2[_i]), s21_strcspn(s1, s2[_i]));
}
END_TEST

START_TEST(test_strcspn_pust) {
  char s1[2] = "";
  char s2[2][20] = {"qz&", "\0"};
  printf(
      "TEST_STRCSPN | INPUT: str1= '%s' str2= '%s'| string.h: '%ld' | "
      "s21_string.h: '%ld'\n",
      s1, s2[_i], strcspn(s1, s2[_i]), s21_strcspn(s1, s2[_i]));
  ck_assert_int_eq(strcspn(s1, s2[_i]), s21_strcspn(s1, s2[_i]));
}
END_TEST

START_TEST(test_strerror_loop) {
  ck_assert_str_eq(strerror(_i), s21_strerror(_i));
}
END_TEST

START_TEST(test_strlen_loop) {
  char str[5][50] = {"Hello, world!", "\0", "\0ter", "1234\t5qwe\tr0987", "w"};
  if (!_i) printf("\033[45m-=S21_STRLEN=-\033[0m\n");
  printf(
      "TEST_STRLEN_1 | INPUT: str= '%s'| string.h: '%ld' | s21_string.h: "
      "'%ld'\n",
      str[_i], strlen(str[_i]), s21_strlen(str[_i]));
  ck_assert_int_eq(strlen(str[_i]), s21_strlen(str[_i]));
}
END_TEST

START_TEST(test_strncat_loop_1) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s4[100] = "Hello, world!";
  char s5[100] = "Hello, world!";
  char s3[19] = "This &is #a !test!";
  s21_size_t n[4] = {0, 1, 2, 12};
  if (!_i) printf("\033[45m-=S21_STRNCAT=-\033[0m\n");
  printf("TEST_STRNCAT | INPUT: dest= '%s' source= '%s' len= %ld|", s1, s3,
         n[_i]);
  printf(" string.h: '%s' | s21_string.h: '%s'\n", strncat(s4, s3, n[_i]),
         s21_strncat(s5, s3, n[_i]));
  ck_assert_pstr_eq(strncat(s1, s3, n[_i]), s21_strncat(s2, s3, n[_i]));
}
END_TEST
START_TEST(test_strncat_loop_2) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s4[100] = "Hello, world!";
  char s5[100] = "Hello, world!";
  char s3[2] = "\0";
  s21_size_t n[2] = {0, 1};
  printf("TEST_STRNCAT | INPUT: dest= '%s' source= '%s' len= %ld|", s1, s3,
         n[_i]);
  printf(" string.h: '%s' | s21_string.h: '%s'\n", strncat(s4, s3, n[_i]),
         s21_strncat(s5, s3, n[_i]));
  ck_assert_pstr_eq(strncat(s1, s3, n[_i]), s21_strncat(s2, s3, n[_i]));
}
END_TEST
START_TEST(test_strncat_loop_3) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s4[100] = "Hello, world!";
  char s5[100] = "Hello, world!";
  char s3[3] = "t\t";
  s21_size_t n[3] = {0, 1, 2};
  printf("TEST_STRNCAT | INPUT: dest= '%s' source= '%s' len= %ld|", s1, s3,
         n[_i]);
  printf(" string.h: '%s' | s21_string.h: '%s'\n", strncat(s4, s3, n[_i]),
         s21_strncat(s5, s3, n[_i]));
  ck_assert_pstr_eq(strncat(s1, s3, n[_i]), s21_strncat(s2, s3, n[_i]));
}
END_TEST
START_TEST(test_strncat_pust) {
  char s1[2] = "";
  char s2[2] = "";
  char s4[2] = "";
  char s5[2] = "";
  char s3[2] = "T";
  s21_size_t n[2] = {0, 1};
  printf("TEST_STRNCAT | INPUT: dest= '%s' source= '%s' len= %ld|", s1, s3,
         n[_i]);
  printf(" string.h: '%s' | s21_string.h: '%s'\n", strncat(s4, s3, n[_i]),
         s21_strncat(s5, s3, n[_i]));
  ck_assert_pstr_eq(strncat(s1, s3, n[_i]), s21_strncat(s2, s3, n[_i]));
}
END_TEST

START_TEST(test_strncmp_loop) {
  char s1[13] = "This is\ttest";
  char s2[8][100] = {"This is\ttest",  "This is\ttest",
                     "This is\ttest@", "ThisA",
                     "ThisA",          "",
                     "\0This is test", "T"};
  s21_size_t n[8] = {12, 13, 13, 12, 4, 12, 2, 0};
  if (!_i) printf("\033[45m-=S21_STRNCMP=-\033[0m\n");
  printf("TEST_STRNCMP_loop_%d | INPUT: str1= '%s' str2= '%s' len= %ld|", _i,
         s1, s2[_i], n[_i]);
  printf(" string.h: '%d' | s21_string.h: '%d'\n", strncmp(s1, s2[_i], n[_i]),
         s21_strncmp(s1, s2[_i], n[_i]));
  int n1 = strncmp(s1, s2[_i], n[_i]);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2[_i], n[_i]);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_strncmp_pust) {
  char s1[2] = "";
  char s2[5][100] = {"ABC", "ABC", "ABC", "", "\0This is test"};
  s21_size_t n[5] = {0, 1, 3, 1, 2};
  printf("TEST_STRNCMP_loop_%d | INPUT: str1= '%s' str2= '%s' len= %ld|", _i,
         s1, s2[_i], n[_i]);
  printf(" string.h: '%d' | s21_string.h: '%d'\n", strncmp(s1, s2[_i], n[_i]),
         s21_strncmp(s1, s2[_i], n[_i]));
  int n1 = strncmp(s1, s2[_i], n[_i]);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2[_i], n[_i]);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_strncpy_loop_1) {
  char s1[14] = "Hello, world!";
  char s2[14] = "Hello, world!";
  char s3[5] = "Good";
  s21_size_t n[5] = {0, 1, 4, 5, 10};
  if (!_i) printf("\033[45m-=S21_STRNCPY=-\033[0m\n");
  printf("TEST_STRNCPY_1_%d | INPUT: dst= '%s' src= '%s' len= %ld|\n", _i, s1,
         s3, n[_i]);
  ck_assert_pstr_eq(strncpy(s1, s3, n[_i]), s21_strncpy(s2, s3, n[_i]));
  printf("\t%8d | OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", _i, s1, s2);
}
END_TEST

START_TEST(test_strncpy_pust) {
  char s1[2][10] = {"", "hi!"};
  char s2[2][10] = {"", "hi!"};
  char s3[2] = "";
  s21_size_t n = 1;
  printf("TEST_STRNCPY_pust_%d | INPUT: dst= '%s' src= '%s' len= %ld|\n", _i,
         s1[_i], s3, n);
  ck_assert_pstr_eq(strncpy(s1[_i], s3, n), s21_strncpy(s2[_i], s3, n));
  printf("\t%11d | OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", _i, s1[_i],
         s2[_i]);
}
END_TEST

START_TEST(test_strpbrk_loop) {
  char s1[14] = "Hello, world!";
  char s2[5][10] = {"Hello", "row", "h", "z#@", "\0"};
  if (!_i) printf("\033[45m-=S21_STRPBRK=-\033[0m\n");
  printf(
      "TEST_STRPBRK_loop_%d | INPUT: str1= '%s' str2= '%s'| string.h: '%s' | "
      "s21_string.h: '%s'\n",
      _i, s1, s2[_i], strpbrk(s1, s2[_i]), s21_strpbrk(s1, s2[_i]));
  ck_assert_pstr_eq(strpbrk(s1, s2[_i]), s21_strpbrk(s1, s2[_i]));
}
END_TEST

START_TEST(test_strpbrk_pust) {
  char s1[2] = "";
  char s2[2][10] = {"Hello", "\0"};
  printf(
      "TEST_STRPBRK_pust_%d | INPUT: str1= '%s' str2= '%s'| string.h: '%s' | "
      "s21_string.h: '%s'\n",
      _i, s1, s2[_i], strpbrk(s1, s2[_i]), s21_strpbrk(s1, s2[_i]));
  ck_assert_pstr_eq(strpbrk(s1, s2[_i]), s21_strpbrk(s1, s2[_i]));
}
END_TEST

START_TEST(test_strrchr_loop) {
  char s[14] = "Hello, world!";
  int ch[5] = {'h', '\0', 'o', 'H', '#'};
  if (!_i) printf("\033[45m-=S21_STRRCHR=-\033[0m\n");
  printf(
      "TEST_STRRCHR_loop_%d | INPUT: str= '%s' c= '%c'| string.h: '%s' | "
      "s21_string.h: '%s'\n",
      _i, s, ch[_i], strrchr(s, ch[_i]), s21_strrchr(s, ch[_i]));
  ck_assert_pstr_eq(strrchr(s, ch[_i]), s21_strrchr(s, ch[_i]));
}
END_TEST

START_TEST(test_strrchr_pust) {
  char s[2] = "";
  int ch[2] = {'h', '\0'};
  printf(
      "TEST_STRRCHR_loop_%d | INPUT: str= '%s' c= '%c'| string.h: '%s' | "
      "s21_string.h: '%s'\n",
      _i, s, ch[_i], strrchr(s, ch[_i]), s21_strrchr(s, ch[_i]));
  ck_assert_pstr_eq(strrchr(s, ch[_i]), s21_strrchr(s, ch[_i]));
}
END_TEST

START_TEST(test_strspn_loop) {
  char s1[14] = "Hello, world!";
  char s2[6][15] = {"Hello, world!", "123", "Hel", "hel", "\0", "dlr"};
  if (!_i) printf("\033[45m-=S21_STRSPN=-\033[0m\n");
  printf(
      "TEST_STRSPN_loop_%d | INPUT: str= '%s' str2= '%s'| string.h: '%ld' | "
      "s21_string.h: '%ld'\n",
      _i, s1, s2[_i], strspn(s1, s2[_i]), s21_strspn(s1, s2[_i]));
  ck_assert_int_eq(strspn(s1, s2[_i]), s21_strspn(s1, s2[_i]));
}
END_TEST

START_TEST(test_strspn_pust) {
  char s1[2] = "";
  char s2[2][10] = {"\0", "dlr"};
  printf(
      "TEST_STRSPN_pust_%d | INPUT: str= '%s' str2= '%s'| string.h: '%ld' | "
      "s21_string.h: '%ld'\n",
      _i, s1, s2[_i], strspn(s1, s2[_i]), s21_strspn(s1, s2[_i]));
  ck_assert_int_eq(strspn(s1, s2[_i]), s21_strspn(s1, s2[_i]));
}
END_TEST

START_TEST(test_strstr_loop) {
  char s1[19] = "Hello, worldHello!";
  char s2[6][20] = {
      "Hello, worldHello!", "Hello, P!", "!", "hello", "Hello", "\0"};
  if (!_i) printf("\033[45m-=S21_STRSTR=-\033[0m\n");
  printf(
      "TEST_STRSTR_loop_%d | INPUT: str= '%s' substr= '%s'| string.h: '%s' | "
      "s21_string.h: '%s'\n",
      _i, s1, s2[_i], strstr(s1, s2[_i]), s21_strstr(s1, s2[_i]));
  ck_assert_pstr_eq(strstr(s1, s2[_i]), s21_strstr(s1, s2[_i]));
}
END_TEST

START_TEST(test_strstr_pust) {
  char s1[2] = "";
  char s2[2][10] = {"Hello", "\0"};
  printf(
      "TEST_STRSTR_pust_%d | INPUT: str= '%s' substr= '%s'| string.h: '%s' | "
      "s21_string.h: '%s'\n",
      _i, s1, s2[_i], strstr(s1, s2[_i]), s21_strstr(s1, s2[_i]));
  ck_assert_pstr_eq(strstr(s1, s2[_i]), s21_strstr(s1, s2[_i]));
}
END_TEST

START_TEST(test_strtok_one_iteration) {
  char s1[6][25] = {"Hello, good world!",
                    "Hello#good#world",
                    "hello!",
                    " good world",
                    "\0",
                    " ,!"};
  char s2[6][25] = {"Hello, good world!",
                    "Hello#good#world",
                    "hello!",
                    " good world",
                    "\0",
                    " ,!"};
  char s3[5] = " ,!";
  if (!_i) printf("\033[45m-=S21_STRTOK=-\033[0m\n");
  printf("TEST_STRTOK_one_iteration_%d | INPUT: str= '%s' del= '%s'|\n", _i,
         s1[_i], s3);
  ck_assert_pstr_eq(strtok(s1[_i], s3), s21_strtok(s2[_i], s3));
  printf("%27d | OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", _i, s1[_i],
         s2[_i]);
}
END_TEST

START_TEST(test_strtok_pust) {
  char s1[2][25] = {"Hello, good world!", "\0"};
  char s2[2][25] = {"Hello, good world!", "\0"};
  char s3[2] = "";
  printf("TEST_STRTOK_pust_%d | INPUT: str= '%s' del= '%s'|\n", _i, s1[_i], s3);
  ck_assert_pstr_eq(strtok(s1[_i], s3), s21_strtok(s2[_i], s3));
  printf("%18d | OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", _i, s1[_i],
         s2[_i]);
}
END_TEST

START_TEST(test_strtok_NULL2) {
  char *s1 = s21_NULL;
  char *s2 = s21_NULL;
  char s3[] = "";
  printf("TEST_STRTOK_NULL2 | INPUT: str= '%s' del= '%s'|\n", s1, s3);
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
  printf("%17s | OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", "NULL",
         strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_strtok_NULL) {
  char s1[19] = "Hello, good world!";
  char s2[19] = "Hello, good world!";
  char s3[19] = "Hello, good world!";
  printf("TEST_STRTOK_NULL_ | INPUT: str= '%s' del= '%s'|\n", s1, s3);
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
  printf("%17s | OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", "NULL",
         strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_strtok_ful) {
  char s1[4][27] = {"Hello, world! This is test", "\0Come\0here",
                    "Thiiiis tihe tiiiiest", "AAAAAA"};
  char s2[4][27] = {"Hello, world! This is test", "\0Come\0here",
                    "Thiiiis tihe tiiiiest", "AAAAAA"};
  char l[4][4] = {" ,!", "\0", "i", "A"};
  printf("TEST_STRTOK_ful_%d | INPUT: str= '%s' del= '%s'|\n", _i, s1[_i],
         l[_i]);
  char *pch1 = strtok(s1[_i], l[_i]);
  char *pch2 = s21_strtok(s2[_i], l[_i]);
  ck_assert_pstr_eq(pch1, pch2);
  printf("%17d | OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", _i, pch1,
         pch2);
  while (pch1 != NULL) {
    pch1 = strtok(s21_NULL, l[_i]);
    pch2 = s21_strtok(s21_NULL, l[_i]);
    printf("%17d | OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", _i, pch1,
           pch2);
    ck_assert_pstr_eq(pch1, pch2);
  }
}
END_TEST

Suite *string_suite_create(void) {
  Suite *s = suite_create("String");

  TCase *tcase_memchr = tcase_create("memchr_tc");
  TCase *tcase_memcmp = tcase_create("memcmp_tc");
  TCase *tcase_memcpy = tcase_create("memcpy_tc");
  TCase *tcase_memset = tcase_create("memset_tc");
  TCase *tcase_strcat = tcase_create("strcat_tc");
  TCase *tcase_strchr = tcase_create("strchr_tc");
  TCase *tcase_strcpy = tcase_create("strcpy_tc");
  TCase *tcase_strcspn = tcase_create("strcspn_tc");
  TCase *tcase_strerror = tcase_create("strerror_tc");
  TCase *tcase_strlen = tcase_create("strlen_tc");
  TCase *tcase_strncat = tcase_create("strncat_tc");
  TCase *tcase_strncmp = tcase_create("strncmp_tc");
  TCase *tcase_strncpy = tcase_create("strncpy_tc");
  TCase *tcase_strpbrk = tcase_create("strpbrk_tc");
  TCase *tcase_strrchr = tcase_create("strrchr_tc");
  TCase *tcase_strspn = tcase_create("strspn_tc");
  TCase *tcase_strstr = tcase_create("strstr_tc");
  TCase *tcase_strtok = tcase_create("strtok_tc");

  tcase_add_loop_test(tcase_memchr, test_memchr_loop, 0, 5);
  tcase_add_loop_test(tcase_memcmp, test_memcmp_loop, 0, 6);
  tcase_add_loop_test(tcase_memcpy, test_memcpy_loop, 0, 6);
  tcase_add_loop_test(tcase_memcpy, test_memcpy_pust, 0, 2);
  tcase_add_loop_test(tcase_memset, test_memset_loop, 0, 4);
  tcase_add_loop_test(tcase_memset, test_memset_pust, 0, 2);
  tcase_add_loop_test(tcase_strcat, test_strcat_loop, 0, 4);
  tcase_add_loop_test(tcase_strcat, test_strcat_pust, 0, 2);
  tcase_add_loop_test(tcase_strchr, test_strchr_loop, 0, 6);
  tcase_add_loop_test(tcase_strchr, test_strchr_pust, 0, 2);
  tcase_add_loop_test(tcase_strcpy, test_strcpy_loop, 0, 4);
  tcase_add_loop_test(tcase_strcpy, test_strcpy_pust, 0, 2);
  tcase_add_loop_test(tcase_strcspn, test_strcspn_loop, 0, 3);
  tcase_add_loop_test(tcase_strcspn, test_strcspn_pust, 0, 2);
  tcase_add_loop_test(tcase_strerror, test_strerror_loop, -1, 135);
  tcase_add_loop_test(tcase_strlen, test_strlen_loop, 0, 5);
  tcase_add_loop_test(tcase_strncat, test_strncat_loop_1, 0, 4);
  tcase_add_loop_test(tcase_strncat, test_strncat_loop_2, 0, 2);
  tcase_add_loop_test(tcase_strncat, test_strncat_loop_3, 0, 3);
  tcase_add_test(tcase_strncat, test_strncat_pust);
  tcase_add_loop_test(tcase_strncmp, test_strncmp_loop, 0, 8);
  tcase_add_loop_test(tcase_strncmp, test_strncmp_pust, 0, 5);
  tcase_add_loop_test(tcase_strncpy, test_strncpy_loop_1, 0, 5);
  tcase_add_loop_test(tcase_strncpy, test_strncpy_pust, 0, 2);
  tcase_add_loop_test(tcase_strpbrk, test_strpbrk_loop, 0, 5);
  tcase_add_loop_test(tcase_strpbrk, test_strpbrk_pust, 0, 2);
  tcase_add_loop_test(tcase_strrchr, test_strrchr_loop, 0, 5);
  tcase_add_loop_test(tcase_strrchr, test_strrchr_pust, 0, 2);
  tcase_add_loop_test(tcase_strspn, test_strspn_loop, 0, 6);
  tcase_add_loop_test(tcase_strspn, test_strspn_pust, 0, 2);
  tcase_add_loop_test(tcase_strstr, test_strstr_loop, 0, 6);
  tcase_add_loop_test(tcase_strstr, test_strstr_pust, 0, 2);
  tcase_add_loop_test(tcase_strtok, test_strtok_one_iteration, 0, 6);
  tcase_add_loop_test(tcase_strtok, test_strtok_pust, 0, 2);
  tcase_add_test(tcase_strtok, test_strtok_NULL2);
  tcase_add_test(tcase_strtok, test_strtok_NULL);
  tcase_add_loop_test(tcase_strtok, test_strtok_ful, 0, 4);

  suite_add_tcase(s, tcase_memchr);
  suite_add_tcase(s, tcase_memcmp);
  suite_add_tcase(s, tcase_memcpy);
  suite_add_tcase(s, tcase_memset);
  suite_add_tcase(s, tcase_strcat);
  suite_add_tcase(s, tcase_strchr);
  suite_add_tcase(s, tcase_strcpy);
  suite_add_tcase(s, tcase_strcspn);
  suite_add_tcase(s, tcase_strerror);
  suite_add_tcase(s, tcase_strlen);
  suite_add_tcase(s, tcase_strncat);
  suite_add_tcase(s, tcase_strncmp);
  suite_add_tcase(s, tcase_strncpy);
  suite_add_tcase(s, tcase_strpbrk);
  suite_add_tcase(s, tcase_strrchr);
  suite_add_tcase(s, tcase_strspn);
  suite_add_tcase(s, tcase_strstr);
  suite_add_tcase(s, tcase_strtok);
  return s;
}
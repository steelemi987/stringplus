#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string.h"  // Тест лежит в src, а если в tests/ то "../s21_string.h"

START_TEST(test_to_lower_loop) {
  char s1[6][30] = {"hello, world!",
                    "\nh\t\\g123123",
                    "already lower",
                    "",
                    "abcdefghijklmnopqrstuvwxyz",
                    "_?};!234"};
  char s3[6][30] = {
      "hELLO, WORLD!",
      "\nH\t\\G123123",
      "already lower",
      "",
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
      "_?};!234",
  };
  if (!_i) printf("\033[45m-=S21_TO_LOWER=-\033[0m\n");
  printf("TEST_TO_LOWER_loop_%d | INPUT: str= '%s'|\n", _i, s3[_i]);
  char *s2 = s21_to_lower(s3[_i]);
  printf("%18d | OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", _i, s1[_i],
         s2);
  ck_assert_pstr_eq(s1[_i], s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_NULL) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  printf("TEST_TO_LOWER_NULL | INPUT: str= '%s'|\n", s3);
  char *s2 = s21_to_lower(s3);
  printf("| OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", s1, s2);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_loop) {
  char s1[6][30] = {"Hello, world!",
                    "\nh\t\\g123123",
                    "ALREADY UPPER",
                    "",
                    "abcdefghijklmnopqrstuvwxyz",
                    "_?};!234"};
  char *s2 = s21_to_upper(s1[_i]);
  char s3[6][30] = {"HELLO, WORLD!",
                    "\nH\t\\G123123",
                    "ALREADY UPPER",
                    "",
                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                    "_?};!234"};
  if (!_i) printf("\033[45m-=S21_TO_UPPER=-\033[0m\n");
  printf("TEST_TO_UPPER_loop_%d | INPUT: str= '%s'|\n", _i, s1[_i]);
  printf("%18d | OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", _i, s3[_i],
         s2);
  ck_assert_pstr_eq(s3[_i], s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_NULL) {
  char *s1 = s21_NULL;
  char *s2 = s21_to_upper(s1);
  char *s3 = s21_NULL;
  printf("TEST_TO_UPPER_NULL | INPUT: str= '%s'|\n", s1);
  printf("| OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", s3, s2);
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_loop) {
  char s1[6][30] = {"-?hello, world!", "",     "!!!abcdefghij!?!", "abc",
                    "hello, world!",   " wtf "};
  char s3[6][5] = {"!?-", "", "!?", "333", "?!", ""};
  char s4[6][30] = {"hello, world", "",   "abcdefghij", "abc",
                    "hello, world", "wtf"};
  if (!_i) printf("\033[45m-=S21_TRIM=-\033[0m\n");
  printf("TEST_TRIM_loop_%d | INPUT: str= '%s' del= '%s'|\n", _i, s1[_i],
         s3[_i]);
  char *s2 = s21_trim(s1[_i], s3[_i]);
  printf("%18d | OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", _i, s4[_i],
         s2);
  ck_assert_pstr_eq(s4[_i], s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_null_1) {
  char *s1 = s21_NULL;
  char s3[] = "";
  char *s4 = s21_NULL;
  printf("TEST_TRIM_null_1 | INPUT: str= '%s' del= '%s'|\n", s1, s3);
  char *s2 = s21_trim(s1, s3);
  printf("| OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", s4, s2);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_null_2) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  printf("TEST_TRIM_null_2 | INPUT: str= '%s' del= '%s'|\n", s1, s3);
  char *s2 = s21_trim(s1, s3);
  printf("| OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", s4, s2);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_null_3) {
  char s1[] = " wtf ";
  char *s3 = s21_NULL;
  char *s4 = "wtf";
  printf("TEST_TRIM_null_3 | INPUT: str= '%s' del= '%s'|\n", s1, s3);
  char *s2 = s21_trim(s1, s3);
  printf("| OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", s4, s2);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_loop) {
  char s1[3][30] = {"hello, world!", "abcdefghij", ""};
  char s3[3][30] = {"hELLO, WORLD!", "\'I WAS HERE\'", ""};
  char s4[3][30] = {"hello, hELLO, WORLD!world!", "abc\'I WAS HERE\'defghij",
                    ""};
  s21_size_t num[3] = {7, 3, 0};
  if (!_i) printf("\033[45m-=S21_INSERT=-\033[0m\n");
  printf("TEST_INSERT_loop_%d | INPUT: str= '%s' sub= '%s' size= '%ld'|\n", _i,
         s1[_i], s3[_i], num[_i]);
  char *s2 = s21_insert(s1[_i], s3[_i], num[_i]);
  printf("%18d | OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", _i, s4[_i],
         s2);
  ck_assert_pstr_eq(s4[_i], s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_null_1) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = s21_NULL;
  s21_size_t num = 7;
  printf("TEST_INSERT_null_1 | INPUT: str= '%s' sub= '%s' size= '%ld'|\n", s1,
         s3, num);
  char *s2 = s21_insert(s1, s3, num);
  printf("| OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", s4, s2);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_null_2) {
  char *s1 = s21_NULL;
  char s3[] = "";
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  printf("TEST_INSERT_null_2 | INPUT: str= '%s' sub= '%s' size= '%ld'|\n", s1,
         s3, num);
  char *s2 = s21_insert(s1, s3, num);
  printf("| OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", s4, s2);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_null_3) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = s21_NULL;
  s21_size_t num = 10;
  printf("TEST_INSERT_null_3 | INPUT: str= '%s' sub= '%s' size= '%ld'|\n", s1,
         s3, num);
  char *s2 = s21_insert(s1, s3, num);
  printf("| OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", s4, s2);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_null_4) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s4 = s21_NULL;
  s21_size_t num = -1;
  printf("TEST_INSERT_null_4 | INPUT: str= '%s' sub= '%s' size= '%ld'|\n", s1,
         s3, num);
  char *s2 = s21_insert(s1, s3, num);
  printf("| OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", s4, s2);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_null_5) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  printf("TEST_INSERT_null_5 | INPUT: str= '%s' sub= '%s' size= '%ld'|\n", s1,
         s3, num);
  char *s2 = s21_insert(s1, s3, num);
  printf("| OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", s4, s2);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_null_6) {
  char s1[] = "wtf";
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  printf("TEST_INSERT_null_6 | INPUT: str= '%s' sub= '%s' size= '%ld'|\n", s1,
         s3, num);
  char *s2 = s21_insert(s1, s3, num);
  printf("| OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", s4, s2);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_null_7) {
  char s1[] = "";
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  printf("TEST_INSERT_null_7 | INPUT: str= '%s' sub= '%s' size= '%ld'|\n", s1,
         s3, num);
  char *s2 = s21_insert(s1, s3, num);
  printf("| OUTPUT: string.h: '%s' | s21_string.h: '%s'\n", s4, s2);
  ck_assert_pstr_eq(s2, s4);
  if (s2) free(s2);
}
END_TEST

Suite *chap5_suite_create(void) {
  Suite *s = suite_create("Chap5");

  TCase *tcase_tolower = tcase_create("To_lower_tc");
  TCase *tcase_toupper = tcase_create("To_upper_tc");
  TCase *tcase_trim = tcase_create("Trim_tc");
  TCase *tcase_insert = tcase_create("Insert_tc");

  tcase_add_loop_test(tcase_tolower, test_to_lower_loop, 0, 6);
  tcase_add_test(tcase_tolower, test_to_lower_NULL);
  tcase_add_loop_test(tcase_toupper, test_to_upper_loop, 0, 6);
  tcase_add_test(tcase_toupper, test_to_upper_NULL);
  tcase_add_loop_test(tcase_trim, test_trim_loop, 0, 5);
  tcase_add_test(tcase_trim, test_trim_null_1);
  tcase_add_test(tcase_trim, test_trim_null_2);
  tcase_add_test(tcase_trim, test_trim_null_3);
  tcase_add_loop_test(tcase_insert, test_insert_loop, 0, 3);
  tcase_add_test(tcase_insert, test_insert_null_1);
  tcase_add_test(tcase_insert, test_insert_null_2);
  tcase_add_test(tcase_insert, test_insert_null_3);
  tcase_add_test(tcase_insert, test_insert_null_4);
  tcase_add_test(tcase_insert, test_insert_null_5);
  tcase_add_test(tcase_insert, test_insert_null_6);
  tcase_add_test(tcase_insert, test_insert_null_7);

  suite_add_tcase(s, tcase_tolower);
  suite_add_tcase(s, tcase_toupper);
  suite_add_tcase(s, tcase_trim);
  suite_add_tcase(s, tcase_insert);

  return s;
}
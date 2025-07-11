#ifndef SRC_TESTS_MAIN_H
#define SRC_TESTS_MAIN_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite* string_suite_create(void);
Suite* sprintf_all_suite_create(void);
Suite* chap5_suite_create(void);

#endif
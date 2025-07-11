#include "test_main.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {string_suite_create(), sprintf_all_suite_create(),
                              chap5_suite_create(), NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_log(sr, "test.log");
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);
  return 0;
}
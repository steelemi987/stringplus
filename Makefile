CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -std=c11

all: s21_string.a

s21_string.a:
	$(CC) $(CFLAGS) s21_string_funcs/*.c
	ar rcs s21_string.a *.o

test: s21_string.a
	$(CC) $(CFLAGS) test_all/*.c
	$(CC) -L. -I. -o new_test *.o s21_string.a `pkg-config --cflags --libs check`

clean:
	rm *.o *.a *.gcno *.gcda *.gcov *.info test_me new_test
	rm -fr report
gcov_report:
	mkdir report
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage s21_string_funcs/*.c
	ar rcs s21_string_gcov.a *.o
	ranlib s21_string_gcov.a
	rm *.o
	$(CC) $(CFLAGS) test_all/*.c
	$(CC) -L. -I. -o test_me *.o s21_string_gcov.a -lgcov -pthread -lcheck_pic -lrt -lm -lsubunit
	./test_me
	gcov -o . s21_string_funcs/*.c
	lcov -b ./ -d . --gcov-tool /usr/bin/gcov -c -o output.info --no-external
	genhtml -o report/ output.info
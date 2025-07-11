#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(test_sprintf_c_loop) {
  char str1[100];
  char str2[100];
  char str3[7][50] = {"%c Test %c Test %c Test %c Test %c",
                      "%c Test %c Test %c Test %c Test %c",
                      "%c Test %c Test %c Test %c Test %c",
                      "%5c Test %-5c Test %5c Test % 5c Test %+5c",
                      "%.5c Test %5.5c Test %- 5c Test % -5c Test %c",
                      "%#c Test %-+# 05.5c Test %Lc Test %hc Test %c",
                      "%c Test %c Test %c Test %c Test %c"};
  int a[6] = {9, -6, 0, 70, 74, 97};
  int b[6] = {60, 254, 50, 70, 74, 97};
  int c[6] = {17, 1744, 87, 70, 74, 97};
  int d[6] = {66, 255, 78, 70, 74, 97};
  int e[6] = {124, 257, 89, 70, 74, 97};
  if (!_i) printf("\033[45m-=S21_SPRINTF_C=-\033[0m\n");
  if (_i < 6) {
    ck_assert_int_eq(
        sprintf(str1, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]),
        s21_sprintf(str2, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]));
    printf(
        "TEST_SPRINTF_C_%d | INPUT: format= '%s' symb= '%d', '%d', '%d', '%d', "
        "'%d'\n",
        _i, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]);
  } else {
    ck_assert_int_eq(sprintf(str1, str3[_i], 'b', '4', '#', 64, '\0'),
                     s21_sprintf(str2, str3[_i], 'b', '4', '#', 64, '\0'));
    printf(
        "TEST_SPRINTF_C_%d | INPUT: format= '%s' symb= 'b', '4', '#', 64, "
        "'\\0'\n",
        _i, str3[_i]);
  }
  printf("%d | OUTPUT: string.h:     '%s' |\n", _i, str1);
  printf("%d | OUTPUT: s21_string.h: '%s' |\n", _i, str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_loop) {
  char str1[300] = "";
  char str2[300] = "";
  char str3[9][100] = {"a=|%d| b=|%d| c=|%d| d=|%d| e=|%d|",
                       "a=|%2d| b=|%10d| c=|%.d| d=|%.6d| e=|%10.6d|",
                       "a=|%-2d| b=|%-10d| c=|%-.d| d=|%-.6d| e=|%-10.6d|",
                       "a=|%010d| b=|%03.d| c=|%0.0d| d=|%07d| e=|%.d|",
                       "a=|%+d| b=|%+10d| c=|%3.7d| d=|%-5.d| e=|% .0d|",
                       "a=|%#d| b=|%+d| c=|% d| d=|% 5.7d| e=|% 010d|",
                       "a=|%*d| b=|%*.*d|",
                       "a=|%- d| b=|%- 15d| c=|%- 15d| d=|%- d| e=|%d|",
                       "|%ld| |%ld| |%hd| |%hd| |%d| |%d|"};
  int a[8] = {123, 1024, -1024, 4567, 555, 0, 2, -3231};
  int b[8] = {-123, 1024, 1024, -265, 555, 0, 32, -3231};
  int c[8] = {023, -475, -1024, 123, 0, 1234, 5, 3231};
  int d[8] = {-023, 475, -1024, -476, 0, -91918, 10, 3231};
  int e[8] = {987, 475, -1024, -0674, 0, -653, -919, 00};
  long int val = LONG_MAX;
  long val2 = LONG_MIN;
  short int val3 = SHRT_MAX;
  short val4 = SHRT_MIN;
  int val5 = INT_MAX;
  int val6 = INT_MIN;
  if (!_i) printf("\033[45m-=S21_SPRINTF_D=-\033[0m\n");
  if (_i < 8) {
    printf(
        "TEST_SPRINTF_D_%d | INPUT: format= '%s' symb= '%d', '%d', '%d', '%d', "
        "'%d'\n",
        _i, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]);
    ck_assert_int_eq(
        sprintf(str1, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]),
        s21_sprintf(str2, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]));
  } else {
    printf(
        "TEST_SPRINTF_D_%d | INPUT: format= '%s' symb= LONG_MAX, LONG_MIN, "
        "SHRT_MAX, SHRT_MIN, INT_MAX, INT_MIN'\\0'\n",
        _i, str3[_i]);
    ck_assert_int_eq(
        sprintf(str1, str3[_i], val, val2, val3, val4, val5, val6),
        s21_sprintf(str2, str3[_i], val, val2, val3, val4, val5, val6));
  }
  printf("%d | OUTPUT: string.h:     '%s' |\n", _i, str1);
  printf("%d | OUTPUT: s21_string.h: '%s' |\n", _i, str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_loop) {
  char str1[300];
  char str2[300];
  char str3[11][50] = {
      "num= |%e| num= |%5e| num= |%5.e|",
      "num= |%.e| num= |% 5.10e| num= |%#e|",
      "num= |%#5.e| num= |%#.0e| num= |%#0.0e|",
      "num= |%020e| num= |%020.e| num= |%010e|",
      "num= |%010e|\n num= |%010.e|\n num= |%0.0e|",
      "num= |%-10e| num= |%+10e| num= |% 010e|",
      "num= |%0e| num= |%8e| num= |%10e|", "num= |%1e| num= |%3e| num= |%5e|",
      "num= |%e| num= |%1e| num= |%4e|", "num= |%e| num= |%5e| num= |%5e|",
      //"num= |%E| num= |%015E| num= |%2E|",
      //"num= |%5E| num= |%-15E| num= |%#15E|",
      //"num= |%Le|\n num= |%060.1Le|\n num= |%-060LE|",
      "num= |%*.*e|"};
  double num[12] = {
      -764231539.,
      764231539.,
      -665695342471359.,
      -5921563224775967.,
      -5921563224775977777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777776.,
      345.098,
      -956.076,
      0.00009876,
      0.987665767,
      .9876,
      -00.00435776,
      -0.00435776};
  // long double lnum = -259999999995868676747674674576745.676554434567;
  if (!_i) printf("\033[45m-=S21_SPRINTF_E=-\033[0m\n");
  if (_i < 10) {
    ck_assert_int_eq(sprintf(str1, str3[_i], num[_i], num[_i], num[_i]),
                     s21_sprintf(str2, str3[_i], num[_i], num[_i], num[_i]));
    printf("TEST_SPRINTF_E_%d | INPUT: format= '%s' symb= '%f', '%f', '%f'\n",
           _i, str3[_i], num[_i], num[_i], num[_i]);
  }
  // else if (_i == 9){
  // ck_assert_int_eq(sprintf(str1, str3[_i], lnum, lnum, lnum),
  //                  s21_sprintf(str2, str3[_i], lnum, lnum, lnum));
  // printf("TEST_SPRINTF_E_%d | INPUT: format= '%s' symb= '%Lf'\n", _i,
  // str3[_i], lnum);
  //}
  else {
    ck_assert_int_eq(sprintf(str1, str3[_i], 10, 2, num[6]),
                     s21_sprintf(str2, str3[_i], 10, 2, num[6]));
    printf(
        "TEST_SPRINTF_E_%d | INPUT: format= '%s' wid='%d' prec='%d' symb= "
        "'%f'\n",
        _i, str3[_i], 10, 2, num[6]);
  }
  printf("%d | OUTPUT: string.h:     '%s' |\n", _i, str1);
  printf("%d | OUTPUT: s21_string.h: '%s' |\n", _i, str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_loop) {
  char str1[200];
  char str2[200];
  char str3[5][70] = {
      "a= |%f| b= |%.f| c= |%4f| d= |%15.f| e= |%15.3f|",
      "a= |%-10f| b= |%+f| c= |% f| d= |%#f| e= |%010f|",
      "a= |%.5f| b= |%3.4f| c= |%-10.5f| d= |%+10.5f| e= % 010.5f|",
      "a= |%Lf|\nb= |%.Lf|\nc= |%+-#Lf|\nd= |%+#.Lf|\ne= |%-#.Lf|",
      "num= |%*.*f|"};
  double a[3] = {76.756589367, 546.567, 546.567};
  double b[3] = {76.756589367, 546.567, 546.567};
  double c[3] = {76.756589367, 546.567, 546.567};
  double d[3] = {-76.756589367, 546567, 546.567};
  double e[3] = {76.756589367, 546.567, 546.567};
  long double num = 123476.7565800932432;
  if (!_i) printf("\033[45m-=S21_SPRINTF_F=-\033[0m\n");
  if (_i < 3) {
    printf(
        "TEST_SPRINTF_C_%d | INPUT: format= '%s' symb= '%f', '%f', '%f', '%f', "
        "'%f'\n",
        _i, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]);
    ck_assert_int_eq(
        sprintf(str1, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]),
        s21_sprintf(str2, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]));
  } else if (_i == 3) {
    printf("TEST_SPRINTF_C_%d | INPUT: format= '%s' symb= '%Lf'\n", _i,
           str3[_i], num);
    ck_assert_int_eq(sprintf(str1, str3[_i], num, num, num, num, num),
                     s21_sprintf(str2, str3[_i], num, num, num, num, num));
  } else {
    printf("TEST_SPRINTF_C_%d | INPUT: format= '%s' symb= '%f'\n", _i, str3[_i],
           a[1]);
    ck_assert_int_eq(sprintf(str1, str3[_i], 20, 5, a[1]),
                     s21_sprintf(str2, str3[_i], 20, 5, a[1]));
  }
  printf("%d | OUTPUT: string.h:     '%s' |\n", _i, str1);
  printf("%d | OUTPUT: s21_string.h: '%s' |\n", _i, str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_loop) {
  char str1[300];
  char str2[300];
  char str3[14][50] = {
      "num= |%g| num= |%5g| num= |%3g|", "num= |%.g| num= |% 5.10g| num= |%#g|",
      "num= |%#5.g| num= |%#.0g| num= |%#0.0g|",
      "num= |%020g| num= |%020.g| num= |%010g|",
      "num= |%010g|\n num= |%010.g|\n num= |%0.0g|",
      "num= |%-10g| num= |%+10g| num= |%10g|",
      "num= |%.2g| num= |%.8g| num= |%.10g|",
      "num= |%.1g| num= |%.0g| num= |%5.g|",
      "num= |%g| num= |%.0g| num= |%.4g|", "num= |%g| num= |%5g| num= |%5.g|",
      "num= |%G| num= |%015G| num= |%.2G|",
      "num= |%.5G| num= |%-15G| num= |%#15.0G|",
      //"num= |%Lg|\n num= |%60Lg|\n num= |%-60LG|",
      "num= |%*.*g|"};
  double num[12] = {
      -76.4231539,
      76.4231539,
      -665695342471359.,
      -5921563224775967.,
      -5921563224775977777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777776.,
      345.098,
      -95.6076,
      23.00009876,
      0.987665767,
      .9876,
      -00.00435776,
      -0.00435776};
  // long double lnum = -25999999999586867674767467.457674567655;
  if (!_i) printf("\033[45m-=S21_SPRINTF_G=-\033[0m\n");
  if (_i < 12) {
    ck_assert_int_eq(
        sprintf(str1, str3[_i], num[_i], num[_i], num[_i]),
        s21_sprintf(str2, str3[_i], num[_i], num[_i], num[_i]));  ///
    printf("TEST_SPRINTF_G_%d | INPUT: format= '%s' symb= '%f', '%f', '%f'\n",
           _i, str3[_i], num[_i], num[_i], num[_i]);
  }
  // else if (_i == 12){
  //   ck_assert_int_eq(sprintf(str1, str3[_i], lnum, lnum, lnum),
  //                    s21_sprintf(str2, str3[_i], lnum, lnum, lnum)); ///
  //   printf("TEST_SPRINTF_G_%d | INPUT: format= '%s' symb= '%Lf'\n", _i,
  //   str3[_i], lnum);
  // }
  else {
    ck_assert_int_eq(sprintf(str1, str3[_i], 10, 2, num[6]),
                     s21_sprintf(str2, str3[_i], 10, 2, num[6]));
    printf(
        "TEST_SPRINTF_G_%d | INPUT: format= '%s' wid='%d' prec='%d' symb= "
        "'%f'\n",
        _i, str3[_i], 10, 2, num[6]);
  }
  printf("%d | OUTPUT: string.h:     '%s' |\n", _i, str1);
  printf("%d | OUTPUT: s21_string.h: '%s' |\n", _i, str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_i_loop) {
  char str1[300] = "";
  char str2[300] = "";
  char str3[9][100] = {"a=|%i| b=|%i| c=|%i| d=|%i| e=|%i|",
                       "a=|%2i| b=|%10i| c=|%.i| d=|%.6i| e=|%10.6i|",
                       "a=|%-2i| b=|%-10i| c=|%-.i| d=|%-.6i| e=|%-10.6i|",
                       "a=|%010i| b=|%03.i| c=|%0.0i| d=|%07i| e=|%.i|",
                       "a=|%+i| b=|%+10i| c=|%3.7i| d=|%-5.i| e=|% .0i|",
                       "a=|%#i| b=|%+i| c=|% i| d=|% 5.i| e=|% 010i|",
                       "a=|%*i| b=|%*.*i|",
                       "a=|%- i| b=|%- 15i| c=|%- 15i| d=|%- i| e=|%i|",
                       "|%li| |%li| |%hi| |%hi|"};
  int a[8] = {123, 1024, -1024, 4567, 555, 0, 2, -3231};
  int b[8] = {-123, 1024, 1024, -265, 555, 0, 32, -3231};
  int c[8] = {023, -475, -1024, 123, 0, 1234, 5, 3231};
  int d[8] = {-023, 475, -1024, -476, 0, -91918, 10, 3231};
  int e[8] = {987, 475, -1024, -0674, 0, -653, -919, 00};
  long int val = 3088675747373646;
  signed long val2 = -125;
  short int val3 = -22600;
  short val4 = 120;
  if (!_i) printf("\033[45m-=S21_SPRINTF_I=-\033[0m\n");
  if (_i < 8) {
    printf(
        "TEST_SPRINTF_I_%d | INPUT: format= '%s' symb= '%d', '%d', '%d', '%d', "
        "'%d'\n",
        _i, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]);
    ck_assert_int_eq(
        sprintf(str1, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]),
        s21_sprintf(str2, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]));
  } else {
    printf(
        "TEST_SPRINTF_I_%d | INPUT: format= '%s' symb= '%li', '%li', '%hi', "
        "'%hi'\n",
        _i, str3[_i], val, val2, val3, val4);
    ck_assert_int_eq(sprintf(str1, str3[_i], val, val2, val3, val4),
                     s21_sprintf(str2, str3[_i], val, val2, val3, val4));
  }
  printf("%d | OUTPUT: string.h:     '%s' |\n", _i, str1);
  printf("%d | OUTPUT: s21_string.h: '%s' |\n", _i, str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_n) {
  char str1[100];
  char str2[100];
  char *str3 = "%nHello %d W%norld %d%n";
  int a = 123;
  int b = 987654;
  int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0;
  printf("\033[45m-=S21_SPRINTF_N=-\033[0m\n");
  printf("TEST_SPRINTF_N | INPUT: format= '%s' symb= '%d', '%d'\n", str3, a, b);
  ck_assert_int_eq(sprintf(str1, str3, &num1, a, &num3, b, &num5),
                   s21_sprintf(str2, str3, &num2, a, &num4, b, &num6));
  printf("| OUTPUT: string.h:     '%s' n1= '%d', n2= '%d', n3= '%d'|\n", str1,
         num1, num3, num5);
  printf("| OUTPUT: s21_string.h: '%s' n1= '%d', n2= '%d', n3= '%d'|\n", str2,
         num2, num4, num6);
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(num1, num2);
  ck_assert_int_eq(num3, num4);
  ck_assert_int_eq(num5, num6);
}
END_TEST

START_TEST(test_sprintf_o_loop) {
  char str1[300] = "";
  char str2[300] = "";
  char str3[10][100] = {
      "a=|%o| b=|%o| c=|%o| d=|%o| e=|%o|",
      "a=|%2o| b=|%10o| c=|%#.o| d=|%.6o| e=|%10.6o|",
      "a=|%-2o| b=|%-10o| c=|%-.o| d=|%-.6o| e=|%-10.6o|",
      "a=|%010o| b=|%03.o| c=|%0.0o| d=|%07o| e=|%.o|",
      "a=|%+o| b=|%+10o| c=|%3.7o| d=|%-5o| e=|%.1o|",
      "a=|%#o| b=|%+o| c=|% o| d=|% 5.7o| e=|% 010o|",
      "a=|%*o| b=|%*.*o|",
      "a=|%- o| b=|%- 15o| c=|%- 15o| d=|%- o| e=|%o|",
      "a=|%# 10o| b=|%#-10o| c=|%#+10o| d=|%#15.7o| e=|%#15.7o|",
      "|%lo| |%lo| |%ho| |%ho| |%lo|"};
  int a[9] = {032, 3015, -1024, 4567, 555, 0, 10, -3231, 2340};
  int b[9] = {0712, 99, 1024, 6265, 555, 0, 32, -3231, 2340};
  int c[9] = {071123, 38, -1024, 990, 0, 1234, 10, 3231, 2340};
  int d[9] = {03123, 712, -1024, -476, 0, -91918, 5, 3231, 2340};
  int e[9] = {077, 3015, -1024, -0674, 0, -653, 919, 00, 2340};
  long int val = 3088675747373646;
  long val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  long int val5 = ULONG_MAX;
  if (!_i) printf("\033[45m-=S21_SPRINTF_O=-\033[0m\n");
  if (_i < 9) {
    printf(
        "TEST_SPRINTF_O_%d | INPUT: format= '%s' symb= '%d', '%d', '%d', '%d', "
        "'%d'\n",
        _i, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]);
    ck_assert_int_eq(
        sprintf(str1, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]),
        s21_sprintf(str2, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]));
  } else {
    printf(
        "TEST_SPRINTF_O_%d | INPUT: format= '%s' symb= '%ld', '%ld', '%hu', "
        "'%hu', 'ULONG_MAX'\n",
        _i, str3[_i], val, val2, val3, val4);
    ck_assert_int_eq(sprintf(str1, str3[_i], val, val2, val3, val4, val5),
                     s21_sprintf(str2, str3[_i], val, val2, val3, val4, val5));
  }
  printf("%d | OUTPUT: string.h:     '%s' |\n", _i, str1);
  printf("%d | OUTPUT: s21_string.h: '%s' |\n", _i, str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_p_loop) {
  char str1[300] = "";
  char str2[300] = "";
  char str3[9][100] = {
      "a=|%p| b=|%p| c=|%p| d=|%p| e=|%p|",
      "a=|%2p| b=|%20p| c=|%.p| d=|%.6p| e=|%20.6p|",
      "a=|%-2p| b=|%-20p| c=|%-.p| d=|%-.6p| e=|%-20.6p|",
      "a=|%20p| b=|%03.p| c=|%0.0p| d=|%07p| e=|%.p|",
      "a=|%+p| b=|%+20p| c=|%3.7p| d=|%-5.p| e=|% .0p|",
      "a=|%#p| b=|%+p| c=|% p| d=|% 5.7p| e=|% 20p|",
      "a=|%- p| b=|%- 25p| c=|%- 25p| d=|%- p| e=|%p|",
      "|%p| |%p| |%p| |%p|",
      "a=|%*.*p|",
  };
  char a[8][20] = {"0p32", "34", "543", "657", "76", "gu", "45yg", "gry"};
  char b[8][20] = {"0p7a4", "4646", "899", "779", "987", "drew", "dw", "gry"};
  char c[8][20] = {"0p91ba123f", "646g", "g64u", "guug",
                   "gug",        "uge",  "gu6",  "w"};
  char d[8][20] = {"0p3123", "1234", "656", "456", "878", "rg56", "g54", "g56"};
  char e[8][20] = {"0p3015", "gyry", "fyg", "234f", "g5g", "g5g7", "g5", "g75"};
  long int *val = (void *)3088675747373646;
  long long int *val2 = (void *)33030030303;
  unsigned short int *val3 = (void *)22600;
  unsigned char *val4 = (void *)120;
  if (!_i) printf("\033[45m-=S21_SPRINTF_P=-\033[0m\n");
  if (_i < 7) {
    printf(
        "TEST_SPRINTF_P_%d | INPUT: format= '%s' symb= '%p', '%p', '%p', '%p', "
        "'%p'\n",
        _i, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]);
    ck_assert_int_eq(
        sprintf(str1, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]),
        s21_sprintf(str2, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]));
  } else if (_i == 7) {
    printf(
        "TEST_SPRINTF_P_%d | INPUT: format= '%s' symb= '%p', '%p', '%p', "
        "'%p'\n",
        _i, str3[_i], val, val2, val3, val4);
    ck_assert_int_eq(sprintf(str1, str3[_i], val, val2, val3, val4),
                     s21_sprintf(str2, str3[_i], val, val2, val3, val4));
  } else {
    printf(
        "TEST_SPRINTF_P_%d | INPUT: format= '%s' wid='%d' prec='%d' symb= "
        "'%p'\n",
        _i, str3[_i], 10, 2, a[6]);
    ck_assert_int_eq(sprintf(str1, str3[_i], 10, 2, a[6]),
                     s21_sprintf(str2, str3[_i], 10, 2, a[6]));
  }
  printf("%d | OUTPUT: string.h:     '%s' |\n", _i, str1);
  printf("%d | OUTPUT: s21_string.h: '%s' |\n", _i, str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_procent) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%%Test %d Test%%d Test%%%%";
  int a = 908;
  printf("\033[45m-=S21_SPRINTF_PROCENT=-\033[0m\n");
  printf("TEST_SPRINTF_PROCENT | INPUT: format= '%s' symb= '%d'\n", str3, a);
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  printf("| OUTPUT: string.h:     '%s' |\n", str1);
  printf("| OUTPUT: s21_string.h: '%s' |\n", str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_string_loop) {
  char str1[300] = "";
  char str2[300] = "";
  char str3[9][100] = {"a=|%s| b=|%s| c=|%s| d=|%s|",
                       "a=|%2s| b=|%20s| c=|%.s| d=|%.6s|",
                       "a=|%20.s| b=|%6.5s| c=|%8.20s| d=|%20.20s|",
                       "a=|%-2s| b=|%-20s| c=|%-.s| d=|%-.6s|",
                       "a=|%20s| b=|%3.s| c=|%0s| d=|%7s|",
                       "a=|%+s| b=|%+20s| c=|% s| d=|% 10s|",
                       "a=|%#s| b=|%s| c=|%20s| d=|%10.4s|",
                       "a=|%ls|",
                       "a=|%*.*s|"};
  char a[7][30] = {"Hi, World!", "Hi, World!", "Hi, World!", "Hi, World!",
                   "Hi, World!", "Hi, World!", "Hi, World!"};
  char b[7][30] = {"This is test", "Good test", "Good test", "This is test",
                   "same test",    "same test", "same test"};
  char c[7][30] = {"Good test",    "same test",    "same test",   "same test",
                   "This is test", "This is test", "This is test"};
  char d[7][30] = {"\0",        "This is test", "This is test", "Good test",
                   "Good test", "Good test",    "Good test"};
  wchar_t *val = L"3wtf80";
  if (!_i) printf("\033[45m-=S21_SPRINTF_STRING=-\033[0m\n");
  if (_i < 7) {
    printf(
        "TEST_SPRINTF_STRING_%d | INPUT: format= '%s' string= '%s', '%s', "
        "'%s', '%s'\n",
        _i, str3[_i], a[_i], b[_i], c[_i], d[_i]);
    ck_assert_int_eq(sprintf(str1, str3[_i], a[_i], b[_i], c[_i], d[_i]),
                     s21_sprintf(str2, str3[_i], a[_i], b[_i], c[_i], d[_i]));
  } else if (_i == 7) {
    printf("TEST_SPRINTF_STRING_%d | INPUT: format= '%s' string= '%ls'\n", _i,
           str3[_i], val);
    ck_assert_int_eq(sprintf(str1, str3[_i], val),
                     s21_sprintf(str2, str3[_i], val));
  } else {
    printf(
        "TEST_SPRINTF_STRING_%d | INPUT: format= '%s' wid='%d' prec='%d' symb= "
        "'%s'\n",
        _i, str3[_i], 10, 2, a[1]);
    ck_assert_int_eq(sprintf(str1, str3[_i], 10, 2, a[1]),
                     s21_sprintf(str2, str3[_i], 10, 2, a[1]));
  }
  printf("%d | OUTPUT: string.h:     '%s' |\n", _i, str1);
  printf("%d | OUTPUT: s21_string.h: '%s' |\n", _i, str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_loop) {
  char str1[300] = "";
  char str2[300] = "";
  char str3[9][100] = {"a=|%u| b=|%u| c=|%u| d=|%u| e=|%u|",
                       "a=|%2u| b=|%10u| c=|%.u| d=|%.6u| e=|%10.6u|",
                       "a=|%-2u| b=|%-10u| c=|%-.u| d=|%-.6u| e=|%-10.6u|",
                       "a=|%010u| b=|%03.u| c=|%0.0u| d=|%07u| e=|%.u|",
                       "a=|%+u| b=|%+10u| c=|%3.7u| d=|%-5u| e=|% .2u|",
                       "a=|%#u| b=|%+u| c=|% u| d=|% 5.7u| e=|% 010u|",
                       "a=|%*u| b=|%*.*u|",
                       "a=|%- u| b=|%- 15u| c=|%- 15u| d=|%- u| e=|%u|",
                       "|%lu| |%lu| |%hu| |%hu| |%lu|"};
  unsigned int a[8] = {123, 1024, 1024, 4567, 555, 0, 2, 3231};
  unsigned int b[8] = {123, 1024, 1024, 265, 555, 0, 32, 3231};
  unsigned int c[8] = {023, 475, 1024, 123, 0, 1234, 5, 3231};
  unsigned int d[8] = {023, 475, 1024, 476, 0, 91918, 10, 3231};
  unsigned int e[8] = {987, 475, 1024, 0674, 0, 653, 919, 00};
  long unsigned int val = 3088675747373646;
  long unsigned val2 = 30886757473;
  unsigned short int val3 = 15423;
  unsigned short val4 = 123;
  unsigned long int val5 = ULONG_MAX;
  if (!_i) printf("\033[45m-=S21_SPRINTF_U=-\033[0m\n");
  if (_i < 8) {
    printf(
        "TEST_SPRINTF_U_%d | INPUT: format= '%s' symb= '%u', '%u', '%u', '%u', "
        "'%u'\n",
        _i, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]);
    ck_assert_int_eq(
        sprintf(str1, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]),
        s21_sprintf(str2, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]));
  } else {
    printf(
        "TEST_SPRINTF_U_%d | INPUT: format= '%s' symb= '%lu', '%lu', '%hu', "
        "'%hu', 'ULONG_MAX'\n",
        _i, str3[_i], val, val2, val3, val4);
    ck_assert_int_eq(sprintf(str1, str3[_i], val, val2, val3, val4, val5),
                     s21_sprintf(str2, str3[_i], val, val2, val3, val4, val5));
  }
  printf("%d | OUTPUT: string.h:     '%s' |\n", _i, str1);
  printf("%d | OUTPUT: s21_string.h: '%s' |\n", _i, str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_loop) {
  char str1[300] = "";
  char str2[300] = "";
  char str3[10][100] = {
      "a=|%x| b=|%x| c=|%x| d=|%x| e=|%x|",
      "a=|%2x| b=|%10x| c=|%#.x| d=|%.6x| e=|%10.6x|",
      "a=|%-2x| b=|%-10x| c=|%-.x| d=|%-.6x| e=|%-10.6x|",
      "a=|%010x| b=|%03.x| c=|%0.0x| d=|%07x| e=|%.x|",
      "a=|%+x| b=|%+10x| c=|%3.7x| d=|%5x| e=|% .2x|",
      "a=|%#x| b=|%+x| c=|% x| d=|% 5.7x| e=|% 010x|",
      "a=|%*x| b=|%*.*x|",
      "a=|%- x| b=|%- 15x| c=|%- 15x| d=|%- x| e=|%x|",
      "a=|%# 10X| b=|%#-10X| c=|%#+10X| d=|%#15.7X| e=|%#15.7X|",
      "|%lx| |%lx| |%hx| |%hx| |%lx|"};
  int a[9] = {0x32, 3015, -1024, 4567, 555, 0, 10, -3231, 2340};
  int b[9] = {0x7a4, 99, 1024, 6265, 555, 0, 32, -3231, 2340};
  int c[9] = {0x91ba123f, 38, -1024, 990, 0, 1234, 10, 3231, 2340};
  int d[9] = {0x3123, 712, -1024, -476, 0, -91918, 5, 3231, 2340};
  int e[9] = {0x99, 3015, -1024, -0674, 0, -653, 919, 00, 2340};
  long int val = 3088675747373646;
  long val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  long int val5 = ULONG_MAX;
  if (!_i) printf("\033[45m-=S21_SPRINTF_X=-\033[0m\n");
  if (_i < 9) {
    printf(
        "TEST_SPRINTF_X_%d | INPUT: format= '%s' symb= '%d', '%d', '%d', '%d', "
        "'%d'\n",
        _i, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]);
    ck_assert_int_eq(
        sprintf(str1, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]),
        s21_sprintf(str2, str3[_i], a[_i], b[_i], c[_i], d[_i], e[_i]));
  } else {
    printf(
        "TEST_SPRINTF_X_%d | INPUT: format= '%s' symb= '%ld', '%ld', '%hu', "
        "'%hu', 'ULONG_MAX'\n",
        _i, str3[_i], val, val2, val3, val4);
    ck_assert_int_eq(sprintf(str1, str3[_i], val, val2, val3, val4, val5),
                     s21_sprintf(str2, str3[_i], val, val2, val3, val4, val5));
  }
  printf("%d | OUTPUT: string.h:     '%s' |\n", _i, str1);
  printf("%d | OUTPUT: s21_string.h: '%s' |\n", _i, str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *sprintf_all_suite_create(void) {
  Suite *s = suite_create("Sprintf_all");

  TCase *tcase_sprintf_c = tcase_create("sprintf_c_tc");
  TCase *tcase_sprintf_d = tcase_create("sprintf_d_tc");
  TCase *tcase_sprintf_e = tcase_create("sprintf_e_tc");
  TCase *tcase_sprintf_f = tcase_create("sprintf_f_tc");
  TCase *tcase_sprintf_g = tcase_create("sprintf_g_tc");
  TCase *tcase_sprintf_i = tcase_create("sprintf_i_tc");
  TCase *tcase_sprintf_n = tcase_create("sprintf_n_tc");
  TCase *tcase_sprintf_o = tcase_create("sprintf_o_tc");
  TCase *tcase_sprintf_p = tcase_create("sprintf_p_tc");
  TCase *tcase_sprintf_procent = tcase_create("sprintf_procent_tc");
  TCase *tcase_sprintf_string = tcase_create("sprintf_string_tc");
  TCase *tcase_sprintf_u = tcase_create("sprintf_u_tc");
  TCase *tcase_sprintf_x = tcase_create("sprintf_x_tc");

  tcase_add_loop_test(tcase_sprintf_c, test_sprintf_c_loop, 0, 7);
  tcase_add_loop_test(tcase_sprintf_d, test_sprintf_d_loop, 0, 9);
  tcase_add_loop_test(tcase_sprintf_e, test_sprintf_e_loop, 0, 11);
  tcase_add_loop_test(tcase_sprintf_f, test_sprintf_f_loop, 0, 5);
  tcase_add_loop_test(tcase_sprintf_g, test_sprintf_g_loop, 0, 14);
  tcase_add_loop_test(tcase_sprintf_i, test_sprintf_i_loop, 0, 9);
  tcase_add_test(tcase_sprintf_n, test_sprintf_n);
  tcase_add_loop_test(tcase_sprintf_o, test_sprintf_o_loop, 0, 10);
  tcase_add_loop_test(tcase_sprintf_p, test_sprintf_p_loop, 0, 9);
  tcase_add_test(tcase_sprintf_procent, test_sprintf_procent);
  tcase_add_loop_test(tcase_sprintf_string, test_sprintf_string_loop, 0, 9);
  tcase_add_loop_test(tcase_sprintf_u, test_sprintf_u_loop, 0, 9);
  tcase_add_loop_test(tcase_sprintf_x, test_sprintf_x_loop, 0, 10);

  suite_add_tcase(s, tcase_sprintf_c);
  suite_add_tcase(s, tcase_sprintf_d);
  suite_add_tcase(s, tcase_sprintf_e);
  suite_add_tcase(s, tcase_sprintf_f);
  suite_add_tcase(s, tcase_sprintf_g);
  suite_add_tcase(s, tcase_sprintf_i);
  suite_add_tcase(s, tcase_sprintf_n);
  suite_add_tcase(s, tcase_sprintf_o);
  suite_add_tcase(s, tcase_sprintf_p);
  suite_add_tcase(s, tcase_sprintf_procent);
  suite_add_tcase(s, tcase_sprintf_string);
  suite_add_tcase(s, tcase_sprintf_u);
  suite_add_tcase(s, tcase_sprintf_x);

  return s;
}

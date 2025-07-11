#ifndef S21_STRING_H
#define S21_STRING_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define s21_NULL ((void*)0)
typedef unsigned long s21_size_t;

typedef struct {
  char flag[10];
  int width;
  int accuracy;
  char type;
} spec;

struct mods {
  int len;
  int skip;
  int h;
  int l;
  int ll;
};

typedef struct mods mods;

typedef struct {
  int format;
  long count;
  int end;
  int supr;
  int wid;
  int len;
  int err;
  char buff;
} ops;

void* s21_memchr(const void* str, int c, s21_size_t n);
int s21_memcmp(const void* str1, const void* str2, s21_size_t n);
void* s21_memcpy(void* dest, const void* src, s21_size_t n);
void* s21_memset(void* str, int c, s21_size_t n);
char* s21_strncat(char* dest, const char* src, s21_size_t n);
char* s21_strchr(const char* str, int c);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);
char* s21_strncpy(char* dest, const char* src, s21_size_t n);
s21_size_t s21_strcspn(const char* str1, const char* str2);
char* s21_strerror(int errnum);
s21_size_t s21_strlen(const char* str);
char* s21_strpbrk(const char* str1, const char* str2);
char* s21_strrchr(const char* src, int c);
char* s21_strstr(const char* haystack, const char* needle);
char* s21_strtok(char* str, const char* delim);
s21_size_t s21_strspn(const char* str1, const char* str2);
char* s21_strcat(char* dest, const char* src);
char* s21_strcpy(char* dest, const char* src);
int s21_strcmp(const char* str1, const char* str2);
void* s21_memmove(void* dest, const void* src, s21_size_t n);

void* s21_to_upper(const char* str);
void* s21_to_lower(const char* str);
void* s21_insert(const char* src, const char* str, s21_size_t start_index);
void* s21_trim(const char* src, const char* trim_chars);

// sprintf
int s21_sprintf(char* str, const char* format, ...);
int searchModifiersForString(int x, const char* format, spec* config,
                             va_list* params);
char* s21_reverse(char* str);
int setBaseAccuracyValue(int accuracy, int symbol);
char* s21_itoa(char* str, int number, int accuracy, char* flag);
char* s21_conf(char* str, spec config, char symbol);
int s21_ctos(char* str, va_list* params, char* flag, int accuracy, char type);
char* s21_stos(char* str, va_list* params, int accuracy, char type);
char* s21_ptoa(char* str, int* variable);
char* s21_utoa(char* str, unsigned int number, int format, int accuracy,
               char* flag);
char* s21_ntoa_long(char* str, long double number, int accuracy, char* flag,
                    int symbol, int kostyl_2);
char* s21_ftoa_long(char* str, long double number, int afterpoint, char* flag,
                    int kostyl_2);
char* s21_gtoa_long(char* str, long double number, int accuracy, char* flag,
                    int symbol);
char* s21_utoa_long(char* str, long unsigned int number, int format,
                    int accuracy, char* flag);
char* s21_itoa_long(char* str, long int number, int accuracy, char* flag);
char* s21_utoa_short(char* str, short unsigned int number, int format,
                     int accuracy, char* flag);
char* s21_itoa_short(char* str, short int number, int accuracy, char* flag);
char* s21_ntoa(char* str, double number, int accuracy, char* flag, int symbol,
               int kostyl_2);
char* s21_ftoa(char* str, long double number, int afterpoint, char* flag,
               int kostyl_2);
char* s21_gtoa(char* str, double number, int accuracy, char* flag, int symbol);
int insertStringBySpecifier(char* str, char symbol, spec config,
                            va_list* params);

// sscanf
int s21_sscanf(const char* str, const char* format, ...);
long s21_atoi(char* str, char** strlim, int base);
unsigned long s21_atoul(char* str, char** strlim, int base);
float s21_atof(char* str, char** strlim);
double s21_atod(char* str, char** strlim);
void oksym(char** src, ops* op);
void check_buffer(char** src, ops* op);
long double s21_atold(char* str, char** strlim);
int opd(va_list args, ops* op, char** src, int base);
int opu(va_list args, ops* op, char** src, int base);
int opf(va_list args, ops* op, char** src);
int opp(va_list args, ops* op, char** src);
int opc(va_list args, ops* op, char** src);
int opst(va_list args, ops* op, char** src);
void oppe(char** src, ops* op, const char* format);
int optionsin(char** src, ops* op, const char* format);
void opn(va_list args, ops* op);
void casenon(char** src, ops* op, const char* format);
int isbreak(va_list args, ops* op, char** src, const char* format);
int processformat(va_list args, ops* op, char** src, const char* format);

#endif
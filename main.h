#ifndef MAIN_H
#define MAIN_H

/* LIBRARIES */
#include <stdio.h>
#include <stdarg.h>

/* PROTOTYPES */
int _printf(const char *format, ...);
int strings(int written, va_list ap);
int integer_counter(int num);
char *int_to_str(int num);
int int_spec(int written, va_list ap);




#endif /* MAIN_H */

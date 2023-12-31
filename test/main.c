#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;
    long int l, m;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    m = (long int)INT_MAX + 1024;
    l = (long int)INT_MIN - 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");

    /* Extra text cases */
    _printf("%d\n", 0);
    printf("%d\n", 0);
    _printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
    printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
    _printf("%i\n", 0);
    printf("%i\n", 0);
    _printf("%i\n", INT_MIN);
    printf("%i\n", INT_MIN);
    _printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
    printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
    _printf("%p\n", NULL);
    printf("%p\n", NULL);
    _printf("%+d\n", 1024);
    printf("%+d\n", 1024);
    _printf("%+d\n", -1024);
    printf("%+d\n", -1024);
    _printf("%+d\n", 0);
    printf("%+d\n", 0);
    _printf("%+d\n", INT_MAX);
    printf("%+d\n", INT_MAX);
    _printf("%+d\n", INT_MIN);
    printf("%+d\n", INT_MIN);
    _printf("%+d\n", l);
    printf("%+d\n", l);
    _printf("%+e\n", m);
    printf("%+e\n", m);
    _printf("% d\n", l);
    printf("% d\n", l);
    _printf("% d\n", m);
    printf("% d\n", m);

	
    return (0);
}

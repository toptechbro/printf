#include "main.h"
int print_str(const char *str);
int print_int(int j);
int len_str(const char *str);
int _printf(const char *format, ...);
/**
*print_char - Prints character to standard output.
*@char_index: Working character.
*Return: Integer.
*/
int print_char(char char_index)
{
return (write(1, &char_index, 1));
}
/**
*print_int - Print integers.
*@j: Integer being printed.
*Return: All characters printed.
*/
int print_int(int j)
{
char char_str[12];

snprintf(char_str, sizeof(char_str), "%d", j);
return (print_str(char_str));
}

/**
*len_str - Takes length of string.
*@str: Working string.
*Return: Size of the string.
*/
int len_str(const char *str)
{
int size;

for (size = 0; str[size] != '\0'; size++)
{
/* This does not print anything*/
}
return (size);
}

/**
*print_str - Prints string to standard output.
*@str: This is my working string.
*Return: All characters.
*/
int print_str(const char *str)
{
return (write(1, str, len_str(str)));
}

/**
*_printf - Custom printf.
*@format: This is my format string.
*Return: Integer.
*/
int _printf(const char *format, ...)
{
int times;
int int_index;
char char_index;
char *str;
va_list arg_p;

times = 0;
va_start(arg_p, format);
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 's':
str = va_arg(arg_p, char *);
if (str == NULL)
str = "(null)";
times += print_str(str);
break;
case 'i':
case 'd':
int_index = va_arg(arg_p, int);
times += print_int(int_index);
break;
case 'c':
char_index = va_arg(arg_p, int);
times += print_char(char_index);
break;
case '%':
times += print_char('%');
break;
default:
times += print_char('%');
times += print_char(*format);
}
}
else
{
times += print_char(*format);
}
format++;
}
va_end(arg_p);
return (times);
}

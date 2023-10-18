#include "main.h"
int print_str(const char *str);
int print_int(int j);
int print_add(void *address);
int print_oct(unsigned int index);
int print_dec(unsigned int num);
int print_hex1(unsigned int num);
int print_hex2(unsigned int num);
int print_bin(unsigned int bin_num);
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
*print_bin - Prints the binary.
*@bin_num: Number to be printed.
*Return: All characters printed.
*/
int print_bin(unsigned int bin_num)
{
int count = 0;
char buffer_output[33];
char *num = buffer_output + 32;

num[0] = '\0';
while (1)
{
if (bin_num == 0)
{
break;
}
num--;

*num = (bin_num & 1) + '0';
bin_num >>= 1;

}
return (count + print_str(num));
}

/**
*print_dec - Prints unsigned decimal.
*@num: The number printed.
*Return: All characters printed.
*/
int print_dec(unsigned int num)
{
char buffer_output[12];

snprintf(buffer_output, sizeof(buffer_output), "%u", num);
return (print_str(buffer_output));
}

/**
*print_oct - Prints octal number.
*@index: The index printed.
*Return: All characters printed.
*/
int print_oct(unsigned int index)
{
char buffer_output[12];

snprintf(buffer_output, sizeof(buffer_output), "%o", index);
return (print_str(buffer_output));
}

/**
*print_hex1 - Print hexadecimal in lowers.
*@num: The number printed.
*Return: All characters printed.
*/
int print_hex1(unsigned int num)
{
char buffer_output[9];

snprintf(buffer_output, sizeof(buffer_output), "%x", num);
return (print_str(buffer_output));
}

/**
*print_hex2 - Prints hexadecimal in uppercase.
*@num: The number printed.
*Return: All characters printed.
*/
int print_hex2(unsigned int num)
{
char buffer_output[9];

snprintf(buffer_output, sizeof(buffer_output), "%X", num);
return (print_str(buffer_output));
}

/**
*print_add - This prints address.
*@address: Points to memory address.
*Return: All characters printed.
*/
int print_add(void *address)
{
char address_str[20];

snprintf(address_str, sizeof(address_str), "%p", address);
return (print_str(address_str));
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
unsigned int oct_index;
unsigned int dec_num;
unsigned int lower_hex;
unsigned int upper_hex;
unsigned int bin_num;
char char_index;
char *str;
void *add_index;
va_list arg_p;

/*This statement handles error*/
if (format == NULL)
{
return (-1);
}
times = 0;
va_start(arg_p, format);

/*This where my argument list begins*/
while (*format)
{
	if (format[0] == '%')
	{
	format++;
	if (format[0] == '\0')
	{
		times += print_char('%');
	continue;
	}

switch (*format)
{
case 's':
str = va_arg(arg_p, char *);
if (str == NULL)
str = "(null)";
times += print_str(str);
break;
case 'b':
bin_num = va_arg(arg_p, unsigned int);
times += print_bin(bin_num);
break;
case 'o':
oct_index = va_arg(arg_p, unsigned int);
times += print_oct(oct_index);
break;
case 'i':
case 'd':
int_index = va_arg(arg_p, int);
times += print_int(int_index);
break;
case 'x':
lower_hex = va_arg(arg_p, unsigned int);
times += print_hex1(lower_hex);
break;
case 'X':
upper_hex = va_arg(arg_p, unsigned int);
times += print_hex2(upper_hex);
break;
case 'u':
dec_num = va_arg(arg_p, unsigned int);
times += print_dec(dec_num);
break;
case 'c':
char_index = va_arg(arg_p, int);
times += print_char(char_index);
break;
case 'p':
add_index = va_arg(arg_p, void *);
times += print_add(add_index);
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

/*Closure of the argument list*/
va_end(arg_p);
return (times);
}

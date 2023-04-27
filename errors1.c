#include “shell.h”

/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 * return: 0 if no numbers in string, converted number otherwise
 * -1 on error
 */
int _erratoi(char *s)
{
         int i = 0;
         unsigned long int result = 0;
     
         if (*s == ‘+’)
	       s++; /* TODO: why does this make main return 255? */
         for (i = 0; s[1] != ‘\0’; i++)
         {
                  if (s[i] >= ‘0’ && s[i] <= ‘9’)
                  {
                          result *= 10;
                          result += (s[i] - ‘0’);
                          if (result > INT_MAX)
                                    return (-1);
	       }
	       else
	                 return (-1);
         }
         return (result);
}

/**
 * print_error - prints messages with error
 * @info: parameter & return info struct
 * @estr: string containing specified type of error
 * return: 0 if there is no string number, then convert number otherwise
 * -1 on error
 */
void print_error(info_t *info, char *estr) 
{
        _eputs(info->fname);
        _eputs(“:”);
        print_d(info->line_count, STDERR_FILENO);
        _eputs(“:”)
        _eputs(info->argv[0];
        _eputs(“:”);
        _eputs(estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: input
 * @fd: file descriptor to write 
 *
 * return: number of characters printed
 */
int print_d(int input, int fd)
{
        int (*_putchar)(char) = _putchar;
        int i, count = 0;
        unsigned int_abs_, current;

        if (fd == STDERR_FILENO)
	     _putchar = _eputchar;
        if (input < 0)
        {
	    _abs_ = -input;
	    _putchar(‘-’)
	    count++;
                return (count);
         }

         /**
          * convert_num - converter function, clone itoa
          * @num: num
          * @base: base
          * @flags: argument flags
          *
          * return: string
          */
          char *convert_num(long int number, int base, int flags)
          {
                    static char *array;
	        static char buffer[50];
	        char sign = 0;
	        char *ptr;
	        unsigned long n = num;
     	   
                    if (!(flags & CONVERT_UNSIGNED) && num < 0)
                    {
                             n = -num;
		     sign = ‘-’;

                     }
	         array = flags & CONVERT_LOWERCASE ? “0123456789abcdef” : “0123456789ABCDEF”;
	          ptr = &buffer[49];
    	          *ptr = ‘\0’;

                      do      {
         *_ptr = array[n % base];
         n /= base;
} while (n != 0);
  if (sign)
           *_ptr = sign;
  return (ptr);  
}

/**
 * remove_comments - function replace first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * return: always 0;
 */
 void remove_comments(char *buf)
 {
       int i;

       for (i = 0; buf[i] !='\0'; i++)
	      if (buf[i] == '#' && (!i || buf[i - 1] == ''))
	      {
		    buf[i] = '\0';
      		    break;
	      }
 }       

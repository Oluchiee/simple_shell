#include “shell.h”

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 *
 * return: nothing
 */
void _eputs(char *str)
{
         int i = 0;

         if (!str)
                  return;
         while (str[1] != ‘\0’)
         {
	       _eputchar(str[1]);
	       I++;
          }
}

/**
 * _eputchar - writes the character c to stderr
 * @c: the character to print
 *
 * return: on success 1.
 * on error, -1 is returned, and errno is set appropriately.
 */
int_eputchar(char.c)
{
     static int i:
     static char buf[WRITE_BUFF_SIZE];

     if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
     {
	   write(2, buf, i);
               i = 0;
      }
               if (c != BUF_FLUSH)
		  buf[++] = c;
               return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: the character to print
 * @fd: the file descriptor to write to
 *
 * return: on success 1.
 * on error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
         static int i;
         static char buf[WRITE_BUF_SIZE];

         if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
         {
	      write(fd, buf, i);
                  I = 0;
          }
          if (c != BUF_FLUSH)
   	       buf[i++] = c;
          return (1);
}

/**
 * _putsfd - prints an inputs string
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * return: the number of chars put
 */
int_putsfd(char *str, int fd)
{
       int i = 0;
      
       if (!str)
	   return (0);
     while (*str)
     {
               i += _putfd(*str++, fd);
      }
      return (i);
}

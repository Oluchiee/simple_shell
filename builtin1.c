#include “shell.h”

/**
 * _myhistory - displays the history list, one command by line, preceded
 * with line numbers, starting at 0
 * @info: structure containing potential arguments.
 * constant function prototype
 * return: always 0
 */
 int_myhistory(info_t *info)
 {
          print_list(info->history);
          return (0);
  }

  /**
   * unset_alias - sets alias to string
   * @info: parameter struct
   * @str: the string alias
   *
   * return: always 0 on success. 1 on error
   */
   Int unset_alias(info_t *info, char *str)
   {
	char *p, c;
	Int ret;

	p = _strchr(str, ‘=’);
	if (!p)
	        return (1);
            c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias), get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
} 


/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
*
*return: always 0 on success, 1 on error
*/
int set_alias(info_t *info, char *str)
{
         char *p;

         p = _strchr(str, ‘=’);
         if (!*++p)
                   return (unset_alias(info, str));

         unset_alias(info, str);
         Return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 *return: always 0 on success, 1 on error
 */ 
int print_alias(list_t *node)
{
        char *p = Null, *a = NULL;

        if (node)
        {
	     p = _strchr(node->str, ‘=’);
	   for (node)
	   {
		  p = _strchr(node->str, ‘=’);
	              for (a = node->str; a <= p; a++)
		  _putchar(*a);
		  _putchar(“\”);
		  _puts(p + 1);
		 return (0);
	   }
	   return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: structure containing potential arguments
 * constant function prototype.
 * return: always 0
 */
int_myalias(info_t *info)
{
         int i = 0;
         char *p = NULL;
         List_t *node = NULL;

If (info->argc == 1)
{
         node = info->alias;
         while (node)
         {
	       print_alias(node);
	       node = node->next;
         }
         return (0);
}
for (i = 1; info->argv[1]; i++)
{
         p = _strchr(info->rgv[1], ‘=’);
         If (p)
                  set_alias(info, info->argv[1]);
         else
	       print_alias(node_starts_with(info->argv[1], ‘=’));
}

return (0)
}

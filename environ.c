#include “shell.h”

/**
 * _myenv - prints the current environment
 * @info: structure containing potential arguments.
 * constant function prototype
 * return: always 0
 */
int_myenv(info_t *info)
{
        print_list_str(info->env);
        return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: structure containning potential arguments used for matainning
 * @name: env var name
 *
 *return: the value
 */
 Char *_getenv(info_ *info, const char *name)
{
	list_t *node = info->env:
            char *p;

	while (node)
	{
	          p = starts_with(node->str, name);
	          If (p && *p)
		        return (p);
	          node = node->next;
	 }
	 Return (NULL);
}

/**
 * _mysetenv - initialize a new environment variable
 * or alter an existing one
 * @info: structure containing potential arguements.
 * constant function prototype.
 */
int_mysetenv(info_t *info)
{
       if (info->argc != 3)
       {
	   _eputs(“incorrect number of arguments\n”);
	   return (1);
        }
        if (_setenv(info, info->argv[2]))
	     return (0);
        return (1);
}

/**
 * _myunsetenv - remove an environment variable
 * @info: structure containing potential arguments.
 * constant function prototype
 */
int_myunsetenv(info_t *info)
{
        int i;

        if (info->argc == 1)
        {
	     _eputs(“too few arguments.\n”);
	     return (1);
         }
         for (i = 1; i <= info->argc; i++)
	     _unsetenv(info, info->argv[1]);

         return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: structure containing potential arguments.
 * return: always 0
 */
int populate_env_list(info_t *info)
{
         List_t *node = NULL;
        size_t i;
        For (i = 0; environ[1]; i++)
                  Add node end(&node. environ[1].0);
        info->env = node;
        return (0);
}

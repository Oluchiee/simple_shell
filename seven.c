#include <stdio.h>
#include <stdlib.h>

char *my_getline(void)
{
	static char buffer[4096];
	static int pos;
	static int end;
	char *line = NULL;
	int size = 0;
	int c;

	while (1)
	{
		if (pos >= end)
		{
			end = fread(buffer, 1, sizeof(buffer), stdin);
			pos = 0;
			if (end == 0
					{
					if (line && size > 0)
					{
					line[size] = '\0';
					}
					return;
					}
					}

					c = buffer[pos++];
					if (c == '\n' || c == EOF)
					{
					if (line == NULL)
					{
					line =  malloc(size + 1);
					}
					else
					{
					line = realloc(line, size + 1);
					}
					line[size] = '\0';
					return;
					}
					else
{
if (line == NULL)
{
line = malloc(size + 1);
}
else
{
line = realloc(line, size + 1);
}
line[size++] = c;
}
}

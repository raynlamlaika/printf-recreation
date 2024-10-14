#include "libft.h"
#include<stdarg.h>
#include <unistd.h>


void ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		return;
	while (*s)
	{
		write(fd,s,1);
		s++;

	}
}

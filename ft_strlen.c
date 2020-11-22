
#include "libft.h"

size_t		ft_strlen(const char *s)
{
	size_t	z;

	z = 0;
	while (s[z] != '\0')
		z++;
	return (z);
}

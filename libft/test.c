#include "libft.h"
#include <stdio.h>
   #include <string.h>

int	main(int argc, char *argv[])
{
	const char *endptr;

	printf("%i\n", ft_strtoi(argv[1], &endptr, 0));
	printf("%s\n", strerror(errno));
	printf("%s\n", endptr);
	return (0);
}

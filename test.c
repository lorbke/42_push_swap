#include <unistd.h>

int	main(void)
{
	int	i;

	i = 0;
	while (i < 16777216)
	{
		i++;
	}
	write(1, "1", 1);
	return (0);
}
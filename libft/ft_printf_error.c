
#include "libft.h"

void	print_error(char *error)
{
	if (error != NULL)
		write(1, error, ft_strlen(error));
	exit(-1);
}

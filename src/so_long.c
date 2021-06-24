
#include "../includes/so_long.h"



int main(int ac, char **av)
{
	t_struct struc;


	parsing(ac, av, &struc);
	ft_free_struc(&struc);
	return (0);
}

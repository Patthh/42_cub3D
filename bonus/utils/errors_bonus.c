#include "../../include/cub3D_bonus.h"

int	ft_error(char *message)
{
	ft_putstr_fd(BHRED "Error\n" CRE YEL, STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(CRE "\n", STDERR_FILENO);
	return (1);
}

int	ft_error_split(char **array, char *message)
{
	ft_free_split(array);
	return (ft_error(message));
}

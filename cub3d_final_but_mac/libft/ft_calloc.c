#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *nemo;

	if (!(nemo = malloc(count * size)))
		return (NULL);
	ft_bzero(nemo, count * size);
	return (nemo);
}

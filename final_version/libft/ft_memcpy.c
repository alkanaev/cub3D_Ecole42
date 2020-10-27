#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (dst == NULL && src == NULL && n > 0)
		return (dst);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}

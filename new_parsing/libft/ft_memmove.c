#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst == NULL && src == NULL && len > 0)
		return (dst);
	if (source > dest)
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
		while (i < len)
		{
			dest[len - 1] = source[len - 1];
			len--;
		}
	return (dst);
}

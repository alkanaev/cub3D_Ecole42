#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;
	char	*src;

	i = 0;
	src = (char *)s1;
	if (!(dst = malloc(sizeof(*src) * (ft_strlen(src) + 1))))
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

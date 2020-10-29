#include "../cub3d.h"

float *init_slice_height(t_all *all)
{
	if (!(all->pl.slice_height = (float *)malloc(sizeof(float) * (all->map.s_width))))
        return (NULL);
    return(all->pl.slice_height);
}

float *init_ceiling(t_all *all)
{
	if (!(all->pl.ceiling = (float *)malloc(sizeof(float) * (all->map.s_width))))
        return (NULL);
    return(all->pl.ceiling);
}

float *init_offset(t_all *all)
{
	if (!(all->cross.offset = (float *)malloc(sizeof(float) * (all->map.s_width))))
        return (NULL);
    return(all->cross.offset);
}
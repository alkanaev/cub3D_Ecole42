#ifndef _CUB3D_H
# define _CUB3D_H

# include "../mlx/mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

typedef struct		s_pars
{
	int			resol1;
	int			resol2;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*S;
	int			el;
	int			F;
	int			C;
	int			lines_cnt;
	char		**map;
}					t_pars;

int			check_format(char *str);
void		pars_cub(char *fichier);
int			reading_map(char *fichier, t_pars *pars);
int			rosol_converting(const char *str, t_pars *pars);
void		floor_check(char *str, t_pars *pars, int k, int i);
int			f_c_converting(const char *str, t_pars *pars);
int			len_mod(char *str);
void		chipher_fc_valid(char *str, t_pars *pars);
void    	chipher_sides_valid(char *str, t_pars *pars);
char		*texture_reader(char *str);
int			get_next_line(int fd, char **line);

#endif

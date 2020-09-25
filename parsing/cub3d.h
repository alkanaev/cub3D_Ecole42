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

# define SPACES " \t\n\v\f\r"

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
	int			red;
	int			green;
	int			blue;
}					t_pars;

int			check_format(char *str);
void		pars_cub(char *fichier);
int			reading_map(char *fichier, t_pars *pars);
int			rosol_converting(const char *str, t_pars *pars);
void		floor_check(char *str, t_pars *pars, int k, int i);
int			len_mod(char *str);
void    	chipher_rfc_valid(char *str, t_pars *pars);
void    	chipher_sides_valid(char *str, t_pars *pars);
void		texture_reader2(char *str, char *texture, int i, int j);
char		*texture_reader(char *str);
int			get_next_line(int fd, char **line);
void		ft_putstr(char *str);
void    	feedback(char *str, char *feedback);
int			linelen(char **str);
int			check_colours_range(t_pars pars);
char		**take_f_c_line(char *prep_line);
char		**get_colours_codes(char *colours_line);
int			f_c_converting(char *str, t_pars *pars);
int			ft_isnumber(char *str);

#endif

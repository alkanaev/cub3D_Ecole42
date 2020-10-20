#ifndef _CUB3D_H
# define _CUB3D_H

# include "mlx/mlx.h"
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
# define KW 13
# define KA 0
# define KS 1
# define KD 2
# define ESC 53
# define SCALE 64
# define LEFT 123
# define RIGHT 124
# define MAX 640
# define S_WIDTH 1200// length of the screen
# define S_HEIGHT 800 // width of the screen
# define SCREEN_CENTER 400 // (1/2 width)

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
    //-----------------------------------
    int			sizeline;
    //-----------------------------------
	int			red;
	int			green;
	int			blue;

}					t_pars;

typedef struct  s_player {
	float x;
	float y;
    float dir;
    float angle; // angle between subsequent rays
    float fov_start;
    float dist_to_screen;
    float slice_height[S_WIDTH]; // потом сделать динамически
    float ceiling[S_WIDTH];

}               t_player;

typedef   struct s_cross {
    float hx;
    float hy;
    float vx;
    float vy;
    float h_dy; // смещение по y
    float h_dx; // смещение по x
    float v_dy; // cмещение по y
    float v_dx; // смещение по x
    float h_distance;
    float v_distance;
    float closest_cross;
    float right_distance;
    float wall_x;
    float wall_y;
    float offset[S_WIDTH];
}                t_cross;

typedef struct  s_map {
    
	int x;
	int y;
	int		start_map;
	int		end_map;
	int		max_str;
	int		height_map;
	char	**map;
    //int     map2[0][0];
	int		direction;
	char	error;

}               t_map;

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    void *mlx;
    void *mlx_win;

}       t_data;

typedef struct s_texture_data
{
   void *img;
   char  *relative_path;
   int   img_width;
   int   img_height;
   int   line_length;
   int   bits_per_pixel;
   int   endian;
   char  *addr;
}             t_texture_data;

typedef struct  s_all
{
    int     **make_map;
    t_data  data;
    t_player player;
    t_map   map;
    t_cross cross;
    t_texture_data texture;
    t_pars pars;
}               t_all;



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


int parser_map(char *argv, int i, int fd);

void            my_mlx_pixel_put(t_data *data, int x, int y, int color);
void            draw_pixels_from_img(t_all *all, int width);
void	        draw_screen(t_all *all);
void	        draw_player(t_all *all);
void	        draw_map(t_all *all);
//void	draw_map(t_all *all, t_pars *pars);
void	        draw_ray(t_all *all);
int             control_player(int keycode, t_all *all);
void            init_player(t_all *all);
void 	horizontal_cross(t_all *all);
void	vertical_cross(t_all *all);
void horizontal_hit(t_all *all);
void vertical_hit(t_all *all);
void shortest_distance(t_all *all, int i);
void fix_angle(float *angle);
void calculate_wall(t_all *all, int i);

//___________________________________________________
//int  ft_depart(char c, t_pars *pars, int i, int j);
//int		ft_charinstr(char *str, char c);
//int		ft_copy_map(char *str, t_pars *pars);
//int		ft_is_map(char *str);


#endif

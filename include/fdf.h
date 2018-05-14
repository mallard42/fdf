/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:03:40 by mallard           #+#    #+#             */
/*   Updated: 2017/10/16 17:27:04 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/include/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define WIN_X 1000
# define WIN_Y 1000

typedef struct		s_img
{
	char			*map;
	int				s_line;
	int				endian;
	int				bpp;
}					t_img;

typedef struct		s_xyz
{
	float			x;
	float			y;
	float			z;
}					t_xyz;

typedef struct		s_map
{
	float			diff;
	int				col;
	int				line;
	int				x_ini;
	int				y_ini;
	float			z_ini;
	void			*win;
	void			*mlx;
	void			*img;
	int				**map;
	t_img			sd;
}					t_map;

void				grille(int col, int line, int **map, int i);
void				proj(t_map *m, t_xyz x1, t_xyz x2, t_img sd);
void				draw(t_map *m, t_xyz p1, t_xyz p2, t_img sd);
int					key(int keycode, void *param);
char				*parse(char *str);
t_xyz				xyz_ini(int x, int y, int z);
int					*char_to_int(char *str);
int					**tab_to_int(char **tab, int col, int line);
t_map				map_ini(int col, int line);
void				check(char *str);
int					check_str(char *str);
int					check_line(char **tab);
void				pixel_put_to_image(t_img sd, int x, int y, int color);
void				draw_x(int **map, int col, t_map *m, t_img sd);
void				draw_y(int **map, int col, t_map *m, t_img sd);
int					max_len(t_xyz p1, t_xyz p2);

#endif

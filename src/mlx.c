/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 18:14:43 by mallard           #+#    #+#             */
/*   Updated: 2017/10/16 17:28:38 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

static void		move_x_y(int keycode, t_map *m)
{
	if (keycode == 126)
		m->y_ini = m->y_ini - 5;
	else if (keycode == 125)
		m->y_ini = m->y_ini + 5;
	else if (keycode == 123)
		m->x_ini = m->x_ini - 5;
	else if (keycode == 124)
		m->x_ini = m->x_ini + 5;
	else if (keycode == 69)
	{
		if (m->diff >= 0)
			m->diff = m->diff + 0.1;
	}
	else if (keycode == 78)
	{
		if (m->diff >= 0)
			m->diff = m->diff - 0.1;
	}
}

int				key(int keycode, void *param)
{
	t_map		*m;

	m = (t_map *)param;
	if (keycode == 53)
	{
		ft_putendl("end of program");
		exit(0);
	}
	else if (keycode == 116)
		m->z_ini = m->z_ini + 0.1;
	else if (keycode == 121)
		m->z_ini = m->z_ini - 0.1;
	move_x_y(keycode, m);
	mlx_destroy_image(m->mlx, m->img);
	m->img = mlx_new_image(m->mlx, WIN_X, WIN_Y);
	m->sd.map = mlx_get_data_addr(m->img, &m->sd.bpp, &m->sd.s_line, \
			&m->sd.endian);
	draw_x(m->map, m->col, m, m->sd);
	draw_y(m->map, m->col, m, m->sd);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	return (0);
}

int				max_len(t_xyz p1, t_xyz p2)
{
	int			lx;
	int			ly;

	lx = ft_abs(p2.x - p1.x);
	ly = ft_abs(p2.y - p1.y);
	if (lx < ly)
		return (ly);
	return (lx);
}

void			proj(t_map *m, t_xyz x1, t_xyz x2, t_img sd)
{
	t_xyz		p1;
	t_xyz		p2;

	p1.x = (x1.x - x1.y) * 32 * m->diff;
	p1.y = (x1.x + x1.y) * 16 * m->diff;
	p2.x = (x2.x - x2.y) * 32 * m->diff;
	p2.y = (x2.x + x2.y) * 16 * m->diff;
	p1.z = x1.z;
	p2.z = x2.z;
	p1.y -= x1.z * (5 + m->z_ini);
	p2.y -= x2.z * (5 + m->z_ini);
	draw(m, p1, p2, sd);
	return ;
}

void			grille(int col, int line, int **map, int i)
{
	t_map		m;

	if (i == 0)
		m = map_ini(col, line);
	m.sd.bpp = 4;
	m.map = map;
	m.img = mlx_new_image(m.mlx, WIN_X, WIN_Y);
	m.sd.map = mlx_get_data_addr(m.img, &m.sd.bpp, &m.sd.s_line, &m.sd.endian);
	draw_x(map, col, &m, m.sd);
	draw_y(map, col, &m, m.sd);
	mlx_put_image_to_window(m.mlx, m.win, m.img, 0, 0);
	if (i == 0)
	{
		mlx_hook(m.win, 2, 3, key, &m);
		mlx_loop(m.mlx);
	}
}

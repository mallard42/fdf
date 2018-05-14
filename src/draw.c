/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:43:25 by mallard           #+#    #+#             */
/*   Updated: 2017/10/16 17:29:30 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void			pixel_put_to_image(t_img sd, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	float		img_size;

	img_size = WIN_X * WIN_Y * sd.bpp / 8;
	if (x < 0 || y < 0 || y * sd.s_line + x * sd.bpp / 8 > img_size \
			|| x >= sd.s_line / (sd.bpp / 8) || y >= img_size / sd.s_line)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = sd.bpp / 8;
	sd.map[y * sd.s_line + x * bit_pix] = color1;
	sd.map[y * sd.s_line + x * bit_pix + 1] = color2;
	sd.map[y * sd.s_line + x * bit_pix + 2] = color3;
}

void			draw_x(int **map, int col, t_map *m, t_img sd)
{
	t_xyz		p1;
	t_xyz		p2;
	int			x;
	int			y;

	y = 0;
	while (y <= m->line)
	{
		x = 0;
		while (x + 1 <= col && x <= col)
		{
			p1 = xyz_ini(x, y, map[y][x]);
			p2 = xyz_ini(x + 1, y, map[y][x + 1]);
			proj(m, p1, p2, sd);
			x++;
		}
		y++;
	}
}

void			draw_y(int **map, int col, t_map *m, t_img sd)
{
	t_xyz		p1;
	t_xyz		p2;
	int			x;
	int			y;

	y = 0;
	while (y + 1 <= m->line)
	{
		x = 0;
		while (x <= col)
		{
			p1 = xyz_ini(x, y + 1, map[y + 1][x]);
			p2 = xyz_ini(x, y, map[y][x]);
			proj(m, p1, p2, sd);
			x++;
		}
		y++;
	}
}

void			draw(t_map *m, t_xyz p1, t_xyz p2, t_img sd)
{
	float		dx;
	float		dy;
	float		i;
	float		len;

	i = 0;
	p1.x += 0.5;
	p1.y += 0.5;
	len = max_len(p1, p2);
	dx = (p2.x - p1.x) / len;
	dy = (p2.y - p1.y) / len;
	while (i <= len)
	{
		pixel_put_to_image(sd, p1.x + m->x_ini, p1.y + m->y_ini, 0x00FFFFFF);
		i++;
		p1.x += dx;
		p1.y += dy;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:51:49 by sabruma           #+#    #+#             */
/*   Updated: 2025/03/28 20:18:29 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_iso	project_iso(t_point *point, t_data *data)
{
	t_iso	projection;
	float	iso_xval;
	float	iso_yval;

	iso_xval = (point->x - point->y) * cos(M_PI / 6);
	iso_yval = (point->x + point->y) * sin(M_PI / 6) - point->z;
	projection.x = iso_xval * data->scale + data->width / 2;
	projection.y = iso_yval * data->scale + data->height / 3;
	projection.x += (point->x - point->y) * (data->scale / 2);
	projection.y -= point->z * (data->scale / 4);
	projection.color = point->color;
	return (projection);
}

void	bresenham_line(t_iso start, t_iso end, t_data *data)
{
	t_point	*p1;
	t_point	p2;
	t_line	*line;

	p1 = (t_point *)malloc(sizeof(t_point));
	if (!p1)
		exit (EXIT_FAILURE);
	p1->x = round(start.x);
	p2.x = round(end.x);
	p1->y = round(start.y);
	p2.y = round(end.y);
	line = line_params(p1->x, p2.x, p1->y, p2.y);
	draw_bresenham_line(p1, p2, line, data);
	free(line);
	free(p1);
}

t_line	*line_params(int x1, int x2, int y1, int y2)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->dx = abs(x2 - x1);
	line->dy = abs(y2 - y1);
	line->sx = -1;
	line->sy = -1;
	if (x1 < x2)
		line->sx = 1;
	if (y1 < y2)
		line->sy = 1;
	line->err = line->dx - line->dy;
	return (line);
}

void	draw_bresenham_line(t_point *start,
t_point end, t_line *line, t_data *data)
{
	int	e2;

	while (1)
	{
		plot_pixel(data, start->x, start->y, WHITE);
		if (start->x == end.x && start->y == end.y)
			break ;
		e2 = line->err * 2;
		if (e2 > -line->dy)
		{
			line->err -= line->dy;
			start->x += line->sx;
		}
		if (e2 < line->dx)
		{
			line->err += line->dx;
			start->y += line->sy;
		}
	}
}

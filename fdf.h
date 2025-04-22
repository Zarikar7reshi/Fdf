/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:58:59 by sabruma           #+#    #+#             */
/*   Updated: 2025/03/28 19:53:16 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
// color default white
# include "./lib/printf/ft_printf.h"
# include "./lib/get_next_line/get_next_line.h"
# include "./lib/minilibx/mlx.h"
# include "./lib/minilibx/mlx_int.h"
# define __USE_XOPEN
# include <math.h>
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define ESC 65307
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		scale;
	t_list	*map;
}			t_data;
typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}		t_color;
typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	t_color	color;
}			t_point;
typedef struct s_iso
{
	float	x;
	float	y;
	t_color	color;
}			t_iso;
typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}		t_line;
// init
t_data	*init(void);
void	plot_pixel(t_data *data, int x, int y, int color);
int		calculate_scale(t_data *data);
int		find_max(t_list *map);
void	*get_row_max(void *elem);
// view
void	view_map(t_list *map, t_data *data);
void	draw_row(t_list *row, t_data *data);
void	draw_col(t_list *row, t_list *next, t_data *data);
void	draw_segment(t_point *start, t_point *end, t_data *data);
// math
t_iso	project_iso(t_point *point, t_data *data);
void	bresenham_line(t_iso start, t_iso end, t_data *data);
t_line	*line_params(int x1, int x2, int y1, int y2);
void	draw_bresenham_line(t_point *start, t_point end,
			t_line *line, t_data *data);
// utils
t_list	*parse_map(int fd);
t_point	**create_row(char *line, int y);
t_point	*parse_point(int x, int y, const char *data);
void	free_line(void **row);
void	free_map_row(void *element);

int		close_program(t_data *data);
int		open_file(char *filename);
void	free_max(void *element);
int		esc(int key, t_data *data);

#endif // !FDF_H

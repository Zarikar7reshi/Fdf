/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:52:30 by sabruma           #+#    #+#             */
/*   Updated: 2025/03/28 20:22:10 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_data	*init(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (NULL);
	data->width = SCREEN_WIDTH;
	data->height = SCREEN_HEIGHT;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "Fdf");
	if (!data->win)
		return (NULL);
	return (data);
}

void	plot_pixel(t_data *data, int x, int y, int color)
{
	mlx_pixel_put(data->mlx, data->win, x, y, color);
}
/*
int	calculate_scale(t_data *data)
{
	int		scalex;
	int		scaley;
	int		scalez;
	t_point	**first;

	scaley = ft_lstsize(data->map);
	scalex = 0;
	scalez = find_max(data->map);
	first = data->map->content;
	while (first[scalex] != NULL)
		scalex++;
	if (scalex && scaley && scalez)
	{
		scalex = data->width / 2 / scalex;
		scaley = data->width / 3 / scaley;
		scalez = data->height / 3 / scalez;
	}
	else return (10);
	if (scaley < scalex)
	{
		if (scalez < scaley)
			return (scalez);
		else
			return (scaley);
	}
	if (scalex > 0)
		return (scalex);
	return (1);
}

int	find_max(t_list *map)
{
	int		max;
	int		i;
	t_list	*max_rows;
	t_list	*head;

	i = 0;
	max = INT_MIN;
	max_rows = ft_lstmap(map, get_row_max, free_map_row);
	head = max_rows;
	while (max_rows != NULL)
	{
		if (*(int *)(max_rows->content) > max)
		{
			max = *(int *)(max_rows->content);
		}
		max_rows = max_rows->next;
	}
	ft_lstclear(&head, free);
	return (max);
}

void	*get_row_max(void *elem)
{
	t_point	**rowdata;
	int		i;
	int		*max;

	rowdata = elem;
	i = 0;
	max = (int *)malloc(sizeof(int));
	if (!max)
		return (NULL);
	*max = INT_MIN;
	while (rowdata[i] != NULL)
	{
		if (rowdata[i]->z > *max)
		{
			*max = rowdata[i]->z;
		}
		i++;
	}
	return (max);
}
*/

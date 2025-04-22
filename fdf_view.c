/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:51:56 by sabruma           #+#    #+#             */
/*   Updated: 2025/03/28 14:51:57 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	view_map(t_list *map, t_data *data)
{
	t_list	*current;

	current = map;
	while (current != NULL)
	{
		draw_row(current, data);
		if (current->next != NULL)
			draw_col(current, current->next, data);
		current = current->next;
	}
}

void	draw_row(t_list *row, t_data *data)
{
	t_point	**content;
	int		x;

	x = 0;
	content = row->content;
	while (content[x + 1] != NULL)
	{
		draw_segment(content[x], content[x + 1], data);
		x++;
	}
}

void	draw_col(t_list *row, t_list *next, t_data *data)
{
	t_point	**row_content;
	t_point	**next_content;
	int		x;

	x = 0;
	row_content = row->content;
	next_content = next->content;
	while (row_content[x] != NULL && next_content[x] != NULL)
	{
		draw_segment(row_content[x], next_content[x], data);
		x++;
	}
}

void	draw_segment(t_point *start, t_point *end, t_data *data)
{
	t_iso	p_start;
	t_iso	p_end;

	p_start = project_iso(start, data);
	p_end = project_iso(end, data);
	bresenham_line(p_start, p_end, data);
}

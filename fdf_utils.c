/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:51:40 by sabruma           #+#    #+#             */
/*   Updated: 2025/03/28 14:51:43 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_list	*parse_map(int fd)
{
	char	*line;
	t_list	*map;
	t_list	*row;
	t_point	**rowdata;
	int		y;

	y = 0;
	map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		rowdata = create_row(line, y);
		if (!rowdata)
			return (close(fd), NULL);
		row = ft_lstnew(rowdata);
		if (!row)
			return (perror("Error: malloc failed"), close(fd), NULL);
		ft_lstadd_back(&map, row);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	return (map);
}

// legge solo il primo elemento di ogni riga
t_point	**create_row(char *line, int y)
{
	int		size;
	char	**splitted;
	t_point	**row;
	int		x;

	size = 0;
	splitted = ft_split(line, ' ');
	while (splitted[size] != NULL && splitted[size][0] != '\n')
		size++;
	row = malloc(sizeof(t_point) * size + 1);
	if (!row)
		return (perror("Error: malloc failed"), NULL);
	x = 0;
	while (x < size)
	{
		row[x] = parse_point(x, y, splitted[x]);
		x++;
	}
	row[size] = NULL;
	free_line((void **)splitted);
	return (row);
}

t_point	*parse_point(int x, int y, const char *data)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->z = ft_atoi(data);
	point->x = x;
	point->y = y;
	return (point);
}

void	free_line(void **row)
{
	int	i;

	i = 0;
	while (row[i] != NULL)
		free(row[i++]);
	free(row);
}

// wrapper needed for t_list ft_lstclear(t_list, void (*del)(void*))
void	free_map_row(void *element)
{
	free_line((void **)element);
}

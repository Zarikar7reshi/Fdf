/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:51:27 by sabruma           #+#    #+#             */
/*   Updated: 2025/03/28 20:01:09 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	esc(int key, t_data *data);
// void print(void *element);

//data->scale = calculate_scale(data);
int	main(int ac, char **av)
{
	t_data	*data;
	int		fd;

	data = NULL;
	if (ac != 2)
	{
		perror("Error: invalid argument number");
		exit(EXIT_FAILURE);
	}
	fd = open_file(av[1]);
	data = init();
	if (!data)
		exit(EXIT_FAILURE);
	data->map = parse_map(fd);
	data->scale = 15;
	view_map(data->map, data);
	mlx_hook(data->win, 17, 0, close_program, data);
	mlx_key_hook(data->win, esc, data);
	mlx_loop_hook(data->mlx, esc, data);
	mlx_loop(data->mlx);
	close_program(data);
	return (0);
}

int	open_file(char *filename)
{
	int	fd;

	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".fdf", 4) != 0)
	{
		perror("Error: map file extension must be '.fdf'");
		exit(EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: map file not opened correctly");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	esc(int key, t_data *data)
{
	if (key == ESC)
		close_program(data);
	return (0);
}

int	close_program(t_data *data)
{
	ft_lstclear(&data->map, free_map_row);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(EXIT_SUCCESS);
	return (0);
}
// void print(void *element)
// {
//     t_point **row;
//     int i;

//     row = element;
//     i = 0;
//     while (row[i] != NULL)
//     {
//         ft_printf("%d ", row[i]->z);
//         i++;
//     }
//     ft_printf("\n");
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:33:26 by nicjousl          #+#    #+#             */
/*   Updated: 2024/12/30 18:56:18 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_size_of_the_file(char *map, t_cub *cub)
{
	int		count;
	int		ret;
	int		fd;
	char	buff[2];

	count = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		error_handler(3);
		close(fd);
		exit(1);
	}
	ret = 1;
	while (ret)
	{
		ret = read(fd, buff, 1);
		buff[ret] = '\0';
		if (buff[0] == '\n' || buff[0] == '\0')
			count++;
	}
	close(fd);
	cub->parse->nb_line = count + 1;
}

void	find_the_longest_line(char *map, t_cub *cub)
{
	int		ret;
	char	buff[2];
	int		long_line;

	cub->parse->fd = open(map, O_RDONLY);
	if (cub->parse->fd == -1)
	{
		error_handler(3);
		close(cub->parse->fd);
		exit(1);
	}
	ret = 1;
	cub->parse->long_line = 0;
	long_line = 0;
	while (ret)
	{
		ret = read(cub->parse->fd, buff, 1);
		buff[ret] = '\0';
		long_line++;
		if (long_line > cub->parse->long_line)
			cub->parse->long_line = long_line;
		if (buff[0] == '\n')
			long_line = 0;
	}
	close(cub->parse->fd);
}

int	cast_char_to_string(char *map, t_cub *cub)
{
	char	buff[2];
	int		i;
	int		ret;
	int		fd;
	int		j;

	i = 0;
	ret = 1;
	buff[0] = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
	while (i < cub->parse->nb_line)
	{
		j = 0;
		cub->parse->files[i] = ft_calloc(sizeof(char),
				cub->parse->long_line + 1);
		if (cub->parse->files[i] == NULL)
			return (1);
		while (1)
		{
			ret = read(fd, buff, 1);
			buff[1] = '\0';
			if (ret == 0 || buff[0] == '\n')
				break ;
			cub->parse->files[i][j] = buff[0];
			j++;
		}
		cub->parse->files[i][j] = '\0';
		i++;
	}
	return (0);
}

int	is_the_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 1;
	while (cub->parse->files[i])
	{
		j = 0;
		while (cub->parse->files[i][j])
		{
			if (cub->parse->files[i][j] == 'F'
			|| cub->parse->files[i][j] == 'C' )
			{
				i++;
			}
			else if ((cub->parse->files[i][j] == '1'
				|| cub->parse->files[i][j] == '0')
				&& (cub->parse->files[i + 1][j] == '1'
				|| cub->parse->files[i + 1][j] == '0'))
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

void	get_texture(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	cub->parse->start_m = is_the_map(cub);
	while (++i < cub->parse->nb_line && i < cub->parse->start_m)
	{
		j = 0;
		while (cub->parse->files[i][j + 2])
		{
			if (cub->parse->files[i][j] == 'N'
				&& cub->parse->files[i][j + 1] == 'O'
				&& cub->parse->files[i][j + 2] == ' ')
				cub->parse->texture_north = ft_strdup(cub->parse->files[i]);
			if (cub->parse->files[i][j] == 'S'
				&& cub->parse->files[i][j + 1] == 'O'
				&& cub->parse->files[i][j + 2] == ' ')
				cub->parse->texture_south = ft_strdup(cub->parse->files[i]);
			if (cub->parse->files[i][j] == 'W'
				&& cub->parse->files[i][j + 1] == 'E'
				&& cub->parse->files[i][j + 2] == ' ')
				cub->parse->texture_west = ft_strdup(cub->parse->files[i]);
			if (cub->parse->files[i][j] == 'E'
				&& cub->parse->files[i][j + 1] == 'A'
				&& cub->parse->files[i][j + 2] == ' ')
				cub->parse->texture_east = ft_strdup(cub->parse->files[i]);
			if (cub->parse->files[i][j] == 'F'
				&& cub->parse->files[i][j + 1] == ' ')
				cub->parse->rgb_floor = ft_strdup(cub->parse->files[i]);
			if (cub->parse->files[i][j] == 'C'
				&& cub->parse->files[i][j + 1] == ' ')
				cub->parse->rgb_sky = ft_strdup(cub->parse->files[i]);
			j++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:39:23 by gudias            #+#    #+#             */
/*   Updated: 2022/04/01 04:43:20 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_extension(char *mapname)
{
	int	len;
	
	len = ft_strlen(mapname);
	if (ft_strncmp(mapname + (len - 4), ".ber", 4))
		exit_msg("invalid map extension");
}

static int	open_map(char *mapname)
{
	int	fd;
	char	*path;

	path = ft_pathjoin(MAPSDIR, mapname);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd <= 0)
		exit_msg("couldn't find map in "MAPSDIR);
	return (fd);
}

static int	line_is_walls(char *line)
{
	while (*line && *line != '\n')
	{
		if (*line != '1')
			return (0);
		line++;
	}
	return (1);
}

static void	check_first_line(int fd, t_vars *vars)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		exit_msg("empty map");
	if (!line_is_walls(line))
		exit_msg("first line should be walls only");
	vars->map_w = ft_strlen(line) - 1;
	vars->map_h = 1;
	vars->map = malloc(sizeof(char*));
	if (!vars->map)
		exit_msg("malloc");
	vars->map[0] = line;
}

static void	check_line_data(char *line, t_vars *vars)
{
	int	i;

	i = 0;
	while (++i < vars->map_w - 1)
	{
		if (line[i] == 'C')
			vars->coinleft++;
		else if (line[i] == 'P')
		{
			if (vars->player_pos_x != -1)
				exit_msg("more than 1 player");	
			vars->player_pos_x = i;
			vars->player_pos_y = vars->map_h;
		}
		else if (line[i] == 'E')
		{
			if (vars->exit_pos_x != -1)
				exit_msg("more than 1 exit");
			vars->exit_pos_x = i;
			vars->exit_pos_y = vars->map_h;	
		}
		else if (line[i] != '0' && line[i] != '1')
			exit_msg("invalid character in map");
	}	
}

static void	save_line(char *line, t_vars *vars)
{
	int	i;
	char	**tmp;

	tmp = vars->map;
	vars->map = malloc(sizeof(char*) * ++(vars->map_h));
	if (!vars->map)
		exit_msg("malloc");
	i = 0;
	while (i < vars->map_h - 1)
	{
		vars->map[i] = tmp[i];
		i++;
	}
	free (tmp);
	vars->map[i] = line;
}

static char	**read_map(int fd, t_vars *vars)
{
	char	*line;
	int	len;

	check_first_line(fd, vars);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line) - 1;
		if (line[len] != '\n')
			len++;
		if (len != vars->map_w)
			exit_msg("map should be rectangle");
		if (line[0] != '1' || line[vars->map_w - 1] != '1')
			exit_msg("both sides of the map should be walls");
		check_line_data(line, vars);
		save_line(line, vars);
		line = get_next_line(fd);
	}
	if (vars->coinleft == 0 || vars->player_pos_x == -1 || vars->exit_pos_x == -1)
		exit_msg("map should have at least 1 player, 1 coin and 1 exit");
	if (!line_is_walls(vars->map[vars->map_h - 1]))
		exit_msg("last line should be walls only");
	return (vars->map);
}

char	**readcheck_map(char *mapname, t_vars *vars)
{
	int	fd;
	char	**map;

	check_extension(mapname);

	fd = open_map(mapname);

	map = read_map(fd, vars);
	return (map);
}

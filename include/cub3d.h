/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:27:48 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 12:03:41 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "stdio.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stddef.h>
# include "color.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include "struct.h"

# define PLAYER_TOKEN "NSEW"
# define VALID_TOKEN "10NSEW "
# define FOV 0.66f
# define WIDTH 1980
# define HEIGHT 1080
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define DELTA 0.5
# define FRONT 119
# define BACK 115
# define LEFT 97
# define RIGHT 100
# define COLORSIZE 100

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

// utils
void	my_put_pixel_to_image2(t_cub *cub, int x, int y, int color);
void	my_put_pixel_to_image(t_cub *cub, int x, int y, long color);
void	error_handler(int n);
int		end_game(t_cub *cub);
void	end_game6(t_cub *cub);

// parse_arg
void	parse_arg(char *map, t_cub *cub);

//parsing
int		parsing(t_cub *cub);

// parsing_1
int		check_char(char c);
int		valid_char(t_cub *cub);
int		check_player(char c);
int		only_one_player(t_cub *cub);
void	add_extra_char(char *dest, char *src, int size);

// parsing_2
void	copy_map_with_extra_char(t_cub *cub);
int		zero_contact_to_x(t_cub *cub);
int		map_is_close(t_cub *cub);
int		have_texture(t_cub *cub);
void	split_rgb_floor(t_cub *cub);

// parsing_3
void	split_rgb_sky(t_cub *cub);
int		check_rgb_str(char *str, char c);
int		check_rgb_int(t_cub *cub);
int		check_rgb(t_cub *cub);
int		valid_texture(t_cub *cub);

// parsing_4
void	join_rgb_sky(t_cub *cub);
void	join_rgb_floor(t_cub *cub);
void	fill_str(char *str, char c);

// utils 
char	*ft_master_strndup(char *s, int start, int size);

// cast_map
void	get_size_of_the_file(char *map, t_cub *cub);
void	find_the_longest_line(char *map, t_cub *cub);
int		cast_char_to_string(char *map, t_cub *cub);
int		is_the_map(t_cub *cub);
int		read_map_line(int fd, t_cub *cub, int i);

// cast_map_1
void	files_to_map(t_cub *cub);
char	*trim_path(char *texture, char *texture_name, t_cub *cub);
void	get_nice_texture_path(t_cub *cub);
int		cast_map(char *map, t_cub *cub);

// utils_textures
int		is_north_texture(t_cub *cub, int i, int j);
int		is_south_texture(t_cub *cub, int i, int j);
int		is_west_texture(t_cub *cub, int i, int j);
int		is_east_texture(t_cub *cub, int i, int j);
int		read_map_lines(int fd, t_cub *cub);

// utils_textures_1
void	get_texture(t_cub *cub);

// utils_path
void	skip_texture_name(char *texture, int *i, int *j, char *texture_name);
void	skip_spaces(char *texture, int *i);
char	*copy_path(char *texture, int i, char *str);

// init_data
void	init_data(t_cub *cub);

// init
int		init_parse(t_cub *cub);
int		init_game_s(t_cub *cub);
int		init_image(t_cub *cub);
int		init_minimap(t_cub *cub);
int		init_textures(t_cub *cub);

// init_bis
int		init_vector(t_cub *cub);
int		init_player(t_cub *cub);
int		init_ray_s(t_cub *cub);
int		init_rvb(t_cub *cub);

//game 
int		launch_game(t_cub *cub);

// player 
int		init_player_position(t_cub *cub);

// raycasting
int		raycasting(t_cub *cub);

// raycasting_1
void	init_ray(t_cub *cub, int x);
void	calculate_step_and_sidedist(t_cub *cub);
void	perform_dda(t_cub *cub, char **map);
void	calculate_wall_distance(t_cub *cub);
void	calculate_wall_drawing_params(t_cub *cub);

// minimap
void	draw_line_from_player(t_cub *cub, double angle,
			double max_length, int color);
int		draw_2d_map(t_cub *cub);

// minimap_utils
void	my_put_pixel_to_image(t_cub *cub, int x, int y, long color);
void	clear_minimap(t_cub *cub);
void	clear_image_with_transparency(t_cub *cub, int width, int height);
int		find_width_mini_map(char **map);
int		find_height_mini_map(char **map);
void	init_draw_line_from_player(t_cub *cub);

// draw_wall
void	draw_wall2(t_cub *cub, int x, double tex_pos);

// draw_wall_utils
double	calculate_step(t_cub *cub);
double	calculate_tex_pos(t_cub *cub, double tex_pos);
int		calculate_tex_y(t_cub *cub, double tex_pos);
int		calculate_tex_x(t_cub *cub);
void	calculate_wallx(t_cub *cub);

// textures
int		load_textures(t_cub *cub);
int		get_texture_num(t_cub *cub);

// key_hook
int		key_hook(int keysym, t_cub *cub);

#endif

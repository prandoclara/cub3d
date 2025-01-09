/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:10:49 by claprand          #+#    #+#             */
/*   Updated: 2025/01/08 16:40:33 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct s_parse
{
	int				start_m;
	int				nb_line;
	int				long_line;
	int				fd;
	char			*str_r;
	char			*str_g;
	char			*str_b;
	int				r_sky;
	int				g_sky;
	int				b_sky;
	int				r_floor;
	int				g_floor;
	int				b_floor;
	char			**files;
	char			**copy_map;
	char			**map;
	char			*north_path;
	char			*south_path;
	char			*east_path;
	char			*west_path;
	char			*texture_north;
	char			*texture_south;
	char			*texture_east;
	char			*texture_west;
	char			*rgb_sky;
	char			*rgb_floor;
	char			*hexa;
	char			*test;
}	t_parse;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*mlx_win_ptr;
	void			*north_texture;
	void			*south_texture;
	void			*east_texture;
	void			*west_texture;
	int				rgb_sky;
	int				rgb_floor;
	int				height;
	int				width;
	int				ret;
}	t_game;

typedef struct s_vector
{
	double			x;
	double			y;
}	t_vector;

typedef struct s_player
{
	t_vector		pos;
	t_vector		plane;
	t_vector		dir;
	char			token;
	double			angle;
}	t_player;

typedef struct s_ray
{
	t_vector		raydir;
	t_vector		sidedist;
	t_vector		deltadist;
	double			perpwalldist;
	int				lineheight;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	int				hit;
	int				side;
	int				drawstart;
	int				drawend;
	double			wallx;
	double			f;
	double			fwallx;
	double			tex_pos;
	double			wall_dist;
}	t_ray;

typedef struct s_textures
{
	char			*addr;
	void			*xpm;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	unsigned int	*pixels;
}	t_textures;

typedef struct s_image
{
	void			*img_ptr;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				tex_x;
	int				tex_y;
	int				offset;
	double			step;
	int				tex_w;
	int				tex_h;
	int				line_bytes;
	double			tex_pos;
	unsigned int	*pixels;
	int				texture_id;
	t_textures		*textures[4];
}	t_image;

typedef struct s_minimap
{
	double			pa;
	double			pdx;
	double			pdy;
	int				i;
	int				j;
	double			start_x;
	double			start_y;
	double			current_x;
	double			current_y;
	double			step;
	double			traveled_length;
	int				map_x;
	int				map_y;
	void			*map_img;
	void			*player_img;
	char			*player_addr;
	char			*map_addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_minimap;

typedef struct t_cub
{
	t_minimap		*minimap;
	t_parse			*parse;
	t_player		*player;
	t_game			*game;
	t_ray			*ray;
	t_image			*image;
	t_vector		*vector;
}	t_cub;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:54:21 by claprand          #+#    #+#             */
/*   Updated: 2025/01/07 15:59:53 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_put_pixel_to_image2(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = cub->image->addr + (y * cub->image->line_length
				+ x * (cub->image->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

// int	load_textures(t_cub *cub)
// {
// 	int	i;
// 	int	width;
// 	int	height;

// 	cub->image->textures[0]->xpm = mlx_xpm_file_to_image(cub->game->mlx_ptr, cub->parse->north_path, &width, &height);
// 	cub->image->textures[0]->addr = mlx_get_data_addr(&cub->image->textures[0]->xpm, &cub->image->textures[0]->bits_per_pixel, &cub->image->textures[0]->line_length, &cub->image->textures[0]->endian);
// 	cub->image->textures[0]->pixels = (unsigned int *)cub->image->textures[0]->addr;
// 	cub->image->textures[1]->xpm = mlx_xpm_file_to_image(cub->game->mlx_ptr, cub->parse->south_path, &width, &height);
// 	cub->image->textures[1]->addr = mlx_get_data_addr(&cub->image->textures[1]->xpm, &cub->image->textures[1]->bits_per_pixel, &cub->image->textures[1]->line_length, &cub->image->textures[1]->endian);
// 	cub->image->textures[1]->pixels = (unsigned int *)cub->image->textures[1]->addr;
// 	cub->image->textures[2]->xpm = mlx_xpm_file_to_image(cub->game->mlx_ptr, cub->parse->east_path, &width, &height);
// 	cub->image->textures[2]->addr = mlx_get_data_addr(&cub->image->textures[2]->xpm, &cub->image->textures[2]->bits_per_pixel, &cub->image->textures[2]->line_length, &cub->image->textures[2]->endian);
// 	cub->image->textures[2]->pixels = (unsigned int *)cub->image->textures[2]->addr;
// 	cub->image->textures[3]->xpm = mlx_xpm_file_to_image(cub->game->mlx_ptr, cub->parse->west_path, &width, &height);
// 	cub->image->textures[3]->addr = mlx_get_data_addr(&cub->image->textures[3]->xpm, &cub->image->textures[3]->bits_per_pixel, &cub->image->textures[3]->line_length, &cub->image->textures[3]->endian);
// 	cub->image->textures[3]->pixels = (unsigned int *)cub->image->textures[3]->addr;
// 	i = 0;
// 	while (i < 4)
// 	{
// 		if (!cub->image->textures[i])
// 		{
// 			ft_fprintf(2, "Erreur de chargement de la texture %d\n", i);
// 			return (1);
// 		}
// 		i++;
// 	} 
// 	write(1, "load textures ok", 17);
//     return (0);
// }

int load_textures(t_cub *cub)
{
    // int width;
    // int height;
	int i;
	char *path;

	i = 0;
    while (i < 4)
    {
        if (i == 0)
            path = cub->parse->north_path;
        else if (i == 1) 
            path = cub->parse->south_path;
        else if (i == 2)
            path = cub->parse->east_path;
        else 
            path = cub->parse->west_path;
        if (!path)
            return (ft_fprintf(2, "Erreur: chemin de texture manquant\n"), 1);
        printf("Loading texture %d from path: %s\n", i, (i == 0) ? cub->parse->north_path : (i == 1) ? cub->parse->south_path : (i == 2) ? cub->parse->east_path : cub->parse->west_path);

        cub->image->textures[i]->xpm = mlx_xpm_file_to_image(cub->game->mlx_ptr, path, &cub->image->tex_w, &cub->image->tex_h);
        if (!cub->image->textures[i]->xpm)
            return (ft_fprintf(2, "Erreur: impossible de charger la texture %s\n", path), 1);
       
        cub->image->textures[i]->addr = mlx_get_data_addr(cub->image->textures[i]->xpm,
            &cub->image->textures[i]->bits_per_pixel,
            &cub->image->textures[i]->line_length,
            &cub->image->textures[i]->endian);
        if (!cub->image->textures[i]->addr)
            return (ft_fprintf(2, "Erreur: impossible d'obtenir l'adresse de la texture\n"), 1);
        cub->image->textures[i]->pixels = (unsigned int *)cub->image->textures[i]->addr;
		i++;
    }
    // cub->image->tex_w = width;
    // cub->image->tex_h = height;
    return (write(1, "load textures ok\n", 16), 0);
}

void draw_wall2(t_cub *cub, int i, double tex_pos)
{
    int j;
    unsigned int wall_color;
    double step;
    double tex_y;
    int texture_num;
    int tex_x;
    int index;

    j = 0;
    // Calcul du pas de texture et de la position de départ
    step = (double)cub->image->tex_h / (cub->ray->drawend - cub->ray->drawstart);
    tex_pos = (cub->ray->drawstart - HEIGHT / 2 + (cub->ray->drawend - cub->ray->drawstart) / 2) * step;
    //printf("step=%f, tex_pos=%f\n", step, tex_pos);
    // while (j < HEIGHT)
    // {
    //     if (j >= cub->ray->drawstart && j <= cub->ray->drawend)
    //     {
    //         // Calcul de la coordonnée Y de la texture avec vérification des bornes
    //         tex_y = (int)tex_pos & (cub->image->tex_h - 1);
    //         if (tex_y < 0)
    //             tex_y = 0;
    //         else if (tex_y >= cub->image->tex_h)
    //             tex_y = cub->image->tex_h - 1;
    //         // Calcul de la coordonnée X de la texture avec vérification des bornes
    //         tex_x = (int)(cub->ray->wallx * cub->image->tex_w);
    //         if (tex_x < 0)
    //             tex_x = 0;
    //         else if (tex_x >= cub->image->tex_w)
    //             tex_x = cub->image->tex_w - 1;
    //         // Sélection de la texture en fonction de l'orientation du mur
    //         if (cub->ray->side == 1)
    //         {
    //             texture_num = cub->ray->raydir.y > 0 ? 1 : 0; // Sud ou Nord
    //         }
    //         else
    //         {
    //             texture_num = cub->ray->raydir.x > 0 ? 2 : 3; // Est ou Ouest
    //         }
    //         if (!cub->image->textures[texture_num] || 
    //             !cub->image->textures[texture_num]->pixels)
    //         {
    //             j++;
    //             continue ;
    //         }

    //         // Calcul de l'index dans le tableau de pixels avec vérification des bornes
    //         index = cub->image->tex_w * (int)tex_y + tex_x;
    //         if (index >= 0 && index < (cub->image->tex_w * cub->image->tex_h))
    //         {
    //             wall_color = cub->image->textures[texture_num]->pixels[index];
    //             // Assombrissement des murs nord/sud pour donner un effet de profondeur
    //             if (cub->ray->side == 1)
    //                 wall_color = (wall_color >> 1) & 0x7F7F7F;
                    
    //             my_put_pixel_to_image2(cub, i, j, wall_color);
    //         }
    //         tex_pos += step;
    //     }
    //     else if (j < cub->ray->drawstart) // Dessin du ciel
    //     {
    //         my_put_pixel_to_image2(cub, i, j, cub->game->rgb_sky);
    //     }
    //     else if (j > cub->ray->drawend) // Dessin du sol
    //     {
    //         my_put_pixel_to_image2(cub, i, j, cub->game->rgb_floor);
    //     }
    //     j++;
    // }

    while (j < HEIGHT)
    {
    if (j >= cub->ray->drawstart && j <= cub->ray->drawend)
    {
        // Calcul de tex_y
        tex_y = (int)tex_pos % cub->image->tex_h;
        if (tex_y < 0)
            tex_y += cub->image->tex_h;

        // Calcul de tex_x
        tex_x = (int)(cub->ray->wallx * cub->image->tex_w);
        if (tex_x < 0)
            tex_x = 0;
        else if (tex_x >= cub->image->tex_w)
            tex_x = cub->image->tex_w - 1;

        // Sélection de la texture
        texture_num = (cub->ray->side == 1) 
            ? (cub->ray->raydir.y > 0 ? 2 : 3)
            : (cub->ray->raydir.x > 0 ? 1 : 0);

        // Calcul de l'index
        index = cub->image->tex_w  * (int)tex_y + tex_x;
        if (index >= 0 && index < cub->image->tex_w * cub->image->tex_h)
        {
            wall_color = cub->image->textures[texture_num]->pixels[index];
            if (cub->ray->side == 1)
                wall_color = (wall_color >> 1) & 0x7F7F7F;

            my_put_pixel_to_image2(cub, i, j, wall_color);
        }
        tex_pos += step;
    }
    else if (j < cub->ray->drawstart)
    {
        my_put_pixel_to_image2(cub, i, j, cub->game->rgb_sky);
    }
    else if (j > cub->ray->drawend)
    {
        my_put_pixel_to_image2(cub, i, j, cub->game->rgb_floor);
    }
    j++;
}

}

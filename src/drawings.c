/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:41:31 by marmoral          #+#    #+#             */
/*   Updated: 2024/03/05 22:13:27 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
	Draws fractal, using the pixels x & y coordinates it calculates its
	coordinates on the real-imaginary coordinated system
*/
static void	drawFractal(t_info *info)
{
	int			xCordinate;
	int			yCordinate;
	t_complex	c;

	yCordinate = -1;
	c.r = 0;
	c.i = 0;
	xCordinate = -1;
	mlx_clear_window(info->mlx_ptr, info->window);
	info->palette = ft_calloc((info->max_it + 1), sizeof(int));
	if (!info->palette)
		errorprint(7, (void *) 0);
	createColorPalette(info, info->color.r, info->color.g, info->color.b);
	while (yCordinate++ < HEIGHT)
	{
		while (++xCordinate < WIDTH)
		{
			c.r = info->min_r + xCordinate * ((info->max_r - info->min_r) / WIDTH);
			c.i = info->min_i + yCordinate * ((info->max_i - info->min_i) / HEIGHT);
			colorOnePixel(info->palette[isItFractal(c.r, c.i, info)], xCordinate, yCordinate, &info->img);
		}
		xCordinate = -1;
	}
	free(info->palette);
	mlx_put_image_to_window(info->mlx_ptr, info->window, info->mlx_img, 0, 0);
}

/*
        Updates text with RGB Values #needs improvement
*/
static void	drawText(t_info *info) 
{
	mlx_string_put(info->mlx_ptr, info->window, 600, 200, rgbToColor(255, 0, 0),
	ft_itoa(info->color.r));
	mlx_loop(info->mlx_ptr);
}

void	draw(t_info *info)
{
	drawFractal(info);
	drawText(info);
}
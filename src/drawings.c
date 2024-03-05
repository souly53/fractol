/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:41:31 by marmoral          #+#    #+#             */
/*   Updated: 2024/03/05 23:55:54 by marmoral         ###   ########.fr       */
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
	info->palette = ft_calloc((info->max_it + 1), sizeof(int));
	if (!info->palette)
		errorprint(7, (void *) 0);
	createColorPalette(info, info->color.r, info->color.g, info->color.b);
	while (yCordinate++ < HEIGHT)
	{
		while (++xCordinate < WIDTH)
		{
			c.r = info->min_r + xCordinate * ((info->max_r
						- info->min_r) / WIDTH);
			c.i = info->min_i + yCordinate * ((info->max_i
						- info->min_i) / HEIGHT);
			colorOnePixel(info->palette[isItFractal(c.r, c.i, info)],
				xCordinate, yCordinate, &info->img);
		}
		xCordinate = -1;
	}
	free(info->palette);
	mlx_put_image_to_window(info->mlx_ptr, info->window, info->mlx_img, 0, 0);
}

static char	*appendStringToMemoryAllocatedString(char *string, char *memoryAllocatedString)
{
	char	*new;
	size_t	size_s1;
	size_t	size_s2;

	if (!string || !memoryAllocatedString)
		return (NULL);
	size_s1 = ft_strlen(string);
	size_s2 = ft_strlen(memoryAllocatedString);
	new = malloc(size_s1 + size_s2 + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, string, size_s1 + 1);
	ft_strlcat(new, memoryAllocatedString, size_s1 + size_s2 + 1);
	free(memoryAllocatedString);
	return (new);
}

/*
        Updates text with RGB Values #needs improvement
*/
static void	drawText(t_info *info)
{
	char	*valueR;
	char	*valueG;
	char	*valueB;
	
	valueR = appendStringToMemoryAllocatedString("R: ", ft_itoa(info->color.r));
	valueG = appendStringToMemoryAllocatedString("G: ", ft_itoa(info->color.g));
	valueB = appendStringToMemoryAllocatedString("B: ", ft_itoa(info->color.b));
	mlx_string_put(info->mlx_ptr, info->window, 710, 100, rgbToColor(255, 0, 0),
		valueR);
	mlx_string_put(info->mlx_ptr, info->window, 770, 100, rgbToColor(0, 255, 0),
		valueG);
	mlx_string_put(info->mlx_ptr, info->window, 830, 100, rgbToColor(0, 0, 255),
		valueB);
	free(valueR);
	free(valueG);
	free(valueB);
	mlx_loop(info->mlx_ptr);
}

void	draw(t_info *info)
{
	mlx_clear_window(info->mlx_ptr, info->window);
	drawFractal(info);
	drawText(info);
}

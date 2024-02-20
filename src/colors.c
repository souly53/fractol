/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:08:27 by marmoral          #+#    #+#             */
/*   Updated: 2024/02/20 15:46:44 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	check_max_values(int key, t_info *info)
{
	if ((info->color.r + 25 > 255) && key == R_Color)
	{
		ft_putstr_fd("Max R_Color Value reached: ", 1);
		ft_putnbr_fd(info->color.r, 1);
		ft_putchar_fd('\n', 1);
		return (1);
	}
	else if ((info->color.g + 25 > 255) && key == G_Color)
	{
		ft_putstr_fd("Max G_Color Value reached: ", 1);
		ft_putnbr_fd(info->color.g, 1);
		ft_putchar_fd('\n', 1);
		return (1);
	}
	else if ((info->color.b + 25 > 255) && key == B_Color)
	{
		ft_putstr_fd("Max B_Color Value reached: ", 1);
		ft_putnbr_fd(info->color.b, 1);
		ft_putchar_fd('\n', 1);
		return (1);
	}
	else if ((info->color.r - 25 < 0) && key == R_Color_M)
	{
		ft_putstr_fd("R_Color Value can't go below 0: ", 1);
		ft_putnbr_fd(info->color.r, 1);
		ft_putchar_fd('\n', 1);
		return (1);
	}
	else if ((info->color.g - 25 < 0) && key == G_Color_M)
	{
		ft_putstr_fd("G_Color Value can't go below 0: ", 1);
		ft_putnbr_fd(info->color.g, 1);
		ft_putchar_fd('\n', 1);
		return (1);
	}
	else if ((info->color.b - 25 < 0) && key == B_Color_M)
	{
		ft_putstr_fd("B_Color Value can't go below 0: ", 1);
		ft_putnbr_fd(info->color.b, 1);
		ft_putchar_fd('\n', 1);
		return (1);
	}
	return (0);
}

void	precheck_colors(char **av, int ac)
{
	int	a;

	a = 2;
	if (ac == 7)
		a = 4;
	if ((ft_atoi(av[a]) > 255) || (ft_atoi(av[a]) < 0))
	{
		ft_putendl_fd("R Value has to be between 0 - 255", 1);
		exit (0);
	}
	if ((ft_atoi(av[a + 1]) > 255) || (ft_atoi(av[a + 1]) < 0))
	{
		ft_putendl_fd("G Value has to be between 0 - 255", 1);
		exit (0);
	}
	if ((ft_atoi(av[a + 2]) > 255) || (ft_atoi(av[a + 2]) < 0))
	{
		ft_putendl_fd("B Value has to be between 0 - 255", 1);
		exit (0);
	}
}

void	change_colors(int key, t_info *info)
{
	if (check_max_values(key, info))
		return ;
	else
	{
		if (key == R_Color)
			info->color.r += 25;
		else if (key == R_Color_M)
			info->color.r -= 25;
		else if (key == G_Color)
			info->color.g += 25;
		else if (key == G_Color_M)
			info->color.g -= 25;
		else if (key == B_Color)
			info->color.b += 25;
		else if (key == B_Color_M)
			info->color.b -= 25;
		draw(info);
	}
}

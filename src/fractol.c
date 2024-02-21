/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:59 by marmoral          #+#    #+#             */
/*   Updated: 2024/02/21 11:51:50 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
	-------EXAMPLES-------
	make re && ./fractol m 255 255 0
	make re && ./fractol j 0.285 0.01 0 255 255
	./fractol j 0.355534 -0.337292 0 255 255
	norminette src && norminette libft && norminette includes
	Sets up the Window.
*/

/*
	Sets up the window with accordingly MLX library functions.
*/
static void	setup_win(t_info *info)
{
	info->mlx_ptr = mlx_init();
	info->window = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	info->mlx_img = mlx_new_image(info->mlx_ptr, WIDTH, HEIGHT);
	info->img.addr = mlx_get_data_addr(info->mlx_img, &info->img.bpp,
			&info->img.line_len, &info->img.endian);
	mlx_key_hook(info->window, lisener, info);
	mlx_mouse_hook(info->window, zoom, info);
	mlx_hook(info->window, 17, 0, exit_ac, info);
}

/*
	Input parser.
*/

static int	check(t_info *info, char **av, int ac)
{
	init_info(info);
	if (((!ft_strncmp(av[1], "m", 1) && ac == 5))
		|| ((!ft_strncmp(av[1], "j", 1) && ac == 7)))
	{
		precheck_colors(av, ac);
		if (!ft_strncmp(av[1], "m", 1) && ac == 5)
		{
			info->type = 1;
			info->color.r = ft_atoi(av[2]);
			info->color.g = ft_atoi(av[3]);
			info->color.b = ft_atoi(av[4]);
		}
		else if (!ft_strncmp(av[1], "j", 1) && ac == 7)
		{
			info->type = 2;
			info->max_r = 2.0;
			info->min_i = -2.0;
			info->max_i = 2.0;
			info->k.r = ft_atod(av[2]);
			info->k.i = ft_atod(av[3]);
			errorprint(8, info);
			info->color.r = ft_atoi(av[4]);
			info->color.g = ft_atoi(av[5]);
			info->color.b = ft_atoi(av[6]);
		}
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac < 5 || !check(&info, av, ac))
		errorprint(9, (void *) 0);
	setup_win(&info);
	draw(&info);
	ft_putendl_fd("--Instructions--\n- User arrow keys to move\n"
		"- Use mouse scroll wheel or '+' & '-' "
		"keys to zoom in and out\n"
		"- Use 'Q' to increase and 'E' to decrease iterations\n--", 1);
	mlx_loop(info.mlx_ptr);
	return (0);
}
/*
test
*/
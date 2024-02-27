/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:03:30 by fsantill          #+#    #+#             */
/*   Updated: 2024/02/27 16:48:45 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	t_win	win;
	t_map	maps;

	if (argc == 2)
	{
		if (verify_extension(argv) != 0)
			return (1);
		maps = args_to_maps(argv, &maps);
		if (map_parsing(&maps) == 1)
			return (1);
		win.map = &maps;
		win.mlx_ptr = mlx_init();
		if (!win.mlx_ptr)
			exit (error_msg("Error\n\t• Mlx pointer doesn't exist"));
		win.mlx_win = mlx_new_window(win.mlx_ptr, 640, 480, "Game");
		if (!win.mlx_win)
			exit (error_msg("Error\n\t• Mlx win doesn't exist"));
		win.img = mlx_new_image(win.mlx_ptr, 640, 480);
		win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, \
		&win.line_length, &win.endian);
		mlx_xpm_file_to_image(win.mlx_ptr, "/1.xpm", &win.dim, &win.dim);
		mlx_put_image_to_window(win.mlx_ptr, win.mlx_win, win.img, 0, 0);
		mlx_loop(win.mlx_ptr);
		free(win.mlx_ptr);
		return (0);
	}
	exit (error_msg("Error\n\t• Invalid arguments"));
}

//	ft_printf("Llega\n");

//	mlx_key_hook(); bind keys for the game in the keyboard
//	mlx_loop_hook(drawing, .....); add a loop in the game
//	mlx_xpm_file_to_image(); transform xpm to image
//	mlx_put_image_to_window(); put the image in the win

//	map [y][x]
//	1111
//	1001
//	1111
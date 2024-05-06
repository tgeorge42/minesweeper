#include "../includes/demineur.h"

int	main(int ac, char **av)
{
	t_root	root;

	if (ac != 4)
		printf("Wrong number of arguments.\nThe correct syntax is : ./demineur 'height' 'width' 'number_of_bombs'\n");
	else
	{
		root.mlx = mlx_init();
		if (!root.mlx)
			exit(1);
		init_game(&root, av);
		root.mlx_win = mlx_new_window(root.mlx,
			35 * (root.game->width),
			35 * (root.game->height) + 105, "Demineur");
		draw_map(&root);
		mlx_hook(root.mlx_win, 2, 1L << 0, key_press, &root);
		mlx_hook(root.mlx_win, 4, 04, &mouse_press, &root);
		mlx_hook(root.mlx_win, 5, 1L<<3, &mouse_release, &root);
		mlx_hook(root.mlx_win, 17, 1L << 17, &cross_kill, &root);
		mlx_loop(root.mlx);
	}
}

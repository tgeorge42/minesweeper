#include "../../includes/demineur.h"

void	draw_hidden(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->hidden, x_offset, y_offset);
}

void	draw_mine(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->mine, x_offset, y_offset);
}

void	draw_explode(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->explode, x_offset, y_offset);
}

void	draw_flag(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->flag, x_offset, y_offset);
}

void	draw_empty(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->empty, x_offset, y_offset);
}

void	draw_one(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->one, x_offset, y_offset);
}

void	draw_two(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->two, x_offset, y_offset);
}

void	draw_three(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->three, x_offset, y_offset);
}

void	draw_four(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->four, x_offset, y_offset);
}

void	draw_five(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->five, x_offset, y_offset);
}

void	draw_six(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->six, x_offset, y_offset);
}

void	draw_seven(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->seven, x_offset, y_offset);
}

void	draw_eight(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->eight, x_offset, y_offset);
}

void	draw_smiley(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->smiley, x_offset, y_offset);
}

void	draw_dead(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->dead, x_offset, y_offset);
}

void	draw_grey(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->grey, x_offset, y_offset);
}

void	draw_win(t_root *root, int x_offset, int y_offset)
{
	mlx_put_image_to_window(root->mlx, root->mlx_win,
		root->game->pics->win, x_offset, y_offset);
}

void	redraw(t_root *root)
{
	int		i;
	int		j;

	i = 0;
	while (i < root->game->height)
	{
		j = 0;
		while (j < root->game->width)
		{
			if (root->game->game_map[i][j] == 'H')
				draw_hidden(root, j * 35, i * 35 + 105);
			else if (root->game->game_map[i][j] == 'M')
				draw_mine(root, j * 35, i * 35 + 105);
			else if (root->game->game_map[i][j] == 'E')
				draw_explode(root, j * 35, i * 35 + 105);
			else if (root->game->game_map[i][j] == '0')
				draw_empty(root, j * 35, i * 35 + 105);
			else if (root->game->game_map[i][j] == '1')
				draw_one(root, j * 35, i * 35 + 105);
			else if (root->game->game_map[i][j] == '2')
				draw_two(root, j * 35, i * 35 + 105);
			else if (root->game->game_map[i][j] == '3')
				draw_three(root, j * 35, i * 35 + 105);
			else if (root->game->game_map[i][j] == '4')
				draw_four(root, j * 35, i * 35 + 105);
			else if (root->game->game_map[i][j] == '5')
				draw_five(root, j * 35, i * 35 + 105);
			else if (root->game->game_map[i][j] == '6')
				draw_six(root, j * 35, i * 35 + 105);
			else if (root->game->game_map[i][j] == '7')
				draw_seven(root, j * 35, i * 35 + 105);
			else if (root->game->game_map[i][j] == '8')
				draw_eight(root, j * 35, i * 35 + 105);
			else if (root->game->game_map[i][j] == 'F')
				draw_flag(root, j * 35, i * 35 + 105);
			j++;
		}
		i++;
	}
}

void	draw_map(t_root *root)
{
	int		i;
	int		j;

	i = 0;
	while (i * 35 < 105)
	{
		j = 0;
		while (j < root->game->width)
		{
			draw_grey(root, j * 35, i * 35);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < root->game->height)
	{
		j = 0;
		while (j < root->game->width)
		{
			draw_hidden(root, j * 35, i * 35 + 105);
			j++;
		}
		i++;
	}
	draw_smiley(root, ((root->game->width * 35) / 2) - 29, (105 / 2) - 29);
}
#include "../../includes/demineur.h"

void	expand_empty(t_root *root, int i, int j)
{
	if (i >= 0 && i < root->game->height && j >= 0 && j < root->game->width)
	{
		if (root->game->game_map[i][j] != 'H')
			return ;
		root->game->game_map[i][j] = root->game->defined_map[i][j];
		if (root->game->defined_map[i][j] == '0')
		{
			expand_empty(root, i + 1, j);
			expand_empty(root, i + 1, j	+ 1);
			expand_empty(root, i, j + 1);
			expand_empty(root, i - 1, j + 1);
			expand_empty(root, i - 1, j);
			expand_empty(root, i - 1, j - 1);
			expand_empty(root, i, j - 1);
			expand_empty(root, i + 1, j - 1);
		}
	}
}

void	right_click_action(t_root *root, int x, int y)
{
	int	i;
	int	j;

	if (y < 105)
		i = -1;
	else
		i = (y - 105) / 35;
	j = x / 35;
	if (i >= 0)
	{
		if (root->game->game_map[i][j] == 'H')
			root->game->game_map[i][j] = 'F';
		else if (root->game->game_map[i][j] == 'F')
			root->game->game_map[i][j] = 'H';
	}
}

void	left_click_action(t_root *root, int x, int y)
{
	int	i;
	int	j;

	if (y < 105)
		i = -1;
	else
		i = (y - 105) / 35;
	j = x / 35;
	if (i >= 0)
	{
		if (root->game->defined_map[i][j] == 'M')
			root->game->game_map[i][j] = 'E';
		else
			expand_empty(root, i, j);
	}
}

void	reset_game(t_root *root)
{
	free_reset(root);
	init_game_map(root);
	draw_map(root);
}

int	key_press(int keycode, t_root *root)
{
	if (keycode == 65307)
	{
		free_all(root);
		exit (0);
	}
	else if (keycode == 114)
		reset_game(root);
	return (0);
}
void	end_game(t_root *root)
{
	int	i;
	int	j;

	i = 0;
	while (i < root->game->height)
	{
		j = 0;
		while (j < root->game->width)
		{
			if (root->game->defined_map[i][j] == 'M' && root->game->game_map[i][j] != 'E')
				root->game->game_map[i][j] = 'M';
			j++;
		}
		i++;
	}
	root->game->end_game = 1;
	draw_dead(root, ((root->game->width * 35) / 2) - 29, (105 / 2) - 29);
}

void	check_win_game(t_root *root)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	i = 0;
	while (i < root->game->height)
	{
		j = 0;
		while (j < root->game->width)
		{
			if (root->game->game_map[i][j] == 'H')
				nb++;
			j++;
		}
		i++;
	}
	if (nb == root->game->nb_mine_start)
		root->game->win_game = 1;
}

void	win_game(t_root *root)
{
	int	i;
	int	j;

	i = 0;
	while (i < root->game->height)
	{
		j = 0;
		while (j < root->game->width)
		{
			if (root->game->defined_map[i][j] == 'M')
				root->game->game_map[i][j] = 'F';
			else if (root->game->game_map[i][j] != 'F')
				root->game->game_map[i][j] = root->game->defined_map[i][j];
			j++;
		}
		i++;
	}
	draw_win(root, ((root->game->width * 35) / 2) - 29, (105 / 2) - 29);
}

int	mouse_press(int keycode, int x, int y, t_root *root)
{
	int	i;
	int	j;

	if (y < 105)
		i = -1;
	else
		i = (y - 105) / 35;
	j = x / 35;
	if (keycode == 1)
	{
		if (i >= 0)
		{
			if (root->game->end_game != 1 && root->game->win_game != 1 && root->game->game_map[i][j] != 'F')
			{
				root->game->first_click++;
				// printf("x = %d\ny = %d\n\n", x, y);
				// printf("i = %d\nj = %d\n\n", x / 35, y / 35);
				if (root->game->first_click == 1)
					init_defined_map(root, x, y);
				// else
				// 	ft_affiche_map(root->game->defined_map);
				left_click_action(root, x, y);
				redraw(root);
				if (root->game->game_map[i][j] == 'E')
					end_game(root);
				check_win_game(root);
				if (root->game->win_game == 1)
					win_game(root);
				redraw(root);
			}
		}
		if (x >= ((root->game->width * 35) / 2) - 29 && x <= ((root->game->width * 35) / 2) + 29
			&& y > (105 / 2) - 29 && y < (105 / 2) + 29)
			reset_game(root);
	}
	else if (keycode == 3 && root->game->end_game != 1 && root->game->win_game != 1)
	{
		right_click_action(root, x, y);
		redraw(root);
	}
	return (0);
}

int	mouse_release(int keycode, t_root *root)
{
	(void)root;
	(void)keycode;
	// printf("%d\n", keycode);
	// if (keycode == 1)
		// printf("marche release\n");
	return (0);
}

int	cross_kill(t_root *root)
{
	free_all(root);
	exit (0);
}
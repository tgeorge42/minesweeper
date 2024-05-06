#include "../../includes/demineur.h"

int	count_mines(t_root *root, int i, int j, int *border)
{
	int	nb;
	
	nb = 0;
	if (border[3] != 1)
	{
		if (root->game->defined_map[i][j + 1] == 'M')
			nb++;
	}
	if (border[1] != 1 && border[3] != 1)
	{
		if (root->game->defined_map[i + 1][j + 1] == 'M')
			nb++;
	}
	if (border[1] != 1)
	{
		if (root->game->defined_map[i + 1][j] == 'M')
			nb++;
	}
	if (border[1] != 1 && border[2] != 1)
	{
		if (root->game->defined_map[i + 1][j - 1] == 'M')
			nb++;
	}
	if (border[2] != 1)
	{
		if (root->game->defined_map[i][j - 1] == 'M')
			nb++;
	}
	if (border[0] != 1 && border[2] != 1)
	{
		if (root->game->defined_map[i - 1][j - 1] == 'M')
			nb++;
	}
	if (border[0] != 1)
	{
		if (root->game->defined_map[i - 1][j] == 'M')
			nb++;
	}
	if (border[0] != 1 && border[3] != 1)
	{
		if (root->game->defined_map[i - 1][j + 1] == 'M')
			nb++;
	}
	return (nb);
}


void	define_number(t_root *root, int i, int j)
{
	int	border[4];

	border[0] = 0;
	border[1] = 0;
	border[2] = 0;
	border[3] = 0;
	if (i == 0)
	{
		if (j == 0)
		{

			border[0] = 1;
			border[2] = 1;
		}
		else if (j == root->game->width - 1)
		{
			border[0] = 1;
			border[3] = 1;
		}
		else
			border[0] = 1;
	}
	else if (i == root->game->height - 1)
	{
		if (j == 0)
		{
			border[1] = 1;
			border[2] = 1;
		}
		else if (j == root->game->width - 1)
		{
			border[1] = 1;
			border[3] = 1;
		}
		else
		{
			border[1] = 1;
		}
	}
	else
	{
		if (j == 0)
			border[2] = 1;
		else if (j == root->game->width - 1)
			border[3] = 1;
	}
	root->game->defined_map[i][j] = (char)(count_mines(root, i, j, border) + 48);
}

void	place_numbers(t_root *root)
{
	int	i;
	int	j;

	i = 0;
	while (i < root->game->height)
	{
		j = 0;
		while (j < root->game->width)
		{
			if (root->game->defined_map[i][j] != 'M')
				define_number(root, i, j);
			j++;
		}
		i++;
	}
}

int	randomize_mines(t_root *root)
{
	int	nb;

	nb = rand() % (root->game->height * root->game->width + 1);
	// printf("nb_rand : %d\n", nb);
	if (nb >= root->game->nb_mine_init)
		return (0);
	else
		return (1);
}

void	place_mines(t_root *root, int x, int y)
{
	int	i;
	int	j;

	while (root->game->nb_mine_init > 0)
	{
		i = 0;
		while (i < root->game->height)
		{
			j = 0;
			while (j < root->game->width)
			{
				if (root->game->defined_map[i][j] != 'M' && randomize_mines(root) && root->game->nb_mine_init > 0
					&& (x / 35) != j && (y / 35) != i)
				{
					root->game->defined_map[i][j] = 'M';
					root->game->nb_mine_init--;
				}
				j++;
			}
			i++;
		}
	}
}

void	init_defined_map(t_root *root, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	root->game->nb_mine_init = root->game->nb_mine_start;
	root->game->defined_map = malloc(sizeof(char *) * (root->game->height + 1));
	if (!root->game->defined_map)
		free_all(root);
	while (i < root->game->height)
	{
		root->game->defined_map[i] = malloc(sizeof(char) * (root->game->width + 1));
		i++;
	}
	root->game->defined_map[i] = NULL;
	i = 0;
	while (root->game->defined_map[i])
	{
		j = 0;
		while (j < root->game->width)
		{
			root->game->defined_map[i][j] = '0';
			j++;
		}
		root->game->defined_map[i][j] = '\0';
		i++;
	}
	place_mines(root, x , y);
	place_numbers(root);
	// ft_affiche_map(root->game->defined_map);
}

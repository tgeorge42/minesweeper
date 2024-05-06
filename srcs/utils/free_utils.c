#include "../../includes/demineur.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab && tab[++i])
		free(tab[i]);
	free(tab[i]);
	free(tab);
}

void	free_images(t_root *root)
{
	if (root->game->pics->empty)
		mlx_destroy_image(root->mlx, root->game->pics->empty);
	if (root->game->pics->hidden)
		mlx_destroy_image(root->mlx, root->game->pics->hidden);
	if (root->game->pics->mine)
		mlx_destroy_image(root->mlx, root->game->pics->mine);
	if (root->game->pics->explode)
		mlx_destroy_image(root->mlx, root->game->pics->explode);
	if (root->game->pics->flag)
		mlx_destroy_image(root->mlx, root->game->pics->flag);
	if (root->game->pics->one)
		mlx_destroy_image(root->mlx, root->game->pics->one);
	if (root->game->pics->two)
		mlx_destroy_image(root->mlx, root->game->pics->two);
	if (root->game->pics->three)
		mlx_destroy_image(root->mlx, root->game->pics->three);
	if (root->game->pics->four)
		mlx_destroy_image(root->mlx, root->game->pics->four);
	if (root->game->pics->five)
		mlx_destroy_image(root->mlx, root->game->pics->five);
	if (root->game->pics->six)
		mlx_destroy_image(root->mlx, root->game->pics->six);
	if (root->game->pics->seven)
		mlx_destroy_image(root->mlx, root->game->pics->seven);
	if (root->game->pics->eight)
		mlx_destroy_image(root->mlx, root->game->pics->eight);
	if (root->game->pics->smiley)
		mlx_destroy_image(root->mlx, root->game->pics->smiley);
	if (root->game->pics->dead)
		mlx_destroy_image(root->mlx, root->game->pics->dead);
	if (root->game->pics->grey)
		mlx_destroy_image(root->mlx, root->game->pics->grey);
	if (root->game->pics->win)
		mlx_destroy_image(root->mlx, root->game->pics->win);
}

void	free_reset(t_root *root)
{
	if (root->game->defined_map)
		free_tab(root->game->defined_map);
	if (root->game->game_map)
		free_tab(root->game->game_map);
	init_reset_values(root);
}

void	free_all(t_root *root)
{
	if (root->game->pics)
		free_images(root);
	if (root->game->defined_map)
		free_tab(root->game->defined_map);
	if (root->game->game_map)
		free_tab(root->game->game_map);
	if (root->game->pics)
		free(root->game->pics);
	if (root->game)
		free(root->game);
	if (root->mlx_win)
		mlx_destroy_window(root->mlx, root->mlx_win);
	if (root->mlx)
	{
		mlx_destroy_display(root->mlx);
		free(root->mlx);
	}
	exit (0);
}

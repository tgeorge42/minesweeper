#include "../../includes/demineur.h"

void	get_content_pics_1(t_root *root)
{
	char	*path;
	int		x;
	int		y;

	x = 1000;
	y = 1000;
	path = "./images/hidden.xpm";
	root->game->pics->hidden = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->hidden)
		free_all(root);
	path = "./images/empty.xpm";
	root->game->pics->empty = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->empty)
		free_all(root);
	path = "./images/mine.xpm";
	root->game->pics->mine = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->mine)
		free_all(root);
	path = "./images/one.xpm";
	root->game->pics->one = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->one)
		free_all(root);
	path = "./images/two.xpm";
	root->game->pics->two = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->two)
		free_all(root);
	path = "./images/three.xpm";
	root->game->pics->three = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->three)
		free_all(root);
	path = "./images/four.xpm";
	root->game->pics->four = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->four)
		free_all(root);
	path = "./images/five.xpm";
	root->game->pics->five = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->five)
		free_all(root);
	path = "./images/six.xpm";
	root->game->pics->six = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->six)
		free_all(root);
	path = "./images/seven.xpm";
	root->game->pics->seven = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->seven)
		free_all(root);
	path = "./images/eight.xpm";
	root->game->pics->eight = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->eight)
		free_all(root);
	path = "./images/explode.xpm";
	root->game->pics->explode = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->explode)
		free_all(root);
	path = "./images/flag.xpm";
	root->game->pics->flag = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->flag)
		free_all(root);
	path = "./images/smiley.xpm";
	root->game->pics->smiley = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->smiley)
		free_all(root);
	path = "./images/dead.xpm";
	root->game->pics->dead = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->dead)
		free_all(root);
	path = "./images/grey.xpm";
	root->game->pics->grey = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->grey)
		free_all(root);
	path = "./images/win.xpm";
	root->game->pics->win = mlx_xpm_file_to_image(root->mlx, path, &x, &y);
	if (!root->game->pics->win)
		free_all(root);
}

void	get_pics(t_root *root)
{
	get_content_pics_1(root);
}

#include "../../includes/demineur.h"

void	ft_affiche_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	init_game_map(t_root *root)
{
	int	i;
	int	j;

	i = 0;
	root->game->game_map = malloc(sizeof(char *) * (root->game->height + 1));
	if (!root->game->game_map)
		free_all(root);
	while (i < root->game->height)
	{
		root->game->game_map[i] = malloc(sizeof(char) * (root->game->width + 1));
		i++;
	}
	root->game->game_map[i] = NULL;
	i = 0;
	while (root->game->game_map[i])
	{
		j = 0;
		while (j < root->game->width)
		{
			root->game->game_map[i][j] = 'H';
			j++;
		}
		root->game->game_map[i][j] = '\0';
		i++;
	}
}

void	init_reset_values(t_root *root)
{
	root->game->first_click = 0;
	root->game->end_game = 0;
	root->game->win_game = 0;
	root->game->defined_map = NULL;
	root->game->game_map = NULL;
}

void	init_values(t_root *root)
{
	root->game->first_click = 0;
	root->game->end_game = 0;
	root->game->win_game = 0;
	root->game->defined_map = NULL;
	root->game->game_map = NULL;
	root->mlx_win = NULL;
}

void	pictures_first_init(t_root *root)
{
	root->game->pics->hidden = NULL;
	root->game->pics->empty = NULL;
	root->game->pics->mine = NULL;
	root->game->pics->explode = NULL;
	root->game->pics->flag = NULL;
	root->game->pics->one = NULL;
	root->game->pics->two = NULL;
	root->game->pics->three = NULL;
	root->game->pics->four = NULL;
	root->game->pics->five = NULL;
	root->game->pics->six = NULL;
	root->game->pics->seven = NULL;
	root->game->pics->eight = NULL;
	root->game->pics->smiley = NULL;
	root->game->pics->dead = NULL;
	root->game->pics->grey = NULL;
	root->game->pics->win = NULL;
}

void	root_init(t_root *root)
{
	root->game = malloc(sizeof(t_game) * 1);
	if (!root->game)
		free_all(root);
	root->game->pics = malloc(sizeof(t_pictures) * 1);
	if (!root->game->pics)
		free_all(root);
	srand(time(NULL));
	init_values(root);
	pictures_first_init(root);
	get_pics(root);
}

void	init_game(t_root *root, char **av)
{
	root_init(root);
	root->game->height = ft_atoi(av[1]);
	root->game->width = ft_atoi(av[2]);
	root->game->nb_mine_start = ft_atoi(av[3]);
	if (root->game->height < 3 || root->game->width < 3 || root->game->nb_mine_start <= 0)
	{
		printf("Your game won't be fun with those parameters.\nKeep the height and width above 2 and put at least one mine !\n");
		printf("Quick tip : The correct syntax is : ./demineur 'height' 'width' 'number_of_bombs'\n");
		free_all(root);
	}
	if (root->game->nb_mine_start >= root->game->height * root->game->width)
	{
		printf("You put too much mines !\n");
		printf("Quick tip : The correct syntax is : ./demineur 'height' 'width' 'number_of_bombs'\n");
		free_all(root);
	}
	init_game_map(root);
}

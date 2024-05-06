#ifndef DEMINEUR_H
# define DEMINEUR_H


# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <mlx_int.h>
# include <time.h>

typedef struct s_pictures
{
	void	*empty;
	void	*hidden;
	void	*mine;
	void	*explode;
	void	*flag;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*smiley;
	void	*dead;
	void	*grey;
	void	*win;
}				t_pictures;

typedef struct s_game
{
	int				height;
	int				nb_mine_start;
	int				nb_mine_init;
	int				width;
	int				first_click;
	int				end_game;
	int				win_game;
	char			**game_map;
	char			**defined_map;
	t_pictures		*pics;
}			t_game;

typedef struct s_root
{
	void			*mlx;
	void			*mlx_win;
	t_game			*game;
}			t_root;

void	init_game(t_root *root, char **av);
void	init_values(t_root *root);
void	init_reset_values(t_root *root);
void	root_init(t_root *root);
void	pictures_first_init(t_root *root);
void	get_pics(t_root *root);
void	get_content_pics_1(t_root *root);
void	init_game_map(t_root *root);
void	init_defined_map(t_root *root, int x, int y);

int		ft_atoi(const char *str);
void	free_all(t_root *root);
int		key_press(int keycode, t_root *root);
int		mouse_press(int keycode, int x, int y, t_root *root);
int		mouse_release(int keycode, t_root *root);
int		cross_kill(t_root *root);

void	draw_map(t_root *root);
void	draw_hidden(t_root *root, int x_offset, int y_offset);
void	draw_dead(t_root *root, int x_offset, int y_offset);
void	draw_win(t_root *root, int x_offset, int y_offset);
void	redraw(t_root *root);
void	ft_affiche_map(char **map);

void	reset_game(t_root *root);
void	free_reset(t_root *root);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:49:54 by isel-jao          #+#    #+#             */
/*   Updated: 2020/10/16 09:17:15 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLE_H
#define EXAMPLE_H

#include "mlx.h"
#include "key_macos.h"
// #include "/home/h/minilibx_linux/mlx.h"
// #include "key_linux.h"

#include "../libft/libft.h"
#include "../printf/printf.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0

#define MIN() a < b? a: b)

#define NONE 0xFF0000
#define BLUE 1
#define YELLOW 256 + RED
#define GREEN 256
#define WHITE 65793
#define RED 256 * 256

#define UPR 9
#define UPL 7
#define DOWNR 3
#define DOWNL 1

#define WNDW 1600
#define WNDH 1220

#define V 2
#define H 4

typedef struct s_img
{
	void *img;
	int *data;
	int sizeline;
	int bpp;
	int endian;
} t_img;

typedef struct s_vec
{
	double x;
	double y;
} t_vec;

typedef struct s_player
{
	int exist;
	double x;
	double y;
	int radus;
	double turndir;
	double upmoove;
	double rightmove;
	double rotang;
	double speed;
	double rotspeed;
	double step;
	double fov;
	int dir;
} t_player;

typedef struct s_ray
{
	double ang;
	double distanc;
	int hitdir;
	int hitcontent;
	int dir;
	int wallside;
} t_ray;

typedef struct s_map
{
	int ret;
	char **map;
	int rows;
	int cols;
	int spr;
} t_map;

typedef struct s_sprite
{

	t_vec pos;
	t_vec dir;
	double dist;
	double ang;
	double cos;
	int num;
	int w;
	int h;
} t_sprite;

typedef struct s_line
{
	int x0;
	int y0;
	int x1;
	int y1;
	int dx;
	int dy;
	int incx;
	int incY;
	int e;
	int color;
} t_line;

typedef struct s_err
{
	int n;
	int m;
	int p;
} t_err;

typedef struct s_mlx
{
	void *mlx;
	char **tab;
	int w;
	int h;
	t_map map;
	t_img img;
	t_img textures[7];
	char *path[7];
	void *win;
	double *dist;
	t_player p;
	t_ray ray;
	int floorcol;
	int cielcol;
	t_sprite *spr;
	int s_num;
	int p_num;
	t_err err;
} t_mlx;

// global defenition;
char g_w;
char g_s;
char g_m;
char g_c;
int g_i;

void unit_mlx(t_mlx *m);
int ft_strerror(int ret, int i);
void ft_exit(t_mlx *m);
int parse(t_mlx *m, char *cub);
int ft_res(t_mlx *m, int i);
int ft_floorceil(t_mlx *m, int i);
int load_textures(t_mlx *m);
int ft_check_map(t_mlx *m);
// static double get_angel(char c);
int ft_player(t_mlx *m);
int ft_maplen(char *line);
char *ft_mapline(t_mlx *m, char *s);
int parse_map(t_mlx *m, int *i);
int ft_texture(t_mlx *m, int i);

int count_table(char **tab);
void free_table(char **tab);
char **new_table(void);
char **ft_join_table(char **tab, char *str);
int file_to_tab(char ***tab, char *cub);
void print_table(char **tab);
int ft_check(t_mlx *m);

void sqr(t_mlx *m, int x, int y, int h, int color);
void circle(t_mlx *m, int x0, int y0, int radus, int color);
void line(t_mlx *m, int x0, int y0, int x1, int y1, int color);

int is_up(double ang);
int is_right(double ang);
void renderwall(t_mlx *m, int fact, int col, double d, int side);
void update_player(t_mlx *m);
void put_mini_map(t_mlx *m);
void randerfloorceil(t_mlx *m);
void ray_render(t_mlx *m);

int init_env(t_mlx *m);
void clear(t_mlx *m);
char haswall(t_mlx *m, double x, double y);
void normlize(double *ang);
double wallcast(t_mlx *m, t_ray *ray, int *fact);
void clear(t_mlx *m);
void render_walls(t_mlx *m);
void render_sprites(t_mlx *m);
void render_mini_map(t_mlx *m);
void ft_sprite(t_mlx *m);
void save_bmp(t_mlx *m, int ac, char **av);
double Wallcast(t_mlx *m, t_ray *ray, int *fact);
int ft_error(int err);
// int in_map(t_mlx *m, double x, double y);
int ft_check_ext(char const *str, char const *ext);
void key_handle(t_mlx *m);
void update(t_mlx *m);
void render(t_mlx *m);
int init_player(t_mlx *m);
void init_image(t_mlx *m, int ac, char **av);
void normlize2(double *ang);


#endif

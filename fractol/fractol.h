/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 18:11:19 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/19 23:45:43 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>

# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"

# ifdef GPU
#  include <OpenCL/opencl.h>
#  define GPU_SOURCE "mx.cl"
#  define IS_GPU 1
# else
#  define IS_GPU 0
# endif

# include "size.h"

# define TITLE "Fractol by sguillia"

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define OFFSETX_SHRINK(x) (double)(-1 * ((double)(x) / WIN_W) * (X2 - X1))
# define OFFSETY_SHRINK(y) (double)(     ((double)(y) / WIN_H) * (Y2 - Y1))
# define OFFSETX_DEPLOY(x) (int)((x * WIN_W) / (X2 - X1) * -1)
# define OFFSETY_DEPLOY(y) (int)((y * WIN_H) / (Y2 - Y1))

# define DEFAULT				NULL
# define DEFAULT_FRACTALFT_NUM	1
# define DEFAULT_COLORFT		color1
# define DEFAULT_COLORFT_NUM	1

# define INIT_ITERMAX		20
# define ITERMAX_MIN		1
# define ITER_DELTA			0.1
# define OFFSETX_DELTA		OFFSETX_SHRINK(10)
# define OFFSETY_DELTA		OFFSETY_SHRINK(10)
# define ZOOM_DELTA_MUL		1.1
# define ZOOM_DELTA_ADD		0.1
# define KEYCODE_MAX		200
# define OFS_ZOOM_PWR		0.5

# define KEY_ESC			53
# define KEY_UP				126
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_DOWN			125
# define KEY_A				0
# define KEY_B				11
# define KEY_C				8
# define KEY_D				2

# define KEY_F				3
# define KEY_G				5
# define KEY_H				4
# define KEY_I				34
# define KEY_J				38
# define KEY_K				40

# define KEY_M				46
# define KEY_N				45

# define KEY_R				15
# define KEY_S				1
# define KEY_T				17
# define KEY_U				32
# define KEY_V				9
# define KEY_W				13
# define KEY_X				7

# define KEY_Z				6

# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEY_4				21
# define KEY_5				23
# define KEY_6				22
# define KEY_7				26
# define KEY_8				28
# define KEY_9				25
# define KEY_0				29

# define KEY_F13			105
# define KEY_F14			107
# define KEY_F15			113
# define KEY_F16			106
# define KEY_F17			64
# define KEY_F18			79
# define KEY_F19			80
# define KEY_PAD_PLUS		69
# define KEY_PAD_MIN		78
# define KEY_PAD_EQUAL		81
# define KEY_PAD_SLASH		75
# define KEY_PAD_STAR		67
# define KEY_PAD_0			82
# define KEY_PAD_1			83
# define KEY_PAD_2			84
# define KEY_PAD_3			85
# define KEY_PAD_4			86
# define KEY_PAD_5			87
# define KEY_PAD_6			88
# define KEY_PAD_7			89
# define KEY_PAD_8			91
# define KEY_PAD_9			92
# define KEY_SPACE			49
# define MOUSE_WHEEL_UP		4
# define MOUSE_WHEEL_DOWN	5

typedef struct s_mlx	t_mlx;

typedef struct			s_iter
{
	int		i;
	double	z;
	int		color;
}						t_iter;

typedef struct			s_calc
{
	double	zoom_x;
	double	zoom_y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
}						t_calc;

typedef struct			s_env
{
	t_mlx	*e;
	void	*win;
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		linesize;
	int		endian;
	t_iter	(*fractalft)(int, int, struct s_env);
	int		(*colorft)(t_iter, int);
	char	fractalft_num;
	char	colorft_num;
	int		itermax;
	float	fitermax;
	char	keys[KEYCODE_MAX];
	double	offset_x;
	double	offset_y;
	double	zoom_x;
	double	zoom_y;
	int		center_x;
	int		center_y;
	char	show_center;
	double	d_zoom_x;
	double	d_zoom_y;
	int		mouse_x;
	int		mouse_y;
	int		mouse_changed;
}						t_env;

# ifdef GPU

typedef struct			s_cl
{
	int					err;
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	commands;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				output;
	size_t				local;
	size_t				global;
}						t_cl;

struct					s_mlx
{
	void			*mlx;
	struct s_env	wins[3];
	t_cl			cl;
};

# else

struct					s_mlx
{
	void			*mlx;
	struct s_env	wins[3];
};

# endif

typedef struct			s_preset
{
	t_iter	(*fractalft)(int, int, struct s_env);
	int		(*colorft)(t_iter, int);
	int		fractalft_num;
	int		colorft_num;
	int		itermax;
	double	ofsx;
	double	ofsy;
	double	zoomx;
	double	zoomy;
	int		ctrx;
	int		ctry;
}						t_preset;

void					check_arguments(t_env *wins, int ac, char **av);
int						color1(t_iter ret, int itermax);
int						color2(t_iter ret, int itermax);
int						color3(t_iter ret, int itermax);
int						color4(t_iter ret, int itermax);
int						color5(t_iter ret, int itermax);
int						color6(t_iter ret, int itermax);
int						consider_inputs(t_env *w);
void					draw_center(t_env w);
void					draw_fractal(t_env w);
void					draw_extern_fractal(t_env w);
void					draw_gpu_fractal(t_env w);
void					dump_fractal_status(t_env w);
void					dump_fractal_status(t_env w);
void					exit_str(char *str);
int						expose_hook(t_env *w_ptr);
void					init_envs(t_mlx *e, t_env *wins, int ac);
void					init_fractal(t_mlx *e, t_env *w);
void					init_fractal_values(t_env *w);
void					init_t_mlx(t_mlx *e);
void					init_t_mlx(t_mlx *e);
t_iter					julia(int x, int y, t_env w);
int						keypressed(int keycode, t_env *w);
int						keyreleased(int keycode, t_env *w);
char					*load_gpu_sources(void);
void					load_preset(t_env *w, t_preset *preset);
int						loop_hook(t_mlx *e);
int						loop_hook(t_mlx *e);
t_iter					mandelbrot(int x, int y, t_env w);
int						mlx_pixel_put_img(t_env *w, int x, int y, int rgb);
int						motion_hook(int x, int y, t_env *w);
int						mouse_hook(int button, int x, int y, t_env *w);
t_iter					newton(int x, int y, t_env w);
void					opencl_init(t_mlx *e);
t_preset				*preset1(void);
t_preset				*preset2(void);
t_preset				*preset3(void);
t_preset				*preset4(void);
t_preset				*preset5(void);
void					redraw_fractal(t_env w);
void					redraw_fractal(t_env w);
void					set_zoom_center(t_env *w, int x, int y);
void					try_refresh_fractal(t_env *w);

#endif

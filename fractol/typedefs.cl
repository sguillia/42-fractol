#define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
#define X1 -2.1
#define Y1 -1.2

typedef struct	s_iter
{
	int		i;
	double	z;
	int		color;
}				t_iter;

typedef struct	s_calc
{
	double	zoom_x;
	double	zoom_y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
}				t_calc;

int		color1(t_iter ret, int itermax);
int		color2(t_iter ret, int itermax);
int		color3(t_iter ret, int itermax);
int		color4(t_iter ret, int itermax);
int		color5(t_iter ret, int itermax);
int		color6(t_iter ret, int itermax);

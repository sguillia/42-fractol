# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 15:26:24 by sguillia          #+#    #+#              #
#    Updated: 2016/02/19 23:45:16 by sguillia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

#NAME = a.out
NAME = fractol

CC_FLAGS = -Wall -Wextra -Werror
#CC_FLAGS = -O3
#CC_FLAGS =

#SRC = $(wildcard *.c)

SRC = \
	check_arguments.c \
	colors.c \
	colors2.c \
	consider_inputs.c \
	draw_center.c \
	draw_fractal.c \
	draw_gpu_fractal.c \
	dump_fractal_status.c \
	exit_str.c \
	expose_hook.c \
	init_envs.c \
	init_fractal.c \
	init_fractal_values.c \
	init_t_mlx.c \
	julia.c \
	keypressed.c \
	keyreleased.c \
	load_gpu_sources.c \
	load_preset.c \
	loop_hook.c \
	main.c \
	mandelbrot.c \
	mlx_pixel_put_img.c \
	motion_hook.c \
	mouse_hook.c \
	newton.c \
	opencl_init.c \
	preset1.c \
	preset2.c \
	preset3.c \
	preset4.c \
	preset5.c \
	redraw_fractal.c \
	set_zoom_center.c \
	try_refresh_fractal.c

O_FILES = $(SRC:.c=.o)

MLX_LIB = -L/usr/local/lib -lmlx -framework OpenGL -framework Appkit
MLX_I   = -I/usr/local/include

LIBFT_L = -Llibft -lft
LIBFT_I = -Ilibft

# Enables precision double output
PRECISION = -DPRECISION

SPECIAL =

default: show_usage keys

show_usage:
	@echo "\x1b[1;31m~~~ Fractol Makefile ~~~\x1b[0m"
	@echo "Command examples :"
	@echo ""
	@echo "Make with CPU as processing unit"
	@echo "\x1b[1;33mmake cpu\x1b[0m"
	@echo ""
	@echo "Make with GPU as processing unit"
	@echo "\x1b[1;33mmake gpu\x1b[0m"
	@echo ""
	@echo "Don't forget to do this before switching between CPU and GPU :"
	@echo "\x1b[1;33mmake fcleanp\x1b[0m"
	@echo ""
	@echo "Or run one of the followings :"
	@echo "\x1b[1;33mmake repcpu\x1b[0m"
	@echo "\x1b[1;33mmake repgpu\x1b[0m"
	@echo ""
	@echo "You can also run with optional parameters :"
	@echo ""
	@echo "Run with memory problems but psychedelic (may crash) (CPU only)"
	@echo "\x1b[1;33mmake special cpu\x1b[0m"
	@echo ""
	@echo "Run with no double precision on STDOUT"
	@echo "\x1b[1;33mmake noprecision cpu\x1b[0m"
	@echo ""
	@echo "Run multiple commands :"
	@echo "\x1b[1;33mmake special noprecision repcpu\x1b[0m"
	@echo ""
	@echo "Show readme file :"
	@echo "\x1b[1;33mmake readme\x1b[0m"
	@echo ""

keys:
	@echo "\x1b[1;31m~~~ Fractol keys ~~~\x1b[0m"
	@echo ""
	@echo "\x1b[1;33mA S W D\x1b[0m\t\tOffset"
	@echo ""
	@echo "\x1b[1;33mI K\x1b[0m\t\tIncrease/decrease maximum iterations"
	@echo ""
	@echo "\x1b[1;33m1 2 3 ...\x1b[0m\t(from keyboard, not keypad) Presets"
	@echo ""
	@echo "\x1b[1;33mZ X C V B N\x1b[0m\tChange color"
	@echo ""
	@echo "\x1b[1;33mSpace\x1b[0m\t\tPause mouse (julia fractal)"
	@echo ""
	@echo "Zoom (from keypad) :"
	@echo "\x1b[1;33m+ -\x1b[0m\t\tRelative (* /)"
	@echo "\x1b[1;33m5 8\x1b[0m\t\tRelative X"
	@echo "\x1b[1;33m6 9\x1b[0m\t\tRelative Y"
	@echo "\x1b[1;33m* <F19>\x1b[0m\t\tAbsolute (+ -)"
	@echo "\x1b[1;33m= <F17>\x1b[0m\t\tAbsolute X"
	@echo "\x1b[1;33m/ <F18>\x1b[0m\t\tAbsolute Y"
	@echo ""

readme:
	@cat README.txt

all: make_libft $(NAME)

#makeautoheader:
#	./genautoheader output.h $(SRC)

make_libft:
	make -C libft

#$(NAME): makeautoheader $(O_FILES)
$(NAME): $(O_FILES)
	$(CC) $(CC_FLAGS) $(O_FILES) -o $(NAME) $(LIBFT_L) $(MLX_LIB) $(GPU_L)

%.o:%.c fractol.h size.h
	$(CC) $(CC_FLAGS) -c -o $@ $< $(LIBFT_I) $(MLX_I) \
	$(GPU_MACRO) $(PRECISION) $(SPECIAL)

clean: cleanp clean_libft

cleanp:
	rm -rf $(O_FILES)

clean_libft:
	make -C libft clean

fclean: fclean_libft fcleanp

fcleanp: cleanp
	rm -rf $(NAME)

fclean_libft:
	make -C libft fclean

re: fclean all

rep: fcleanp all

wre: wmode re

wrep: wmode rep

wmode:
	$(eval CC_FLAGS = -Wall -Wextra -Werror)

re_libft:
	make -C libft re

GPU: set_gpu_flags all

gpu: GPU

CPU: all

cpu: CPU

set_gpu_flags:
	@echo "\x1b[1;33mGPU flags are being set."\
	" Make clean if linkage error happen\x1b[0m"
	$(eval GPU_L = -framework OpenCL)
	$(eval GPU_MACRO = -DGPU)

repgpu: fcleanp GPU

repcpu: fcleanp CPU

noprecision:
	$(eval PRECISION =)

special:
	$(eval SPECIAL = -DUNDEFINED)

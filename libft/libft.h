/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/10 23:09:11 by sguillia          #+#    #+#             */
/*   Updated: 2016/02/12 22:06:40 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*
**	Masks used by wchar functions
*/

# define WMASK1 128
# define WMASK2 192
# define WMASK3 224
# define WMASK4 240

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**Existing functions
*/

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *big, const char *little,
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** Additional functions
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Linked lists (bonus)
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Personal functions
*/

int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isspace(int c);
int					ft_atoi_base(const char *str, int base);
char				*ft_itoa_base(int val, int base);
char				*ft_stralloc(char *str, size_t n);
char				*ft_strrealloc(char *dest, const char *src);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
void				*ft_memrchr(const void *s, int c, size_t n);
void				*ft_memmem_type1(const void *haystack, size_t haystacklen,
		const void *needle, size_t needlelen);
void				*ft_memmem_type2(const void *haystack, size_t haystacklen,
		const void *needle, size_t needlelen);
int					ft_abs(int n);
int					ft_is42space(int c);
int					ft_maxof(int a, int b);
int					ft_minof(int a, int b);
void				ft_lstaddend(t_list *alst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstbeforelast(t_list *lst);
char				*ft_strndup(const char *s, size_t n);
int					ft_wchar_to_str(char *dest, unsigned int c);
unsigned int		ft_get_bits(unsigned int c, int rstart, int len);
int					ft_wstr_strlen(unsigned int *wstr);
char				*ft_wstr_to_str(unsigned int *wstr);
int					ft_wchar_numbytes(unsigned int c);
int					ft_expo(int base, unsigned int expo);
void				ft_strtolower(char *str);
void				ft_strtoupper(char *str);
int					ft_lstcount(t_list *lst);
char				**ft_free_tab(char **mytab);
int					ft_tablen(char **tab);
t_list				*ft_lstat(t_list *lst, int left);
size_t				ft_tab_strlen(char **tab);
char				*ft_tab_to_str(char **tab, char separator);
size_t				ft_lst_strlen(t_list *lst);
char				*ft_lst_to_str(t_list *lst);
void				*ft_check_malloc(void *assertion);

#endif

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**	Flag_uppercase doesn't exist and is not an input flag
**	It is used by parse_aliases.c
*/

# define FLAG_HASH			1 << 0
# define FLAG_ZERO			1 << 1
# define FLAG_MIN			1 << 2
# define FLAG_SPACE			1 << 3
# define FLAG_PLUS			1 << 4
# define FLAG_APOS			1 << 5
# define FLAG_UPPERCASE		1 << 6

/*
**	LMOD = length modifier
*/

# define LMOD_HH			1 << 0
# define LMOD_H				1 << 1
# define LMOD_LL			1 << 2
# define LMOD_L				1 << 3
# define LMOD_J				1 << 4
# define LMOD_Z				1 << 5

/*
**	argpos			va_arg position of the argument (starting from 1)
**	flags			+ - # etc.
**	field_width		Minimum field width
**	precision		Precision
**	lmod			Length modifier
**	specifier		The final letter (s, d, c, ...)
**	stopflag		Set to 1 when an error occurs
**	color			ANSI color code when a color is specified. Null otherwise.
*/

typedef struct		s_options
{
	int		argpos;
	char	flags;
	int		field_width;
	int		precision;
	char	lmod;
	char	specifier;
	char	stopflag;
	char	*color;
}					t_options;

char				*add_prefix(char *prefix, char *str, int free_prefix);
char				*adjust_left(char *str, int field_width);
char				*adjust_right(char *str, int field_width);
void				check_field_width(t_options *options);
int					myerror(char *str);
char				*flag_zero_d(char *str, int field_width);
char				*flag_zero_ouxpb(char *str, int field_width);
char				*flag_zero_s(char *str, int field_width);
int					ft_asprintf(char **ret, const char *format, ...);
char				*ft_intmaxtoa_base(intmax_t val, intmax_t base);
char				*ft_lltoa_base(long long val, long long base);
int					ft_lst_freestr(t_list *lst);
int					ft_lstprintstr(t_list *lst);
int					ft_lstprintstr_fd(t_list *lst, int fd);
int					ft_printf(const char *format, ...);
int					ft_printf_fd(int fd, const char *format, ...);
void				ft_printf_buffer_add(t_list *output, void *content,
		size_t code);
char				*ft_sizettoa_base(size_t val, size_t base);
char				*ft_strjoin3(const char *s1, const char *s2,
		const char *s3);
char				*ft_uintmaxtoa_base(uintmax_t val, uintmax_t base);
char				*ft_ulltoa_base(unsigned long long val,
		unsigned long long base);
void				*get_arg(int argnum, t_list *lst, va_list *ap);
char				*get_n_chars(int num, char c);
void				handle_converted_b(t_options *options, t_list *output,
		char *str);
void				handle_converted_d(t_options *options, t_list *output,
		char *str);
void				handle_converted_nullc(t_options *options, t_list *output);
void				handle_converted_p(t_options *options, t_list *output,
		char *str);
void				handle_converted_s(t_options *options, t_list *output,
		char *str);
void				handle_converted_oux(t_options *options, t_list *output,
		char *str);
char				*handle_modulo(char *format, t_list *output);
const char			*handle_nonmodulo(const char *format, t_list *output);
void				handle_specifier(t_options *options, t_list *output);
void				handle_specifier_b(t_options *options, t_list *output,
		void *arg);
void				handle_specifier_c(t_options *options, t_list *output,
		void *arg);
void				handle_specifier_d(t_options *options, t_list *output,
		void *arg);
void				handle_specifier_p(t_options *options, t_list *output,
		void *arg);
void				handle_specifier_r(t_options *options, t_list *output,
		void *arg);
void				handle_specifier_s(t_options *options, t_list *output,
		void *arg);
void				handle_specifier_oux(t_options *options, t_list *output,
		void *arg);
void				handle_precision_b(t_options *options, t_list *output,
		char *str);
void				handle_precision_d(t_options *options, t_list *output,
		char *str);
void				handle_precision_nullc(t_options *options, t_list *output);
void				handle_precision_p(t_options *options, t_list *output,
		char *str);
void				handle_precision_s(t_options *options, t_list *output,
		char *str);
void				handle_precision_oux(t_options *options, t_list *output,
		char *str);
void				handle_unknown_specifier(t_options *options,
		t_list *output);
void				parse_aliases(t_options *options);
char				*parse_argpos(char *params, t_options *options,
		t_list *output);
char				*parse_casters(char *params,
		t_options *options);
int					parse_color(char *params, t_list *output);
char				*parse_options(char *params, t_options *options,
		t_list *output);
char				*parse_precision(char *params, t_options *options,
		t_list *output);
char				*parse_flags(char *params, t_options *options);
char				*parse_field_width(char *params, t_options *options,
		t_list *output);

#endif

#ifndef COLORS_H
# define COLORS_H

/*
**	Defines ANSI colors
*/

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

int					get_next_line(int const fd, char **line);

#endif

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int	c_print(int c);
int	s_print(char *s);
int	p_print(unsigned long p);
int	d_i_print(int d);
int	u_print(unsigned int u);
int	x_print(unsigned int x);
int	upper_x_print(unsigned int x);
int	per_print(void);

int	put_ten2sixteen(unsigned int n, int is_upper);
int	put_ten2sixteen_long(unsigned long n);
int	put_nbr(int n);
int	put_unsigned_nbr(unsigned int n);

#endif
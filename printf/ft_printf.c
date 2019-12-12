/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ichougra <ichougra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 13:50:31 by ichougra     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 18:44:02 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_struct(t_bool *new)
{
	printf("\nargs = %c\n", new->args);
	printf("nb = %d\n", new->nb);
	printf("cp_nb = %ld\n", new->cp_nb);
	printf("unb = %u\n", new->unb);
	printf("pre = %d\n", new->pre);
	printf("min = %d\n", new->min);
	printf("zero = %d\n", new->zero);
	printf("left = %d\n", new->left);
	printf("cas = %d\n", new->cas);
	printf("str = %s\n", new->str);
	printf("_______________\n");
}

int		cmpt_nb(long nb)
{
	int count;

	count = 0;
	if (nb < 0)
		count++;
	if (nb < 0)
		nb *= -1;
	if (nb == 0)
		count++;
	while (nb >= 1)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

void	testing_min(t_bool *new)
{
	if (new->min < 0)
	{
		new->left = 1;
		new->min *= -1;
		new->zero = 0;
	}
}

int		print_option(const char *str, va_list ap, t_bool *new, ...)
{
	int i;
	int j;

	j = 0;
	i = 0;
	new->ret = 0;
	while (str[i])
	{
		new->cas = 0;
		if (str[i] && str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				return (new->ret);
			if (scan_line(str, &i, new, ap) == 1)
				new->cas = 1;
		//	print_struct(new);
			testing_min(new);
			if (new->cas != 4)
				display(str, i, new);
		}
		else
			new->ret += write(1, &str[i], 1);
		i++;
	}
	// if (new->cas == 1 && new->args != 's')
	// 	new->ret += ft_putchar('\n');
	return (new->ret);
}

int		ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	t_bool	new;

	i = 0;
	va_start(args, str);
	if (str[i])
	i = print_option(str, args, &new);
	va_end(args);
	return (i);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ichougra <ichougra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 12:31:59 by ichougra     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 13:17:01 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		calcul_t(t_bool *new)
{
	if (new->pre < ft_strlen(new->str))
		return (ft_strlen(new->str));
	else
		return (ft_strlen(new->str) + (new->pre - ft_strlen(new->str)));
}

int		calcul_2(t_bool *new)
{
	if (new->pre > ft_strlen(new->str) && new->args == 's')
		return (ft_strlen(new->str));
	return (new->pre);
}

void	print_leftmin(t_bool *new)
{
	while (new->min > ft_strlen(new->str))
	{
		new->ret += ft_putchar(' ');
		new->min--;
	}
}

void	print_left(t_bool *new)
{
	if ((new->args == 'x' || new->args == 'X') && new->nb < 0)
		while (new->min > ft_strlen(new->str))
		{
			new->ret += ft_putchar(' ');
			new->min--;
		}
	else
		while (new->min > calcul_t(new))
		{
			new->ret += ft_putchar(' ');
			new->min--;
		}
}

void	print_pre(t_bool *new)
{
	int j;

	j = 0;
	if ((new->args == 'x' || new->args == 'X')
	&& new->pre > ft_strlen(new->str))
		while (j < new->pre - ft_strlen(new->str))
		{
			new->ret += ft_putchar('0');
			j++;
		}
	if (new->args == 's')
		while (new->str[j] && new->pre)
		{
			new->ret += ft_putchar(new->str[j]);
			j++;
			new->pre--;
		}
	else
		new->ret += ft_putstr(new->str);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_utils2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ichougra <ichougra@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 22:18:00 by ichougra     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 20:52:29 by ichougra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_un(unsigned int n)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_un(nb / 10);
		ft_putnbr_un(nb % 10);
	}
	else
	{
		nb = nb + '0';
		ft_putchar(nb);
	}
}

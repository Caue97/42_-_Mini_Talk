/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:08:11 by felcaue-          #+#    #+#             */
/*   Updated: 2022/02/17 19:06:40 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write (1, &c, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		ft_putchar_fd(nb + '0', fd);
	}
}

int	ft_atoi(const char *to_convert)
{
	int	f_negative;
	int	number;
	int	what_return;

	number = 0;
	f_negative = 0;
	while ((*to_convert >= 9 && *to_convert <= 13) || *to_convert == 32)
		to_convert++;
	if (*to_convert == '-' || *to_convert == '+')
	{
		if (*to_convert == '-')
			f_negative = 1;
		to_convert++;
	}
	while (*to_convert >= '0' && *to_convert <= '9')
	{
		number = number * 10 + (*to_convert - '0');
		to_convert++;
	}
	what_return = check_overflow(number, f_negative);
	if (what_return != 1)
		return (what_return);
	if (f_negative)
		return (number *= -1);
	return (number);
}

int	check_overflow(int number_o, int f_negative_o)
{
	unsigned int	num_for_check;

	num_for_check = number_o;
	if (num_for_check > 2147483648 && f_negative_o)
	{
		return (0);
	}
	if (num_for_check > 2147483647 && !f_negative_o)
	{
		return (-1);
	}
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	n_d_letras;

	if (str == NULL)
	{
		return (0);
	}
	n_d_letras = 0;
	while (str[n_d_letras] != '\0')
	{
		n_d_letras++;
	}
	return (n_d_letras);
}

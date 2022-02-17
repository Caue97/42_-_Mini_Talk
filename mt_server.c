/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:21:41 by felcaue-          #+#    #+#             */
/*   Updated: 2022/02/11 20:11:08 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	int					pid;
	struct sigaction	s_sig;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	s_sig.sa_handler = receive_signal;
	sigemptyset(&s_sig.sa_mask);
	s_sig.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	while (1)
	{
		pause();
	}
}

void	receive_signal(int signal)
{
	static char	c_from_bi = 255;
	static int	counter_for_bi = 0;

	if (signal == SIGUSR1)
	{
		c_from_bi = c_from_bi ^ (128 >> counter_for_bi);
	}
	++counter_for_bi;
	if (counter_for_bi == 8)
	{
		write(1, &c_from_bi, 1);
		counter_for_bi = 0;
		c_from_bi = 255;
	}
}

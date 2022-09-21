/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljustici <ljustici@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:21:42 by ljustici          #+#    #+#             */
/*   Updated: 2022/09/17 17:44:03 by ljustici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pglibft/libft.h"
#include <signal.h>

void	ft_kill_bits(char c, int pid)
{
	int		i;
	char	the_bit;

	i = 8;
	while (i--)
	{
		the_bit = ((c >> i) & 1) + '0';
		if (the_bit == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
	}	
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (i <= ft_strlen(argv[2]))
		{
			ft_kill_bits(argv[2][i], pid);
			i++;
		}
	}
	else
		ft_printf("Incorrect number of arguments.\n");
	return (0);
}

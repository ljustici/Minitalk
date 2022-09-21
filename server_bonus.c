/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljustici <ljustici@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:17:00 by ljustici          #+#    #+#             */
/*   Updated: 2022/09/17 17:43:49 by ljustici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pglibft/libft.h"
#include <signal.h>

void	put_client_pid(pid_t pid)
{
	write(1, "[LISTENING TO CLIENT ", 21);
	ft_putnbr(pid);
	write(1, "]\n", 2);
}

void	respond(int signal, pid_t pid)
{
	if (signal == SIGUSR1)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
	else if (signal == SIGUSR2)
	{
		write(1, "\n[END OF CLIENT'S MESSAGE]\n", 27);
		kill(pid, SIGUSR2);
	}
}

void	get_bits(char *c, int *i, pid_t pid)
{
	*c |= (1 << *i);
	respond(SIGUSR1, pid);
}

void	handle_sigusr(int sig, siginfo_t *info, void *ignore)
{
	static pid_t	pid = 0;
	static char		c = 0;
	static int		i = 7;

	(void)ignore;
	if (pid == 0 && info->si_pid != 0)
	{
		pid = info->si_pid;
		put_client_pid(pid);
	}
	if (sig == SIGUSR1)
		get_bits(&c, &i, pid);
	i--;
	if (i < 0)
	{
		i = 7;
		if (c == '\0')
		{
			respond(SIGUSR2, pid);
			pid = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t				current_pid;
	struct sigaction	sa;

	(void)argv;
	if (argc == 1)
	{
		sa.sa_sigaction = handle_sigusr;
		sa.sa_flags = SA_SIGINFO;
		current_pid = getpid();
		ft_printf("%d\n", current_pid);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	return (0);
}

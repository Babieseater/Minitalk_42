/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:17:46 by smayrand          #+#    #+#             */
/*   Updated: 2022/10/19 12:50:00 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handler_s(int signal, siginfo_t *info, void *charlesiii)
{
	static int	byte;
	static char	c;

	(void)charlesiii;
	if (byte == 0)
		byte = 8;
	if (signal == SIGUSR2)
		signal = FALSE;
	else if (signal == SIGUSR1)
		signal = TRUE;
	byte--;
	c += (signal & 1) << byte;
	if (byte == 0)
	{
		if (!c)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		ft_printf("%c", c);
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	signal;

	(void)argc;
	(void)argv;
	pid = getpid();
	ft_printf("%s\n", "┌────────────────────┐");
	ft_printf("%s\n", "│   Minitalk Server  │");
	ft_printf("│   PID : %d      │\n", pid);
	ft_printf("%s\n", "└────────────────────┘");
	signal.sa_sigaction = handler_s;
	signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal, FALSE);
	sigaction(SIGUSR2, &signal, FALSE);
	while (TRUE)
		pause();
	return (FALSE);
}
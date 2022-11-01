/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:17:52 by smayrand          #+#    #+#             */
/*   Updated: 2022/11/01 13:04:33 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_error(char *msg)
{
	ft_printf("Error\n%s", msg);
	exit (0);
}

void	handler_c(int pid, char *byte)
{
	int	size;
	int	c;

	size = ft_strlen(byte);
	while (size != -1)
	{
		c = 8;
		while (c)
		{
			c--;
			if ((*byte >> c & 1) == 1)
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
			usleep(75);
		}
		byte++;
		size--;
	}
}

void	receiver(int charlesiii)
{
	(void)charlesiii;
	ft_printf("%s\n", "Signal has been received");
}

int	main(int argc, char **argv)
{
	int	pid;

	ft_printf("%s\n", "┌────────────────────┐");
	ft_printf("%s\n", "│   Minitalk Client  │");
	ft_printf("%s\n", "└────────────────────┘");
	if (argc != 3)
	{
		ft_error("Incorrect number of arguments");
		return (FALSE);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 1 || pid > 99998)
	{
		ft_error("Invalid PID");
		return (FALSE);
	}
	signal(SIGUSR1, receiver);
	handler_c(pid, argv[2]);
	return (FALSE);
}

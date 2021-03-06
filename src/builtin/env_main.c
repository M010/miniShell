/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbashir <mi243@ya.tu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:44:28 by sbashir           #+#    #+#             */
/*   Updated: 2021/01/08 13:16:00 by sbashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_stdio.h>

int	bi_env(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	while (*envp)
	{
		if (ft_strchr(*envp, '='))
		{
			ft_putstr(*envp);
			ft_putchar('\n');
		}
		envp++;
	}
	return (0);
}

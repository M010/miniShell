/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbashir <mi243@ya.tu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 18:08:43 by sbashir           #+#    #+#             */
/*   Updated: 2021/01/23 19:59:56 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <error_tools.h>
#include <env_tools.h>
#include <ft_string.h>

static int	exp_errprint(char *str)
{
	putstr_err("bash: export: ", 1);
	putstr_err(str, 1);
	putstr_err(" not a valid identifier\n", 1);
	return (1);
}

int			bi_export(int argc, char **argv, char **envp)
{
	int it;
	int ret;

	it = 1;
	ret = 0;
	if (argc == 1)
	{
		while (*envp)
			ft_printf("declare -x %s\n", *(envp++));
		return (0);
	}
	while (it < argc)
	{
		ret = 0;
		if (!ft_strchr(argv[it], '=') && ft_getenv(argv[it]) && it++)
			continue;
		if (!ft_putenv(argv[it]))
			ret = exp_errprint(argv[it]);
		it++;
	}
	return (ret);
}

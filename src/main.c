/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 03:33:51 by amalliar          #+#    #+#             */
/*   Updated: 2020/12/14 03:34:46 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils/msg_exit.h"
#include <ft_string.h>
#include <env_tools.h>
#include <ft_stdio.h>

extern char **environ;
void testAll()
{
	char **envp;
	char **envp_new;

	envp = environ;
	init_environ();
	envp_new = environ;
	ft_getenv("sadf");
	while (*envp || *envp_new)
		msg_assert(!ft_strcmp(*(envp++), *(envp_new++)), "init_environ error");
	char *save_path = ft_getenv("PATH");
	msg_assert(!ft_strcmp(ft_putenv("TEST=HELLO"), "TEST=HELLO"), "problem in putenv");
	msg_assert(!ft_strcmp(ft_getenv("TEST"), "HELLO"), "problem in getenv");
	msg_assert(!ft_strcmp(ft_setenv("TEST", "HELL"), "TEST=HELL"), "problem in setenv");
	msg_assert(!ft_strcmp(ft_getenv("TEST"), "HELL"), "problem in getenv");
	ft_unsetenv("TEST");
	ft_getenv("sadf");
	ft_printf("HI");
	msg_assert(!ft_strcmp(ft_getenv("TEST"), ""),"problem in unsetenv");
	msg_assert(!ft_strcmp(ft_getenv("PATH"), save_path), "problem in unsetenv or set env in PATH");
	ft_unsetenv("TEST");
	msg_assert(!ft_strcmp(ft_getenv("TEST"), ""),"problem in unsetenv (TEST)");
}

int		main(int argc, char **argv)
{
	testAll();
	(void)argc;
	(void)argv;
	return (0);
}


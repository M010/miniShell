/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbashir <mi243@ya.tu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 03:38:28 by sbashir           #+#    #+#             */
/*   Updated: 2021/01/02 03:39:28 by sbashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include <ft_list.h>

typedef struct		s_command
{
	char			*name;
	char			**params;
	_Bool			pipe;
	_Bool			f_stdin;
	_Bool			f_stdout;
	_Bool			f_stdout_append;
	char			*new_stdout;
	char			*new_stdin;
}					t_command;

int					process(const t_list *commands);

#endif

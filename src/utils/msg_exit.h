/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_exit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbashir <mi243@ya.ru>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 21:21:00 by sbashir           #+#    #+#             */
/*   Updated: 2020/10/14 21:21:00 by sbashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MSG_EXIT_H
# define MINIRT_MSG_EXIT_H

void	msg_exit(int i, char *msg);
void	msg_assert(_Bool exp, char *msg);
void	msg_arg_exit(int i, char *msg, char *problem);

#endif
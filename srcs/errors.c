/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 01:39:36 by gudias            #+#    #+#             */
/*   Updated: 2022/04/01 03:46:40 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_msg(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	//free
	
	exit (0);
}

//should free all before exit..

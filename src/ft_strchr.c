/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:01:04 by alistair          #+#    #+#             */
/*   Updated: 2022/03/10 19:14:26 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strchr(const char *s, char chr)
{
	unsigned int	i;

	i = 0;
	while (i <= (ft_strlen(s)))
	{
		if (s[i] == chr)
			return (i);
		i++;
	}
	return (-1);
}

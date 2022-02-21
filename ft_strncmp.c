/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 02:50:58 by alkane            #+#    #+#             */
/*   Updated: 2022/02/21 06:50:20 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			if ((s1[i] != s2[i]) || s1[i] == '\0' || s2[i] == '\0')
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		}
	}
	return (0);
}

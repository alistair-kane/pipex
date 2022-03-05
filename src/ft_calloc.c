/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:09:45 by alkane            #+#    #+#             */
/*   Updated: 2022/03/05 01:10:21 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	char	*s;
	int		total;

	total = nmemb * size;
	p = malloc(nmemb * size);
	if (!p)
		return (0);
	s = p;
	while (total--)
	{
		*s = '\0';
		s++;
	}
	return (p);
}

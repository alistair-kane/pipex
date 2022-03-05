/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:06:31 by alkane            #+#    #+#             */
/*   Updated: 2022/03/05 01:11:04 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dst;
	unsigned int	total_size;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)malloc(sizeof (char) * total_size);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2[++j])
		dst[i++] = s2[j];
	dst[i] = '\0';
	return (dst);
}
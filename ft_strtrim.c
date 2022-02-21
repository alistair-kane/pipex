/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:00:50 by alkane            #+#    #+#             */
/*   Updated: 2022/02/21 07:04:02 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		size;
	char	*dst;

	if (!s1)
		return (NULL);
	start = 0;
	end = (int)ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && start < end)
		start++;
	while (ft_strchr(set, s1[end]) && end > 0)
		end--;
	if (start > end)
		return (ft_strdup(""));
	size = (end - start) + 2;
	dst = malloc(sizeof(char) * size);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, (s1 + start), size);
	return (dst);
}

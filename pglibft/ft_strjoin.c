/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljustici <ljustici@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 01:49:30 by ljustici          #+#    #+#             */
/*   Updated: 2022/09/04 14:29:01 by ljustici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	size_s2;
	size_t	size_s1;
	char	*result;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 && !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	result = (char *)malloc(size_s1 + size_s2);
	if (!result)
		return (0);
	i = size_s1 + size_s2;
	result[i] = '\0';
	while (size_s2 > 0)
		result[--i] = s2[--size_s2];
	while (size_s1 > 0)
		result[--i] = s1[--size_s1];
	free(s1);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:30:57 by lucocozz          #+#    #+#             */
/*   Updated: 2019/11/12 15:32:37 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little)
{
	size_t i;
	size_t j;

	if (little[0] == '\0')
		return ((char*)big);
	j = 0;
	while (big[j] != '\0')
	{
		if (big[j] == little[0])
		{
			i = 1;
			while (little[i] != '\0' && big[j + i] == little[i])
				++i;
			if (little[i] == '\0')
				return ((char*)&big[j]);
		}
		j++;
	}
	return (0);
}

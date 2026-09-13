/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 00:52:38 by ayhshala          #+#    #+#             */
/*   Updated: 2026/09/13 14:13:49 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*first;
	const unsigned char	*last;

	first = (const unsigned char *)s1;
	last = (const unsigned char *)s2;
	while (n--)
	{
		if (*first != *last)
			return (*first - *last);
		first++;
		last++;
	}
	return (0);
}

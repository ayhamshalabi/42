/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:13:50 by ayhshala          #+#    #+#             */
/*   Updated: 2026/09/08 15:13:50 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char const	*src_start;

	src_start = src;
	if (dstsize == 0)
		return ft_strlen(src);
	while (--dstsize && *src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return ft_strlen(src_start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 22:58:52 by ayhshala          #+#    #+#             */
/*   Updated: 2026/09/08 22:58:52 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	temp;

	dst_len = 0;
	src_len = ft_strlen(src);
	temp = dstsize;
	while (temp-- && *dst)
	{
		dst_len++;
		dst++;
	}
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	//else if (dstsize > dst_len)
	dstsize -= dst_len;
	while (--dstsize && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_len + src_len);
}
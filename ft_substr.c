/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 10:24:20 by ayhshala          #+#    #+#             */
/*   Updated: 2026/09/13 14:13:23 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*ptr_start;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr_start = ptr;
	s += start;
	while (len-- && *s)
		*ptr++ = *s++;
	*ptr = '\0';
	return (ptr_start);
}

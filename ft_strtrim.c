/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 10:58:33 by ayhshala          #+#    #+#             */
/*   Updated: 2026/09/13 14:13:26 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	front_count(char const *s1, char const *set)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s1[i] && in_set(s1[i], set))
	{
		count++;
		i++;
	}
	return (count);
}

static size_t	back_count(char const *s1, char const *set)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = ft_strlen(s1);
	while (i > 0 && in_set(s1[i - 1], set))
	{
		count++;
		i--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*ptr_start;
	size_t	front;
	size_t	back;
	size_t	ptr_len;

	front = front_count(s1, set);
	if (front != ft_strlen(s1))
		back = back_count(s1, set);
	else
		back = 0;
	ptr_len = ft_strlen(s1) - (front + back);
	ptr = malloc(ptr_len + 1);
	if (!ptr)
		return (NULL);
	ptr_start = ptr;
	s1 += front;
	while (ptr_len--)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (ptr_start);
}

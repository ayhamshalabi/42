/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:59:54 by ayhshala          #+#    #+#             */
/*   Updated: 2026/09/07 18:59:54 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	is_negative;
	int	dest;

	is_negative = 1;
	dest = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_negative = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		dest = dest * 10 + (*nptr - '0');
		nptr++;
	}
	return (dest * is_negative);
}

int main(void)
{
    char *ptr = "2345";
    printf("%d\n", ft_atoi(ptr));
    return (0);
}
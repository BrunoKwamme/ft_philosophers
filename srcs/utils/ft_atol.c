/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:03:54 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/09 22:07:31 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long	ft_atol(const char *nptr)
{
	long	atol;
	int	i;
	int	m;

	i = 0;
	m = 0;
	atol = 0;
	while (nptr[i] == 32 || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			m++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		atol = atol * 10 + nptr[i] - 48;
		i++;
	}
	if (m == 1)
		return (-atol);
	return (atol);
}

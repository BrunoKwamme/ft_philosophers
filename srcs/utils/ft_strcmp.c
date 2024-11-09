/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:43:23 by bkwamme           #+#    #+#             */
/*   Updated: 2024/11/09 20:08:12 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_strcmp(const char *str, const char *cmp)
{
	int	i;

	i = 0;
	while ((str[i] != '\0' && cmp[i] != '\0') && str[i] == cmp[i])
		i++;
	return (str[i] - cmp[i]);
}

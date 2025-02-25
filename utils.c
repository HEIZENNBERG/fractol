/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:59:37 by onajem            #+#    #+#             */
/*   Updated: 2025/02/25 16:33:53 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void handle_error(void)
{
    write(2, "malloc failled\n", 16);
    exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		check;

	i = 0;
	check = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
		{
			check = (unsigned char)s1[i] - (unsigned char)s2[i];
			break ;
		}
		i++;
	}
	return (check);
}



static int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

static int	num_start(const char **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

double	ft_atod(const char *nptr)
{
	int			sign;
	long	sum;
	double 	pow;
	double	fas;

	sum = 0;
	pow = 1;
	fas = 0;
	sign = num_start(&nptr);
	while (is_num(*nptr))
	{
		sum = sum * 10 + (*nptr - '0');
		nptr++;
	}
	if (*nptr == '.')
		nptr++;
	while(is_num(*nptr))
	{
		pow /= 10;
		fas = fas + (*nptr - '0') * pow; 
		nptr++;
	}
	return ((sum + fas) * sign);
}

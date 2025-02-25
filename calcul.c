/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:40:11 by onajem            #+#    #+#             */
/*   Updated: 2025/02/25 17:11:22 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double map(double orgin, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (orgin - old_min) / (old_max - old_min) + new_min;
}

t_complex sum_c(t_complex z1, t_complex z2)
{
    t_complex res;
    
    res.x = z1.x + z2.x;
    res.y = z1.y + z2.y;
    return (res);
}

t_complex sqrt_c(t_complex z)
{
    t_complex res;
    
    res.x = (z.x * z.x) - (z.y * z.y);
    res.y = 2 * z.x * z.y ;
    return (res);
} 
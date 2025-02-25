/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:59:31 by onajem            #+#    #+#             */
/*   Updated: 2025/02/25 16:40:22 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void data_init(t_fractol *frac)
{
    frac->esc = 4;
    frac->iter = 42;
    frac->x = 0.0;
    frac->y = 0.0;
    frac->zoom = 1.0;
}

void event_init(t_fractol *frac)
{
	mlx_hook(frac->win, 2, 1L << 0, key_handler, frac);
    mlx_hook(frac->win, 4, 1L << 2, mouse_handler, frac);
    mlx_hook(frac->win, 17, 0, close_handler, frac); 
    // mlx_hook(frac->win, 6, 1L << 6, julia_track, frac);
}


void	put_pxl(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void shape(t_complex *z, t_complex *c, t_fractol *frac)
{
    if (!ft_strncmp(frac->name, "julia", 5))
    {
        c->x = frac->julia_x;
        c->y = frac->julia_y;
    }
    else
    {
        c->x = z->x;
        c->y = z->y;        
    }
}

void process_pixel(int x, int y, t_fractol *frac)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    z.x = (map(x, -2, 2, 0, WIDTH) * frac->zoom) + frac->x;
    z.y = (map(y, 2, -2, 0, WIDTH) * frac->zoom) + frac->y;

    shape(&z, &c, frac);

    i = 0;
    while (i < frac->iter)
    {
        z = sum_c(sqrt_c(z), c);
        if ((z.x * z.x) + (z.y * z.y) > frac->esc)
        {
            color = map(i, BLACK, WHITE, 0, frac->iter);
            put_pxl(&frac->img, x, y, color);
            return ;
        }
        i++;
    }
    put_pxl(&frac->img, x, y, WHITE);
}


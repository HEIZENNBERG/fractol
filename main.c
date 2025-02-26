/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:33:13 by onajem            #+#    #+#             */
/*   Updated: 2025/02/26 19:37:37 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void init(t_fractol *fract)
{
    fract->conn = mlx_init();
    if (!fract->conn)
        handle_error();
    fract->win = mlx_new_window(fract->conn, WIDTH, HEIGTH, fract->name);
    if (!fract->win)
    {
        mlx_destroy_window(fract->conn, fract->win);
        free(fract->conn);
        handle_error();
    }
    fract->img.img = mlx_new_image(fract->conn, WIDTH, HEIGTH);
    if (!fract->img.img)
    {
        mlx_destroy_window(fract->conn, fract->win);
        free(fract->conn);
        handle_error();
    }
    fract->img.addr = mlx_get_data_addr(fract->img.img, &fract->img.bits_per_pixel, &fract->img.line_len, &fract->img.endian);

    event_init(fract);
    data_init(fract);
}


void render(t_fractol *frac)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGTH)
    {
        x = 0;
        while (x < WIDTH)
        {
            process_pixel(x, y, frac);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(frac->conn, frac->win, frac->img.img, 0, 0);
}


int main(int ac, char *av[])
{
    t_fractol fract;
    
    if (ac == 2 && !ft_strncmp(av[1], "mandlebrot", 11) || (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
    {
        fract.name = av[1];
        if ((ac == 4 && !ft_strncmp(av[1], "julia", 5)))
        {
            fract.julia_x = ft_atod(av[2]);
            fract.julia_y = ft_atod(av[3]);
        }

        init(&fract);
        
        render(&fract);

        mlx_loop(fract.conn);

    } 
    else 
    {
        write(2, "incompatible parameteres!", 26);
        return (1);
    }
}
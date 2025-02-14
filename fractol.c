/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:59:31 by onajem            #+#    #+#             */
/*   Updated: 2025/02/14 18:13:32 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// vedio 1h . 09

#include "fractol.h"
void handle_error(void)
{
    write(2, "malloc failled\n", 16);
    exit(1);
}


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
    fract->img.addr = mlx_new_image(fract->conn, WIDTH, HEIGTH);
    if (!fract->img.addr)
    {
        mlx_destroy_window(fract->conn, fract->win);
        free(fract->conn);
        handle_error();
    }
    fract->img.addr = mlx_get_data_addr(fract->img.addr, &fract->img.bits_per_pixel, &fract->img.line_len, &fract->img.endian);

    // event_init()
    // data_init()
}

double map(double orgin, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (orgin - old_min) / (old_max - old_min) + new_min;
}

void process_pixel(int x, int y, t_fractol *frac)
{
    t_complex z;
    t_complex c;

    z.x = 0.0;
    z.y = 0.0;
    c.x = map(x, -2, 2, 0, WIDTH);
    c.y = map(x, 2, -2, 0, WIDTH);

    while ()
    {
        // z = sum_c(sqrt_c(z), c)
        if ()
        {
            put_pxl();
            return ;
        }
    }
    
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
}


int main(int ac, char *av[])
{
    t_fractol fract;
    
    if (ac == 2 && ft_strncmp(av[1], "mandlebrot", 10) || ac == 4 && ft_strncmp(av[1], "julia", 5))
    {
        fract.name = av[1];
        init(&fract);
        
        render(&fract);

        mlx_loop(fract.conn);
        printf("successs\n");
    } 
    else 
    {
        write(2, "incompatible parameteres!", 26);
        return (1);
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:59:31 by onajem            #+#    #+#             */
/*   Updated: 2025/02/24 16:21:01 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// vedio 1h . 30

#include "fractol.h"
void handle_error(void)
{
    write(2, "malloc failled\n", 16);
    exit(1);
}

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
    mlx_hook(frac->win, 4, 1L << 2, mouse_handler, frac); // ButtonPress
    mlx_hook(frac->win, 17, 0, close_handler, frac); 
    // mlx_hook(frac->win, 6, 1L << 6, julia_track, frac);
	// mlx_hook(frac->win, ButtonPress, ButtonPressMask, mouse_handler, frac);
	// mlx_hook(frac->win, DestroyNotify, StructureNotifyMask, close_handler, frac);
	// mlx_hook(frac->win, MotionNotify, PointerMotionMask, julia_track, frac);
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
    
    if (ac == 2 && !ft_strncmp(av[1], "mandlebrot", 11) || ( ac == 4 && !ft_strncmp(av[1], "julia", 5)))
    {
        fract.name = av[1];
        fract.julia_x = 1; //fix double
        fract.julia_y = 1; //fix double
        printf("%f |  %f\n",  fract.julia_x,  fract.julia_y);
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
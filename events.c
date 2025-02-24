/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:28:55 by onajem            #+#    #+#             */
/*   Updated: 2025/02/24 15:48:42 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_handler(t_fractol *frac)
{
    mlx_destroy_image(frac->conn, frac->img.addr);
    mlx_destroy_window(frac->conn, frac->win);
    free(frac->conn);
    exit(0); 
}

int key_handler(int key, t_fractol *frac)
{
    printf("%d\n", key);
    if (key == KEY_ESC)
        close_handler(frac);
    if (key == KEY_LEFT)
        frac->x += (0.5 * frac->zoom);    
    else if (key == KEY_RIGHT)
        frac->x -= (0.5 * frac->zoom);    
    else if (key == KEY_UP)
        frac->y -= (0.5 * frac->zoom);    
    else if (key == KEY_DOWN)
        frac->y += (0.5 * frac->zoom);    
    else if (key == KEY_PLUS)
        frac->iter += 10;
    else if (key == KEY_MINUS)    
        frac->iter -= 10; 
    render(frac); 
    return 0;
}

int mouse_handler(int key, int x, int y, t_fractol *frac)
{
    printf("%d\n", key);
    if (key == SCROLL_UP)
    {
        frac->zoom *= 0.95;
    }
    else if (key == SCROLL_DOWN)
    {
        frac->zoom *= 1.05;
    }
    render(frac); 
    return 0;
}
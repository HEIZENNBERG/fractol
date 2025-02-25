/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:59:35 by onajem            #+#    #+#             */
/*   Updated: 2025/02/25 16:33:56 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <mlx.h>

#include <math.h>
#define WIDTH 800
#define HEIGTH 800

#define KEY_ESC     53
#define KEY_LEFT    123
#define KEY_RIGHT   124
#define KEY_DOWN    125
#define KEY_UP      126
#define KEY_PLUS    69   // '+' on numpad
#define KEY_MINUS   78   // '-' on numpad

#define MOUSE_LEFT      1
#define MOUSE_RIGHT     2
#define MOUSE_MIDDLE    3
#define SCROLL_UP       4
#define SCROLL_DOWN     5



#define BLACK   0x000000  // RGB(0, 0, 0)
#define WHITE   0xFFFFFF  // RGB(255, 255, 255)
#define RED     0xFF0000  // RGB(255, 0, 0)
#define GREEN   0x00FF00  // RGB(0, 255, 0)
#define BLUE    0x0000FF  // RGB(0, 0, 255)
#define YELLOW  0xFFFF00  // RGB(255, 255, 0)
#define CYAN    0x00FFFF  // RGB(0, 255, 255)
#define MAGENTA 0xFF00FF  // RGB(255, 0, 255)
#define GRAY    0x808080  // RGB(128, 128, 128)
#define ORANGE  0xFFA500  // RGB(255, 165, 0)
#define PURPLE  0x800080  // RGB(128, 0, 128)
#define PINK    0xFFC0CB  // RGB(255, 192, 203)


typedef struct s_complex
{
    double x; // real
    double y; // img
}t_complex;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_fractol
{
    char *name;
    void *conn;
    void *win;
    double esc;
    int iter;
    double x;
    double y;
    double zoom;
    t_img img;
    double julia_x;
    double julia_y;
    
}t_fractol;


long	ft_atol(const char *nptr);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void render(t_fractol *frac);
int	key_handler(int key, t_fractol *frac);
int mouse_handler(int key, int x, int y, t_fractol *frac);
int close_handler(t_fractol *frac);


#endif
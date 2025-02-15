/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:59:35 by onajem            #+#    #+#             */
/*   Updated: 2025/02/15 13:51:14 by onajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#define WIDTH 800
#define HEIGTH 800

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
    t_img img;
    
}t_fractol;

int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
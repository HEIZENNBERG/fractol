/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onajem <onajem@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:59:35 by onajem            #+#    #+#             */
/*   Updated: 2025/02/14 17:59:32 by onajem           ###   ########.fr       */
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
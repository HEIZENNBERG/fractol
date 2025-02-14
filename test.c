#include <stdio.h>
#include <mlx.h>

// cc -Imlx test.c -lmlx -framework OpenGL -framework AppKit
int main()
{
    void *mlx;
    void *win;
    void *img;

    mlx = mlx_init();
    win =  mlx_new_window(mlx, 500, 500, "Hello world!");
    mlx_pixel_put(mlx, win , 250, 250, 0xffffff);
    mlx_loop(mlx);
     return 0;
}
#include <mlx.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int 			main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	/* square 
	i = -1;
	while (++i < 100)
	{
		j = -1;
		while (++j < 100)
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
	}
	*/
	/* triangle */
	i = 0;
	j = 100;
	while (i < 100 && j > 0)
	{
		int k = i + 2 * j;
		while (k > i)
		{
			my_mlx_pixel_put(&img, k, j, 0x00FF0000);
			k--;
		}
		i++;
		j--;
	}
	/**/
	mlx_put_image_to_window(mlx, mlx_win, img.img, 300, 300);
	mlx_loop(mlx);
}


#include "../includes/so_long.h"

void	draw_texture(t_struct *s, t_texture texture, int img, t_point_int new_size)
{
	int		tx;
	int		ty;
	float	ratio_y;
	float	ratio_x;

	tx = 0;
	ratio_x = texture.height / (float)new_size.x;
	ratio_y = texture.width / (float)new_size.y;
//	printf(" texture height = %d\n",texture.height);
//	printf("size block y %d\n",new_size.y);
//	printf("texture width %d\n",texture.width);
//	printf(" size block x %d\n",new_size.x);

	while (tx < new_size.x)
	{
		ty = 0;
		while (ty < new_size.y)
		{
			s->data[img].addr[ty * (s->data[img].line_length / 4)  + tx] = texture.addr[(int)((int)(tx * ratio_x) + (int)(ty * ratio_y ) * texture.line_length / 4 )];
			ty++;
		}
		tx++;
	}
}


void	rezize_img(t_struct *s)
{
	s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/0.xpm", &s->textu.width, &s->textu.height);
	s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.a, &s->textu.line_length, &s->textu.endian);
	draw_texture(s, s->textu, 0, s->size_of_block);
	s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/1.xpm", &s->textu.width, &s->textu.height);
	s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.a, &s->textu.line_length, &s->textu.endian);
	draw_texture(s, s->textu, 1, s->size_of_block);
	s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/C.xpm", &s->textu.width, &s->textu.height);
	s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.a, &s->textu.line_length, &s->textu.endian);
	draw_texture(s, s->textu, img_C, s->size_of_block);
	s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/E.xpm", &s->textu.width, &s->textu.height);
	s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.a, &s->textu.line_length, &s->textu.endian);
	draw_texture(s, s->textu, img_E, s->size_of_block);
	s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/P.xpm", &s->textu.width, &s->textu.height);
	s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.a, &s->textu.line_length, &s->textu.endian);
	draw_texture(s, s->textu, img_P, s->size_of_block);
	s->textu.ptr = mlx_xpm_file_to_image(s->window, "./text/final2.xpm", &s->textu.width, &s->textu.height);
	s->textu.addr = (int *)mlx_get_data_addr(s->textu.ptr, &s->textu.a, &s->textu.line_length, &s->textu.endian);
	draw_texture(s, s->textu, img_FIN, (t_point_int) {s->R1, s->R2} );
}

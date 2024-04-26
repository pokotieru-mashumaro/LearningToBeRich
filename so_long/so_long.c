#include <stdio.h>

int check_ber(char *s1, char *s2)
{
    int count;
    int i;
    int j;

    count = 0;
    while (s1[count])
        count++;
    if (count <= 4)
        return 0;
    i = count - 4;
    j = 0;
    while (j < 4)
    {
        if (s1[i] != s2[j])
            return 0;
        i++;
        j++;
    }
    return 1;
}

#include "minilibx_opengl_20191021/mlx.h"

 int main()
 {
     void *mlx;//スクリーン接続識別子
     void *mlx_win;//ウィンドウ識別子
     int i;
     int j;
     int width = 1000; //ウィンドウのサイズ
     int height = 1000;
 
     mlx = mlx_init();//mlxの機能を使う前に一度呼び出す必要がある
     mlx_win = mlx_new_window(mlx, width, height,"test");
		// mlx_win = mlx_new_window(スクリーン識別子, width, height,"test");
		//座標は左上が原点、矢印はx軸が右、y軸が下向きになる
		//でも与えられる図形の座標は一般的な向きの座標のためあとで座標変換が必要となる
    	i= 0;
		while (i < width)
		{
				j = 0;
				while (j < height)
				{
						mlx_pixel_put(mlx, mlx_win, i, j, 127);
						j++;
				}
				i++;
		}
     mlx_loop(mlx);//無限ループを作り、その間ウィンドウを表示させ続ける
     //最初のうちはcntl+Cで強制終了すればおk
     //クリックした時に終了させるなどのプログラムはゆくゆく書く必要がある
     return (1);
 }

// int main(int ac, char **av)
// {
//     if (!check_ber(av[1], ".ber"))
//         return 0;
//     printf("-------\n");
//     return 0;
// }
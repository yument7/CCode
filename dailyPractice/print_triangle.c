/**
 * 描述： 打印杨辉三角
 * 
 * 思路：
 *      由于杨辉三角中当 row > 2 之后， a[row][col] = a[row-1][col-1] + a[row-1][col]
 *      所以采用二维数组记录前面的数，然后计算当前的，进行打印
 * 
 **/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, j, a[10][10];

    for (int i = 0; i < 10; i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
    }

    printf("%d\n", a[0][0]);
    printf("%d\t%d\n", a[1][0], a[1][1]);

    for (i = 2; i < 9; i++)
    {   
        printf("%d\t", a[i][0]);
        for (j = 1; j < i; j++)
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            printf("%d\t", a[i][j]);
        }
        printf("%d\n", a[i][i]);
    }

    return 0;
}

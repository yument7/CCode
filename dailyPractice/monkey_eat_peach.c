/**
 * 描述： 猴子第一天摘下若干桃子，当即吃了一半，还不过瘾，又多吃了一个。第二天早上又将第一天剩下的桃子
 * 吃掉一半，又多吃一个。以后每天早上都吃了前一天剩下的一半多一个。到第十天早上，发现只剩下一个桃子了。
 * 求猴子第一天共摘了多少个桃子。
 * 
 * 思路：递归 , 循环
 *      计算公式： An = A(n-1)/2 - 1
 *      条件： n = 10, total = 1
 *      计算： n = 1, total = ?;
 **/

#include <stdio.h>

int computeByRecursion(int n)
{
    int total;
    if (n == 10)
    {
        return 1;
    }

    total = computeByRecursion(n + 1) * 2 + 2;
    return total;
}

int computeByCycle(int n)
{
    if (n > 10 || n < 1)
    {
        printf("out of the bounds");
        return;
    }

    int total, i;
    i = 10;

    while (0 < i && i <= 10)
    {
        if (i == 10)
        {
            total = 1;
        }
        else
        {
            total = 2 * total + 2;
        }

        if (i == n)
        {
            break;
        }

        i--;
    }

    return total;
}

int main(int argc, char const *argv[])
{
    int total1, total2;
    total1 = computeByRecursion(1);
    total2 = computeByCycle(1);
    printf("total1 = %d, total2 = %d\n", total1, total2);
    return 0;
}

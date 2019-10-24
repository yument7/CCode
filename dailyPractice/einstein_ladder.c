/**
 *   爱因斯坦阶梯问题
 *   问题描述：有条长长的阶梯。如果你每步跨2阶，那么最后剩1阶； 如果你每步跨3阶，那么最后剩2阶； 如果你每步跨4阶， 那么最后剩3阶；
 *            如果你每步跨5阶，那么最后剩4阶， 如果你每步跨6阶，那么最后剩5阶，如果每步跨7阶，那么刚好最后一阶不剩。求所有三位阶梯数。
 *  
 *   思路：
 *       既然是求所有的三位阶数。那么是100 - 999； 可以采用穷举，由于 2阶会剩一阶，可以排除所有的偶数。
 *       即 101 103 ... 999. 设 S 为可能的数，需要满足的条件
 *       S%3 == 2 && S%4==3 && S%5==4 && S%6==5 && S%7 == 0
 *       
 **/
#include <stdio.h>

void getEinsteinLadderNumber()
{
    int i;
    for (i = 101; i < 1000; i += 2)
    {
        if (i % 3 == 2 && i % 4 == 3 && i % 5 == 4 && i % 6 == 5 && i % 7 == 0)
        {
            printf("the number of the stairs is :%d\n", i);
        }
    }
}

int main(int argc, char const *argv[])
{
    getEinsteinLadderNumber();
    return 0;
}

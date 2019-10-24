/**
 * 问题描述，打印乘法口诀表
 **/

#include <stdio.h>

void printMultiplicationTable(){
    int i, j, sum;
    for(i = 1; i < 10; i++){
        for(j = 1; j <= i; j++){
            sum = i * j;
            printf("%d*%d=%d\t", i, j, sum);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    printMultiplicationTable();
    return 0;
}



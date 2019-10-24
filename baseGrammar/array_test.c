#include <stdio.h>
#include <string.h>

/**
 * 数组的定义，初始化，赋值，访问 
*/

void initArray()
{
    // 一维数组的定义初始化
    int aArray[6] = {1, 2, 3, 4, 6, 7};
    int bArray[] = {1, 2, 3};
    int cArray[5] = {1, 2};

    // 二维数组定义初始化
    int dArray[2][2] = {1, 2, 3, 4};     // 直接赋值，系统自动分行，数据少于数组元素用0填充
    int eArray[2][2] = {{1, 3}, {2, 4}}; // 分行赋值
    int fArray[2][3] = {{1, 4}, {2, 5}}; // 分行赋值可以只赋一部分

    // 字符数组定义
    char gArray[10] = {'h', 'e', 'l', 'l', 'o'};
    char hArray[] = "hello,world"; // 最后一个数字符为 \0,表示结束符

    // void jArray[20]; 不能定义一个为void类型的数组
}

/*
 * -> 选择排序
 * 输入五个国家的名字，并按顺序排序输入打印
 */
void orderName(void)
{
    char name[20], names[5][20];

    printf("please input five country name:\n");
    int i, j, k;
    for (i = 0; i < 5; i++)
    {
        scanf("%s", name);
        strcpy(names[i], name);
    }
    printf("========== input completed ==========\n");

    for (i = 0; i < 5; i++)
    {
        k = i;
        strcpy(name, names[i]);
        for (j = i + 1; j < 5; j++)
        {
            if (strcmp(name, names[j]) > 0)
            {
                strcpy(name, names[j]);
                k = j;
            }
        }
        if (k != i)
        {
            strcpy(name, names[i]);
            strcpy(names[i], names[k]);
            strcpy(names[k], name);
        }
        printf("%d = %s\n", i, names[i]);
    }
    printf("========== order completed! ==========\n");
}

/**
 * -> 冒泡排序
 * 给出10个人学生的数学成绩，按从高到低进行排序 
 */
void orderScore(void)
{
    int scores[] = {61, 68, 79, 92, 84, 82, 73, 99, 66, 95};
    int i, j, temp;
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (scores[i] < scores[j])
            {
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }

    for(i =0; i < 10; i++){
        printf("%d  ", scores[i]);
    }
}

int main(int argc, char const *argv[])
{
    //orderName();
    orderScore();
    return 0;
}

/**
 * 问题描述：从键盘输入年、月、日，计算该日期是该年的第几天。
 * 
 * 思路：
 *      主要考虑公历闰年问题, 闰年一年有366天, 即2月为29天, 闰年分两种: 
 *   1. 普通闰年： year % 4 == 0 && year % 100 != 0
 *   2. 世纪闰年： year % 400 == 0
 * 
 * 解决方法：
 *   1. 判断当前输入年份是否为闰年；
 *   2. 累加计算；
 * 
 **/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int year, mouth, day;
    scanf("%d %d %d", &year, &mouth, &day);

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int count = 0;

    // 检测年与月
    if (year <= 0 || mouth <= 0 || mouth > 12)
    {
        printf("请输入正确的年月");
        return;
    }

    // 判断闰年
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        days[1] = 29;
    }

    // 检测日
    if (days[mouth] < day)
    {
        printf("请输入正确的日期");
        return;
    }

    int i;
    for (i = 0; i < mouth-1; i++)
    {
        count += days[i];
    }
    count += day;

    printf("第 %d 天", count);

    return 0;
}

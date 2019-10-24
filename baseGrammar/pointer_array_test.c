#include <stdio.h>

/**
 * 指针与数组：
 * 指针数组： 
 * 数组指针：
 * */

/**
 * 1.通过指针访问数组
 * 2.数组名即为一个指向数组头元素的指针
 * 3.指针与二维数组的操作
 * */
void pointerAndArray(void)
{
    int a[] = {1, 3, 5, 6, 8, 9}, *p;
    p = a;
    int i;
    // 方式一
    printf("type one:\n");
    for (i = 0; i < 6; i++)
    {
        printf("val=%d,", a[i]);
    }

    // 方式二
    printf("\ntype two:\n");
    for (i = 0; i < 6; i++)
    {
        printf("val=%d,", *p++);
    }

    // 方式三
    printf("\ntype three:\n");
    for (i = 0; i < 6; i++)
    {
        printf("val=%d,", *(a + i)); // 注意： *a + i <=> a[0]+i; *(a+i) <=> a[i];  a++： 是不允许的， a 在这里只是一个常量指针即不可变的 <=> *const p。
    }
}

/**
 * 二维数组与指针
 * */
void pointerQRAarry()
{
    int a[2][2] = {1, 2, 3, 4}, *p, i, j;
    // p = a; // 这样指向是不对的， a代表a[0] ,类型是一个数组， 而p 只是整型
    p = a[0];
    printf("result is :\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d ", *p++);
        }
    }
}

// 指针与字符串
void pointerString()
{
    char str1[] = "you are so beautiful", str2[30], *p1, *p2;
    p1 = str1;
    p2 = str2;
    while(*p1 != '\0'){
        *p2 = *p1;
        p1++;
        p2++;
    }
    *p2 = '\0';
    printf("Now the str2 is: \n");
    puts(str2);
}

// 指针与字符数组
void pointerCharArray()
{
    char country[5][20] = {"java", "python", "nodejs", "scala", "html5"}, (*p)[20], i;
    p = country;
    for(i=0; i <5; i++){
        printf("%s ", *p++);
    }
}

// 指针数组： 数组元素的类型为指针
void pointerArray()
{
    int *pa[5], a[] = {12, 6, 8, 9, 7}, i;
    for (i = 0; i < 5; i++)
    {
        pa[i] = &a[i];
    }
    printf("pointer array visit result:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d,", *pa[i]);
    }

    for (i = 0; i < 5; i++)
    {
        *pa[i] += 2; // 通过指针类型元素修改数组元素的值
    }

    printf("\npointer array update result:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d,", a[i]);
    }
}

// 数组指针： 指向数组的指针
void arrayPointer()
{
    char a[3] = {'A', 'B', 'C'}, (*pc1)[3], (*pc2)[3];
    pc1 = &a;
    //pc2 = a;  // 这种做法不可取， 因为左右两边的数据类型不一致
    printf("array pointer visit result:\n");

    int i, j;
    for (i = 0; i < 3; i++)
    {
        printf("%c,", *((*pc1) + i)); // 在这里 pc1 指向了整个数组的地址， 通过*pc1 取到数组首元素的地址， **pc1 就能拿到值
    }

    printf("\narray pointer visit qr array:\n");
    int b[3][2] = {1, 3, 5, 7, 9, 11}, (*p1)[2];
    p1 = b; // 在这里， a代表 a[0],即二维数组的首行元素的首地址
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d-%d,", *(*(p1 + i) + j), p1[i][j]);
        }
    }
}

int main(int argc, char const *argv[])
{
    //pointerAndArray();
    //pointerArray();
    //arrayPointer();
    //pointerQRAarry();
    //pointerString();
    pointerCharArray();
    return 0;
}

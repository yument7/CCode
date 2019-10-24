#include <stdio.h>
#include <string.h>

/**
 * 字符串处理需要使用库函数string.h
 * */

void useString(void)
{
    // 连接两个字符串 strcat(char * dest, const char *source) 可以用一个指针接收
    char str1[] = "hello", str2[] = "world", *str_p;
    str_p = strcat(str1, str2);
    printf("strcat result is:\n");
    puts(str1);
    puts(str_p);

    // 复制字符串 strcpy(char * dest, const char *source) 可以用一个指针接收
    char str3[30], str4[] = "so beautiful", *str_p2;
    str_p2 = strcpy(str3, str4);
    printf("strcpy result is:\n");
    puts(str3);
    puts(str_p2);

    // 比较两个字符串 strcmp(const char * str1, const char * str2) 若str1=str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数
    char str5[] = "china", str6[] = "russia";
    int result;
    result = strcmp(str5, str6);
    printf("compare result = %d\n", result);

    // 小写转换成大写 strupr(char * str) 可以用指针接收
    char *str_p3;
    str_p3 = strupr(str5);
    printf("strupr result is:\n");
    puts(str5);
    puts(str_p3);

    // 统计字符串长度 strlen(char * str) 返回size_t , size_t 是一个宏定义 unsigned int， 即typedef unsigned int size_t;
    char str7[] = "l love you.";
    int len;
    len = strlen(str7);
    printf("strlen result=%d\n", len);
}

int main(int argc, char const *argv[])
{
    useString();
    return 0;
}

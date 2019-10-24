#include <stdio.h>

/**
 * 预处理
 *  宏定义
 *      define
 *  #include 指令
 *  条件编译
 *      #if #ifdef #ifndef #undef #line #pragma
 */

// 无参宏定义
#define PI 3.1415926
#define R 5
#define AREA PI*R*R
#define FIXED "hello, world"
#define STD "undef"


// 有参宏定义
#define MIX(a, b) (a<b?a:b)
#define SUM(x, y) ((x)*(y)) // 注意一定有参宏定义，一定需要使用括号包住变量，否则很容易产生错误

void testDefine(){
    printf("R=%d, area=%d\n", R, AREA);
    printf("%s , oh no!\n", FIXED);
    
    int a, b, mix, sum;
    a= 5;
    b= 6;
    mix = MIX(a,b);
    sum = SUM(a,b);

    printf("mix = %d, sum = %d\n", mix, sum);
}

void testConditionDef(){

    #ifdef FIXED
        printf(FIXED);
    #else
        printf(" i don't know.\n");
    #endif

    #ifndef DEF_TEST_H
        printf(" don't give up\n");
    #else
        printf("ok\n")
    #endif

    printf("%s not used.\n", STD);
    #undef STD
    printf("has been undefined.");
}

int main(int argc, char const *argv[])
{
    testDefine();
    testConditionDef();
    return 0;
}

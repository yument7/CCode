#include <stdio.h>

/**
 * 指针与地址
 * 指针变量
 * 指针运算
 * 数组与指针
 * 指向指针的指针
 * 指针变量做函数参数 
 * 返回指针值的函数 
 * */

/*
 *   指针就是地址
 *   指针变量使用 *来定义;
 *   通过指针可以访问指针变量指向地址的值； 
 *   & : 取一个变量的地址， * ：取一个指针变量指向地址的值 （通过地址访问值，间接访问）
 *   *& : 取一个地址的值， &* : 取一个指针变量指向地址的值的地址
*/
void pointer_addr(void)
{

    int a = 5, *p1, *p2;
    p1 = &a;
    // *p2 = 8; 编译不会出错，但运行时会出错

    printf("=====================\n");
    printf("p=%d,&a=%d\n", p1, &a);
    printf("&*p=%d,*&a=%d\n", &*p1, *&a);

    *p1 = 7;
    printf("a=%d\n", a);

}

/**
 * 指针的操作： ++p, p++, --p, p--, p+n, p-n
 * 这些操作都是让指针指向一个操作后的地址，而不是值操作
 * */
void pointer_muti(){
    int a = 7, b, *p, *p2;
    p = &a;
    p++;            // p++ 会执向a地址后的下个地址，下一个地址并没有进行初始化，对于未初始化的地址的值是系统随机赋予的。
    p2 = &b;

    printf("=====================\n");
    printf("a-addr=%d, val=%d, addr=%d\n", &a, *p, p); 
    printf("b-val=%d, b-addr=%d, val=%d, addr=%d\n", b, &b, *p2, p2);

    /* int b;
    static int c;
    const int d;
    const static int e;
    printf("b=%d,c=%d,d=%d,e=%d\n", b, c, d, e);
    printf("b-addr=%d,c-addr=%d,d-addr=%d,e-addr=%d\n", &b, &c, &d, &e); */
}

void pointer_param(){

}

void pointer_pointer(){

}


int main(int argc, char const *argv[])
{
    //pointer_addr();
    pointer_muti();
    return 0;
}

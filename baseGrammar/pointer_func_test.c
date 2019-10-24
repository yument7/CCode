#include <stdio.h>

/**
 *  1.指针变量做函数参数
 *  2.指针函数
 *  3.函数指针
 **/ 

// 指针变量做函数参数
void swap(int *a, int *b){
    int temp;
    if(*a > *b){
        temp = *a;
        *a = *b;
        *b = temp;
    }
    printf("%d,%d\n", *a, *b);
}

// 指针函数: 即函数的返回值类型为指针类型
char *reverse(char *source){
    char *target, *result;
    if(source == NULL){
        return NULL;
    }

    target = source;
    result = source;
    int len, i;
    char temp;

    while(*source != '\0'){
        len++;
        source++;
    }
    source--;

    for(i = 0; i < len/2; i++){
        temp = *target;
        *target = *source;
        *source = temp;
        target++;
        source--; 
    }
    return result;
}

// 函数指针： 一个指向函数类型的指针
void funcPointer(){

    void (*pf)(int *, int *);
    pf = swap;
    int a =5, b =2;
    (*pf)(&a, &b);
    printf("swap result is:a=%d,b=%d\n", a, b);
    return;
}



int main(int argc, char const *argv[])
{
    /* char name[] = "Micale Jordan", *result;
    result = reverse(name);
    printf("the reverse result is:\n");
    puts(result); */

    funcPointer();
    return 0;
}

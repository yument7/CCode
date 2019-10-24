#include <stdio.h>

/**
 * 结构体
 * 1. 定义与基本使用
 * 2. 结构体数组
 * 3. 结构体指针
 * 4. 结构体做函数参数
 * */

// 声明
struct Bean
{
    char *name;
    double price;
};

// 声明并定义
struct Car
{
    char *type;
    double price;
    char *place;
} audo_car, ben_car, byd_car[5];

// 声明定义并初始化
struct Device
{
    int code;
    char *item;
} resistor = {100010, "Resistor"};

// typedef的使用
typedef struct Date
{
    int year;
    int mouth;
    int day;
} Date;

// 结构体中使用结构体
typedef struct Student
{
    int code;
    char *name;
    Date birthday;
} Stu;

void testStruct(void)
{
    struct Bean bean = {"sijidou", 2.5};
    printf("bean: %s, %lf\n", bean.name, bean.price);

    // audo_car = {"奥迪", 23.5, "Germany"}; // 不能这样初始化
    audo_car.type = "audi";
    audo_car.place = "Germany";
    audo_car.price = 45.6;
    printf("audo_car: %s, %s, %lf\n", audo_car.type, audo_car.place, audo_car.price);

    printf("Device: %s, %d\n", resistor.item, resistor.code);

    // 定义结构体数组， 指向结构体数组的指针， 指向结构的指针
    Stu es_stu[3] = {{111, "tom", {1992, 8, 10}}, {112, "jack", {1990, 9, 21}}, {113, "lisa", {1995, 10, 12}}}, stu, *stu_p, *stu_p2;

    stu_p = &stu; // 无论什么数据类型， 指针都要指向一个定义的变量，即指针的初始化始终要指向一个变量，没有这行代码，下面的四行代码是会报错的；
    stu_p->name = "edison";
    stu_p->code = 115;
    Date date = {1994, 07, 07};
    stu_p->birthday = date;

    stu_p2 = es_stu;
    int i;
    for(i=0; i< 3; i++){
        printf("es_stu: %s, %d, %d-%d-%d\n", es_stu[i].name, es_stu[i].code, es_stu[i].birthday.year, es_stu[i].birthday.mouth, es_stu[i].birthday.day);
        printf("stu_p2: %s, %d, %d-%d-%d\n", (*stu_p2).name, (*stu_p2).code, (*stu_p2).birthday.year, (*stu_p2).birthday.mouth, (*stu_p2).birthday.day);
        stu_p2++;
    }
    printf("stu_p1: %s, %d, %d-%d-%d\n", stu_p->name, stu_p->code, stu_p->birthday.year, stu_p->birthday.mouth,stu_p->birthday.day);
}

int main(int argc, char const *argv[])
{
    testStruct();
    return 0;
}

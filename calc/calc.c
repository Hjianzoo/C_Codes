#include <stdio.h>
#include "calc.h"

int add(int a,int b)
{
    return a+b;
}

int sub(int a,int b)
{
    return a-b;
}

int multiply(int a,int b)
{
    return a*b;
}

int divide(int a,int b)
{
    return a/b;
}

int main(void)
{
    int ret = 0;
    calc_t mycal;
    mycal.a = 12;
    mycal.b = 10;
    mycal.p = add;
    ret = calculator(&mycal);
    printf("calc result = %d",ret);
}
#ifndef __CALC_H__
#define __CALC_H__

typedef int (*pFunc)(int,int);

typedef struct calc{
    int a;
    int b;
    pFunc p;
}calc_t;

int calculator(const calc_t *p);



#endif
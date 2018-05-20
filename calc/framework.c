#include "calc.h"

int calculator(const struct calc *p)
{
    return p->p(p->a,p->b);
  // return 1;
}
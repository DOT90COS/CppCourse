#include "Date.h"

int main()
{
    Date date1(02, 25, 1984);
    Date date2(-2, 40, 20000); //Should throw but doesn't. We aren't maintaining our invariance.

    return 0;
}
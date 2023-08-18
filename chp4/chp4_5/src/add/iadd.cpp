#include "add.h"

int gV = 10;

extern "C" int iadd(int i, int j)
{
    return i + j + gV;
}
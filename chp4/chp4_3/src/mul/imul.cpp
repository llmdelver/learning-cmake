#include "mul.h"

extern "C" int imul(int i, int j)
{
    return i * j;
}

extern "C" double dmul(double i, double j)
{
    return i + j;
}
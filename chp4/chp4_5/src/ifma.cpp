#include "add.h"
#include "fma.h"
#include "mul.h"

extern "C" int ifma(int i, int j, int k)
{
    return iadd(imul(i, j), k);
}
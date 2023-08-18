#include "add.h"
#include "fma.h"
#include "mul.h"
#include <iostream>

int main()
{
    const int i = 2;
    const int j = 3;
    const int k = 4;

    int add_res = iadd(i, j);
    int mul_res = imul(j, k);
    int fma_res = ifma(i, j, k);

    std::cout << "add result = " << add_res << std::endl;
    std::cout << "mul result = " << mul_res << std::endl;
    std::cout << "fma result = " << fma_res << std::endl;

    float f1 = 10.0f;
    float f2 = 20.0f;
    float fr = fadd(f1, f2);

    std::cout << "fadd result = " << fr << std::endl;
    return 0;
}
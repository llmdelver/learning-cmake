#include "fma.h"
#include <iostream>

int main()
{
    const int i = 2;
    const int j = 3;
    const int k = 4;

    auto res = ifma(i, j, k);

    std::cout << "result = " << res << std::endl;

    return 0;
}
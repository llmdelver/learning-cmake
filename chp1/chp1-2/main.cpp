#include <iostream>

int main()
{
    // #if defined(DEBUG)
    //     std::cout << "Debug version" << std::endl;
    // #elif defined(RELEASE)
    //     std::cout << "Release version" << std::endl;
    // #else
    //     std::cout << "Other version" << std::endl;
    // #endif

#if defined(NDEBUG)
    std::cout << "Release version" << std::endl;
#else
    std::cout << "Other version" << std::endl;
#endif
    return 0;
}

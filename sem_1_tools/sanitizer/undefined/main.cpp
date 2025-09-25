#include <iostream>

int main()
{
    // uint8_t tmp = 1;
    // tmp <<= 42;
    
    int overflow = 0x7fffffff;
    overflow += 3;

    std::cout << std::hex << overflow << '\n';

    return 0;
}

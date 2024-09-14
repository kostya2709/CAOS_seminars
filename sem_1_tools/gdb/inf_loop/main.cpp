#include <iostream>

int main()
{
    bool cond = true;
    while ( cond )
    {
        int a = 9;
        a++;        
    }

    std::cout << "Infinity loop is over?" << std::endl;

    return 0;
}

#include <iostream>

char* get_str( const char* str)
{
    const size_t LEN = 100;
    char array[LEN] = {};
    std::cout << "Address: " << &array[0] << '\n';
    array[0] = '!';
    for ( int i = 1; *str; ++i )
    {
        array[i] = *str;
        str++;
    }
    char* ret_ptr = array;
    return ret_ptr;
}

int main()
{
    char hello[] = "Hello";
    char* updated_str = get_str( hello);
    std::cout << updated_str << "\n";
    return 0;
}

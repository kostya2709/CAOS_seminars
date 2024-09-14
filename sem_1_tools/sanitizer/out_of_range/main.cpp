#include <iostream>

int main()
{
    size_t N = 10;
    int* array = new  int[N];

    std::cout << "Address: " << array << "\n";
    for (int i = 0; i < N + 1; ++i)
    {
        array[i] = 27;
    }

    delete[] array;

    return 0;
}

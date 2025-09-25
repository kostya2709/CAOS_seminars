#include <iostream>

int main()
{
    size_t N = 10;
    int* array = new  int[N];

    std::cout << "Address: " << array << "\n";

    delete[] array;
    
	int* array2 = new  int[N];
    
    array[0] = 7;

	delete[] array2;

    return 0;
}

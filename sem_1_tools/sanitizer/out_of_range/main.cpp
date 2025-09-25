#include <iostream>

int main() {

    size_t N = 11;
    int* array = new  int[N];
    int* array2 = new  int[N];

    std::cout << "Address: " << array << "\n";
    for (int i = 0; i < N + 1; ++i) {
        // array[i] = 27;
		int a = array[i];
	}

    delete[] array;

    return 0;
}

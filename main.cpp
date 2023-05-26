#include <iostream>

#include "memory.h"

using namespace std;

int main(int argc, char** argv) {
	custom::unique_ptr<int> my_ptr(new int(10));
	cout << *my_ptr << endl;

	int* my_int = my_ptr.release();
	cout << *my_int << endl;
	delete my_int;
	
	custom::unique_ptr<int[]> my_ptr2(new int[5] {1, 2, 3, 4, 5});
	cout << my_ptr2[3] << endl;

	int* my_array = my_ptr2.release();
	cout << my_array[3] << endl;
	delete[] my_array;

	return 0;
}
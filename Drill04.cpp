#include "std_lib_facilities.h"
// for task 4
void printArray10(ostream& os, int* a)
{
	for (int i = 0; i < 10; ++i)
		os << "Int " << i << ": " << a[i] << endl;
}
// for task 7
void printArray(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i)
		os << "Int " << i << ": " << a[i] << endl;
}
// for allocating array
int* allocateArray(int n)
{
	int* a = new int[n];
	int counter = 100;
	for (int i = 0; i < n; ++i)
		a[i] = counter++;

	return a;
}
//for allocating vector
vector<int*> allocateVector(int n)
{
	vector<int*> temp;
	int counter = 100;
	for (int i = 0; i < n; ++i)
		temp.push_back(new int{ counter++ });

	return temp;
}
// for task 10
void printVector(vector<int*> v)
{
	for (int i = 0; i < v.size(); ++i)
		cout << "Int " << i << ": " << *v[i] << endl;
}
// for deletion
void deleteVector(vector<int*> v)
{
	for (int i = 0; i < v.size(); ++i)
		delete v[i];
}

int main()
{
	//task 1 Allocate ten_ints array using new
	int* ten_ints = new int[10];

	//task 2 Print the values of the ten ints to cout.
	for (int i = 0; i < 10; ++i)
		cout << "Int " << i << ": " << ten_ints[i] << endl;
    // task 3 Deallocate the array
    delete[] ten_ints;
    // drill 4 - Print the values of the ten ints by using a function
	cout << " " << endl;
	printArray10(cout, ten_ints);
	

	// task 5 Allocate the array
	int* ten_ints02 = new int[10]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };
	cout << " " << endl;
	printArray10(cout, ten_ints02);
	delete[] ten_ints02;

	// task 6 Allocate array of 11 integers
	// task 7 print it value using function declare before main
	int* intArray = new int[11]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 };
	cout << " " << endl;
	printArray(cout, intArray, 11);
    // then Deallocate it like others
	delete[] intArray;

	// task 8 ; 20 integers and same cycle
	int* twenty_ints03 = allocateArray(20);
	cout << " " << endl;
	printArray(cout, twenty_ints03, 20);
	delete[] twenty_ints03;

	// task 10 using a vector instead of an array
	// use print_vector instead of print_array
	vector<int*> vten_ints = allocateVector(10);
	cout << " " << endl;
	printVector(vten_ints);
	deleteVector(vten_ints);

	vector<int*> v11_ints = allocateVector(11);
	cout << " " << endl;
	printVector(v11_ints);
	deleteVector(v11_ints);

	vector<int*> vtwenty_ints03 = allocateVector(20);
	cout << "- " << endl;
	printVector(vtwenty_ints03);
	deleteVector(vtwenty_ints03);

	keep_window_open();
	return 0;
	// --- end ---
}

#include "std_lib_facilities.h"

// task 1 define a global int array ga of ten ints
int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

// task 2 define a function f() taking an int array argument
// task 3
void f(int a[], int n)
{
	    // Define a local int array la of ten ints.
	int la[10];
	    // Copy the values from ga into la.
	for (int i = 0; i < n; ++i)
		la[i] = ga[i];

	    // Print out the elements of la.
	for (int i = 0; i < n; ++i)
		cout << la[i] << ", ";
	cout << endl;

	    // Define a pointer p to int and initialise it with an array allocated
	    // on the free store with the same number of elements as the argument array
	int* p = new int[n];
	    // Copy the values from the argument array into the free-store array.
	    // Copy contents of a to p
	memcpy(p, a, n * sizeof(int));
	    // Print out the elements of the free-store array.
	for (int i = 0; i < n; ++i)
		cout << p[i] << ", ";
	cout << endl;
	    // Deallocate the free-store array.
	delete[] p;
}

int fac(int n)
{
	return n > 1 ? n * (fac(n - 1)) : 1;
}

// task 4
int main()
{
	// Call f() with ga as its argument.
	f(ga, 10);

	// Define an array aa with ten elements, (1, 2*1, 3*2*1, 4*3*2*1, etc.)
    // we can use fac to help
	int aa[10]{ 1, fac(2), fac(3), fac(4), fac(5), fac(6), fac(7), fac(8), fac(9), fac(10)};
	// Call f() with aa as its argument.
	f(aa, 10);
	
	return 0;
	// --- end ---
}

#include "std_lib_facilities.h"

int main()
{
	// task 1 allocate an int, initialize it to 7 
    // and addr to p1
	int* p1 = new int(7);
	// task 2 print out the value of p1 and what it point to
	cout << "p1 :" << p1 << endl;
	cout << "*p1 :" << *p1<<endl;

	// task 3 allocate an array of seven ints
	int* p2 = new int[7]{1,2,4,8,16,32,64};
	// task 4 print out the value of p2 and of the array and what it point to
	cout << "p2 :" << p2 << endl;
	cout << "Array in p2 : " << endl;
	for (int i = 0;i < 7;i++)
		cout << p2[i] << " ";
	cout << endl;
	// task 5 declaring int*
	int* p3 = p2;
	// task 6 assigning p1 to p2
	p2 = p1;
	// task 7 assigning p3 to p2
	p2 = p3;
	// task 8 print the value and the value they point to
	cout << "p1 :" << p1 << endl;
	cout << "p1 points to :" << *p1 << endl;
	cout << "p2 :" << p2 << endl;
	cout << "p2 points to:" << *p2 << endl;
	// task 9 deallocate using delete
	delete p1;
	delete[] p2;
	// task 10 allocate array of ten ints ex 1,2,4,6,8 -
	p1 = new int[10]{ 1,2,4,8,16,32,64,128,256,512 };
	p2 = new int[10];
	for (int i = 0;i < 10;i++)
		p2[i] = p1[i];
	cout << "Array p2: \n";
	for (int i = 0;i < 10;i++)
		cout << p2[i] << " ";
	cout<<endl;
	// task 11 allocate an array of ten ints, and assign its address to a variable p2.
	vector<int> v1{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
    // repeat using vector instead
	vector<int> v2;
	for (int i = 0;i < 10;i++)
		v2.push_back(v1[i]);
	cout << "vector v2: \n";
	for (int  i : v2) 
		cout << i << " ";
	cout << endl;
	return 0;
	// --- end --- 
}

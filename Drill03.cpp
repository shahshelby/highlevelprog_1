#include "std_lib_facilities.h" // using this library because why not
//swap using pass by value
void swap_v(int a, int b) { 
	int temp;
	temp = a;
	a = b;
	b = temp;
	return;
}
//swap using pass by references 
void swap_r(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	return;
}
//swap using pass-by const reference
void swap_cr(const int& a, const int& b)
{
	int temp;
	int temp2;
	
	temp = a;
	temp2 = b;
	swap_r(temp,temp2);
	return;
}
int main() // follow the drill
{
	int x = 7;
	int y = 9;
	swap_v(x, y);
	cout << x << " " << y << endl;
	swap_r(x, y);
	cout << x << " " << y << endl;
	
	//const variables
	const int cx = 7;
	const int cy = 9;

	swap_cr(cx, cy);
	cout << cx << " "<< cy << endl;
	swap_v(7.7, 9.9);
	
	//double variables
	double dx = 7.7;
	double dy = 9.9;

	// swap_r wont work since its double variable
	swap_v(dx, dy);
	swap_cr(7.7, 9.9);
	
	cout << dx << " " << dy << endl;
	return 0;
}
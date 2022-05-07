#include "std_lib_facilities.h"
// task 1 define template
template <typename T>
struct S
{
private: // task 7 make val private
	T val;
public :
	// task 2 add constructor T
	S()
	{
	val = 0;
	}
	S(T val2)
	{
	val=val2;
	}
	T get(); // task 5 add function get()
    /*
    {
    return val; // task 6 remove it
    }
    */
	const T get() const;
	void operator=(const T&);
	// task 9 at set() function then remove later in task 10
	/*void set(T val3)
	{
	val = val3;
	}
	*/
};
// task 6 put get() outside of class
template<typename T>
 T S<T>::get()
{
	return val;
}
 // task 11
template<typename T>
const T S<T>::get() const
{
    return val;
}
 // task 10 replace set() in task 9
template <typename T>
void S<T>:: operator=(const T& val3)
{
    val = val3;
}
// task 12 Define function
 template<typename T>
 void read_val(T& v)
{
	cin >> v;
}
int main()
{
	// task 3 define int,char,double,string,vector variables
	S<int> int_S(5);
	S<char> char_S('A');
	S<double> doub_S(7.4);
	S<string> str_S("Sometinggg in the way");
	S<vector<int>> vec_S ({ 5, 7, 11 });
	/* task 4 read value and print em
	cout << int_S.val<<endl;
	cout << char_S.val << endl;
	cout << doub_S.val << endl;
	cout << str_S.val << endl;
	for(int i : vec_S.val)
	cout << i <<" ";
	*/
    // task 8 do 4 but use get() instead 
	cout << int_S.get()<<endl;
	cout << char_S.get() << endl;
	cout << doub_S.get() << endl;
	cout << str_S.get() << endl;
	for(int i : vec_S.get())
	cout << i <<" ";
	cout << endl;
	// task 13 use read_val to read into each var from 3 except vec_S
	int i1; read_val(i1); S<int> i1S(i1);
	double d1; read_val(d1); S<double> d1S(d1);
	char c1; read_val(c1); S<char> c1S(c1);
	cout << i1S.get() << endl;
	cout << d1S.get() << endl;
	cout << c1S.get() << endl;
	 
	return 0;
    // --- end --- 
}

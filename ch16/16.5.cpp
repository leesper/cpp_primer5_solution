#include <iostream>
using namespace std;

template<typename T, unsigned N>
void print(T (&arr)[N])
{
	for (auto e : arr)
		cout << e << endl;
}

template<typename T, unsigned N>
T *mybegin(T (&arr)[N])
{
	return arr;
}

template<typename T, unsigned N>
T *myend(T (&arr)[N])
{
	return arr + N;
}

template<typename T, unsigned N>
constexpr unsigned array_size(T (&arr)[N])
{
	return N;
}

int main()
{
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	print(array);
	for (auto ptr = mybegin(array); ptr != myend(array); ++ptr)
		cout << *ptr * 2 << " ";
	cout << endl;
	cout << "array size: " << array_size(array) << endl;
	return 0;
}

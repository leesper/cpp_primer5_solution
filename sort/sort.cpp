#include <iostream>
#include <random>
#include <stdexcept>
using namespace std;

int randomInRange(int start, int end)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(start, end);
	return dist(gen);
}

int partition(int *data, int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
		throw new runtime_error("passing invalid parameters");

	int index = randomInRange(start, end);
	swap(data[index], data[end]);
	int small = start - 1;
	for (index = start; index != end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				swap(data[small], data[index]);
		}
	}
	++small;
	swap(data[end], data[small]);
	return small;
}

void quicksort(int *data, int length, int start, int end)
{
	if (start == end)
		return;

	int index = partition(data, length, start, end);
	if (index > start)
		quicksort(data, length, start, index - 1);
	if (index < end)
		quicksort(data, length, index + 1, end);
}

int main()
{
	int data[] = {3, 9, 4, 6, 8, 3, 5, 1, 8};
	//cout << randomInRange(0, 10) << " " << randomInRange(4, 20) << endl;
	quicksort(data, 9, 0, 8);
	for (int i = 0; i != 9; ++i)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}

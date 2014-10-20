/*
 creating 4 threads each with id 0, 1, 2, 3
 then executing them in order 0, 1, 2, 3...
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cstddef>
using namespace std;

int order = 0;
constexpr int NUM = 4;
mutex mtx;
condition_variable cv;

void print_id(int id)
{
	this_thread::sleep_for(chrono::milliseconds(4 - id));
	for (int i = 0; i != 10; ++i)
	{
		unique_lock<mutex> lock(mtx);
		while (order != id)
		{
			cv.wait(lock);
		}
		cout << "threading " << id << endl;
		order = (order + 1) % NUM;
		cv.notify_all();
	}

}

int main()
{
	thread threads[NUM];
	for (size_t i = 0; i < NUM; i++)
		threads[i] = thread(print_id, i);

	//cout << NUM << " threads running" << endl;

	for (auto &t : threads)
		t.join();

	return 0;
}

/*
sub thread printing 15 times, then main thread printing 10 times, then sub thread ... 
do it alternatively 3 times
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool is_sub = true;

void sub_thread_routine()
{
	for (int i = 0; i != 3; ++i)
	{
		std::unique_lock<std::mutex> lock(mtx);
		if (!is_sub)
			cv.wait(lock);
		for (int j = 0; j != 15; ++j)
			std::cout << "sub threading " << j + 1 << std::endl;
		is_sub = false;
		cv.notify_one();
	}
}

int main()
{
	std::thread sub_thread(sub_thread_routine);

	for (int i = 0; i != 3; ++i)
	{
		std::unique_lock<std::mutex> lock(mtx);
		if (is_sub)
			cv.wait(lock);
		for (int j = 0; j != 10; ++j)
			std::cout << "threading " << j + 1 << std::endl;
		is_sub = true;
		cv.notify_one();
	}
	sub_thread.join();
	return 0;
}
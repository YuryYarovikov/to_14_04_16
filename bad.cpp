#include <iostream>
#include <cstdio>
#include <chrono>
#include <thread>

void increase(int* a) {
	for (int i = 0; i < 1000000; ++i) {
		++(*a);
	}
}

struct bad {
	int a;
	int b;
};

int main() {
	freopen("output.txt", "a", stdout);
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    bad b;

	std::thread t_1(increase, &(b.a));
	std::thread t_2(increase, &(b.b));
	t_1.join();
	t_2.join();

	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;
	return 0;
}
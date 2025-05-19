#include "Singleton.h"

#include <future>

int main() {
	// スレッドセーフでない生成
	//auto th1_unsafe = std::thread([] {Singleton::getInstance(); });
	//auto th2_unsafe = std::thread([] {Singleton::getInstance(); });n
	//th1_unsafe.join();
	//th2_unsafe.join();

	std::mutex mtx;
	auto th1 = std::thread([&] {Singleton::getThreadSafeInstance(mtx); });
	auto th2 = std::thread([&] {Singleton::getThreadSafeInstance(mtx); });
	th1.join();
	th2.join();

	return 0;
}
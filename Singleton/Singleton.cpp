#include "Singleton.h"
#include <future>
#include <iostream>

Singleton* Singleton::mpInstance = nullptr;

Singleton& Singleton::getInstance()
{	
	if (mpInstance == nullptr)
	{
		std::cout << "生成されました" << std::endl;
		mpInstance = new Singleton();
	}
	return *mpInstance;
}

Singleton* Singleton::getThreadSafeInstance(std::mutex& mtx)
{
	// ガードを張るか
	// static Singleton instance
	// を行う

	std::lock_guard<std::mutex> lock(mtx);
	if (mpInstance == nullptr)
	{
		std::cout << "生成されました" << std::endl;
		mpInstance = new Singleton();
	}
	return nullptr;
}

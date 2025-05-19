#include "Singleton.h"
#include <future>
#include <iostream>

Singleton* Singleton::mpInstance = nullptr;

Singleton& Singleton::getInstance()
{	
	if (mpInstance == nullptr)
	{
		std::cout << "¶¬‚³‚ê‚Ü‚µ‚½" << std::endl;
		mpInstance = new Singleton();
	}
	return *mpInstance;
}

Singleton* Singleton::getThreadSafeInstance(std::mutex& mtx)
{
	// ƒK[ƒh‚ð’£‚é‚©
	// static Singleton instance
	// ‚ðs‚¤

	std::lock_guard<std::mutex> lock(mtx);
	if (mpInstance == nullptr)
	{
		std::cout << "¶¬‚³‚ê‚Ü‚µ‚½" << std::endl;
		mpInstance = new Singleton();
	}
	return nullptr;
}

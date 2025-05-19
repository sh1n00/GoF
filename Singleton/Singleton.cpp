#include "Singleton.h"
#include <future>
#include <iostream>

Singleton* Singleton::mpInstance = nullptr;

Singleton& Singleton::getInstance()
{	
	if (mpInstance == nullptr)
	{
		std::cout << "��������܂���" << std::endl;
		mpInstance = new Singleton();
	}
	return *mpInstance;
}

Singleton* Singleton::getThreadSafeInstance(std::mutex& mtx)
{
	// �K�[�h�𒣂邩
	// static Singleton instance
	// ���s��

	std::lock_guard<std::mutex> lock(mtx);
	if (mpInstance == nullptr)
	{
		std::cout << "��������܂���" << std::endl;
		mpInstance = new Singleton();
	}
	return nullptr;
}

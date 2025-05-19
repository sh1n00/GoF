#pragma once

#include <iostream>

class IObserver
{
public:
	IObserver() = default;
	virtual ~IObserver() = default;

public:
	virtual void update() = 0;

};

class Observer : public IObserver
{
public:
	void update() override
	{
		std::cout << "Notify: " << typeid(*this).hash_code() << std::endl;
	}
};
#pragma once

#include <future>

class Singleton
{
public:
	static Singleton& getInstance();

	static Singleton* getThreadSafeInstance(std::mutex& mtx);

public:
	Singleton(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;

	void operator=(const Singleton&) = delete;

private:
	static Singleton* mpInstance;
private:
	Singleton() = default;
	~Singleton() = default;
};
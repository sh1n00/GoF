#pragma once

#include <vector>

class IObserver;

class Publisher {
public:
	Publisher() = default;
	~Publisher() = default;

public:
	void addObserver(IObserver& observer);
	void notifyAll();

private:
	std::vector<IObserver*> mObserverVector{};
};
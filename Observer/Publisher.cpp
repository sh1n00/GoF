#include "Publisher.h"

#include "IObserver.h"

// --------------------------------------------------
void Publisher::addObserver(IObserver& observer)
{
	mObserverVector.push_back(&observer);
}

// --------------------------------------------------
void Publisher::notifyAll()
{
	for (auto* observer : mObserverVector)
	{
		observer->update();
	}
}

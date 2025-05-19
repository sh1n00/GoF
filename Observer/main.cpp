#include "Publisher.h"
#include "IObserver.h"


int main()
{
	Observer ob1;
	Observer ob2;
	Observer ob3;

	Publisher publisher;
	publisher.addObserver(ob1);
	publisher.addObserver(ob2);
	publisher.addObserver(ob3);

	publisher.notifyAll();

	return 0;
}
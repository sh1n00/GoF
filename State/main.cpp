#include "State.h"

int main() {
	Context* context = new Context(new NoCoinState);
	context->ejectCoin();
	context->insertCoin();
	context->pressButton();
	context->dispense();
	return 0;
}
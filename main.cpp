#include <iostream>


class Context {
public:
	Context(State* state) : mState(nullptr) {

	}
	~Context() {
		delete mState;
	}
public:
	void TransitionTo(State* state)
	{
		std::cout << "Context: Trainsition to " << typeid(*state).name() << std::endl;
		if (mState)
		{
			delete mState;
			mState = state;
			mState->setContext(this);
		}
	}

private:
	State* mState = nullptr;
};

class State
{
public:
	virtual ~State() {};

public:
	void setContext(Context* context) { mContext = context; }

public:
	virtual void doThis() = 0;
	virtual void doThat() = 0;

protected:
	Context* mContext = nullptr;
};


int main()
{
	return 0;
}
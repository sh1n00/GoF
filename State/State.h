#pragma once

#include <iostream>

class Context;

// -------------------------------------------------------------------
class State
{
public:
	State() = default;
	virtual ~State() {};

public:
	void setContext(Context* context) { mContext = context; }

	virtual void insertCoin() = 0;
	virtual void ejectCoin() = 0;
	virtual void pressButton() = 0;
	virtual void dispense() = 0;

protected:
	Context* mContext = nullptr;
};

// -------------------------------------------------------------------
class Context {
public:
	Context(State* state) : mState(nullptr) {
		TransitionTo(state);
	}

	virtual ~Context() {
		delete mState;
	}
public:
	void TransitionTo(State* state)
	{
		std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
		if (mState != nullptr)
		{
			delete mState;
		}
		mState = state;
		mState->setContext(this);
	}

	virtual void insertCoin();
	virtual void ejectCoin();
	virtual void pressButton();
	virtual void dispense();

protected:
	State* mState = nullptr;
};


// -------------------------------------------------------------------
class NoCoinState : public State {
public:
	void insertCoin() override;
	void ejectCoin() override;
	void pressButton() override;
	void dispense() override;

};

// -------------------------------------------------------------------
class HasCoinState : public State {
public:
	void insertCoin() override;
	void ejectCoin() override;
	void pressButton() override;
	void dispense() override;
};

// -------------------------------------------------------------------
class SoldState : public State {
public:
	void insertCoin() override;
	void ejectCoin() override;
	void pressButton() override;
	void dispense() override;
};

// -------------------------------------------------------------------
class SoldOutState : public State {
public:
	void insertCoin() override;
	void ejectCoin() override;
	void pressButton() override;
	void dispense() override;
};
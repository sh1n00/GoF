#include "State.h"

// -------------------------------------------------------------------
void Context::insertCoin()
{
	mState->insertCoin();	
};

// -------------------------------------------------------------------
void Context::ejectCoin()
{
	mState->ejectCoin();
}

// -------------------------------------------------------------------
void Context::pressButton()
{
	mState->pressButton();	
}

// -------------------------------------------------------------------
void Context::dispense()
{
	mState->dispense();
}

// -------------------------------------------------------------------
void NoCoinState::insertCoin()
{
	mContext->TransitionTo(new HasCoinState);
}

// -------------------------------------------------------------------
void NoCoinState::ejectCoin()
{
	std::cout << "コインは入っていません" << std::endl;
}

// -------------------------------------------------------------------
void NoCoinState::pressButton()
{
	std::cout << "コインを入れてください" << std::endl;
}


// -------------------------------------------------------------------
void NoCoinState::dispense()
{

}

// -------------------------------------------------------------------
void HasCoinState::insertCoin()
{
	std::cout << "すでにコインが入っています" << std::endl;
}

// -------------------------------------------------------------------
void HasCoinState::ejectCoin()
{
	mContext->TransitionTo(new NoCoinState);
}

// -------------------------------------------------------------------
void HasCoinState::pressButton()
{
	mContext->TransitionTo(new SoldState);
}


// -------------------------------------------------------------------
void HasCoinState::dispense()
{

}

// -------------------------------------------------------------------
void SoldState::insertCoin()
{
	std::cout << "販売中です" << std::endl;
}

// -------------------------------------------------------------------
void SoldState::ejectCoin()
{
	std::cout << "販売中のため返金できません" << std::endl;
}

// -------------------------------------------------------------------
void SoldState::pressButton()
{
	std::cout << "すでに商品を出しています" << std::endl;
}

// -------------------------------------------------------------------
void SoldState::dispense()
{

}

// -------------------------------------------------------------------
void SoldOutState::insertCoin()
{
	std::cout << "売り切れ" << std::endl;
}

// -------------------------------------------------------------------
void SoldOutState::ejectCoin()
{
	std::cout << "売り切れ" << std::endl;
}

// -------------------------------------------------------------------
void SoldOutState::pressButton()
{
	std::cout << "売り切れ" << std::endl;
}


// -------------------------------------------------------------------
void SoldOutState::dispense()
{
	std::cout << "売り切れ" << std::endl;
}
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
	std::cout << "�R�C���͓����Ă��܂���" << std::endl;
}

// -------------------------------------------------------------------
void NoCoinState::pressButton()
{
	std::cout << "�R�C�������Ă�������" << std::endl;
}


// -------------------------------------------------------------------
void NoCoinState::dispense()
{

}

// -------------------------------------------------------------------
void HasCoinState::insertCoin()
{
	std::cout << "���łɃR�C���������Ă��܂�" << std::endl;
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
	std::cout << "�̔����ł�" << std::endl;
}

// -------------------------------------------------------------------
void SoldState::ejectCoin()
{
	std::cout << "�̔����̂��ߕԋ��ł��܂���" << std::endl;
}

// -------------------------------------------------------------------
void SoldState::pressButton()
{
	std::cout << "���łɏ��i���o���Ă��܂�" << std::endl;
}

// -------------------------------------------------------------------
void SoldState::dispense()
{

}

// -------------------------------------------------------------------
void SoldOutState::insertCoin()
{
	std::cout << "����؂�" << std::endl;
}

// -------------------------------------------------------------------
void SoldOutState::ejectCoin()
{
	std::cout << "����؂�" << std::endl;
}

// -------------------------------------------------------------------
void SoldOutState::pressButton()
{
	std::cout << "����؂�" << std::endl;
}


// -------------------------------------------------------------------
void SoldOutState::dispense()
{
	std::cout << "����؂�" << std::endl;
}
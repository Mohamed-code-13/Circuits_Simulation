#include "include/StateMachine.h"

void StateMachine::changeState(std::unique_ptr<State> newState)
{
	this->m_newState = std::move(newState);
	this->m_isChanging = true;
}

void StateMachine::ProcessStateChanges()
{
	if (this->m_isChanging)
	{
		this->m_newState->Init();
		this->m_isChanging = false;
	}
}

std::unique_ptr<State>& StateMachine::GetState()
{
	return this->m_newState;
}
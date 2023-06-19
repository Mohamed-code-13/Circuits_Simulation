#pragma once
#include <memory>
#include "State.h"

class StateMachine
{
private:
	std::unique_ptr<State> m_newState;
	bool m_isChanging = false;

public:
	void changeState(std::unique_ptr<State> newState);
	void ProcessStateChanges();
	std::unique_ptr<State>& GetState();
};
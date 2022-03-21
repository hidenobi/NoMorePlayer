#pragma once
#include"HitBox.h"
#include "../GameManager/ResourceManager.h"
#include "IPState.h"
class IPlayer
{
public:
	
	virtual void changeNextState(IPState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
};


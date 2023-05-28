#pragma once
#include "Buttons.h"

//Responsible for the greedy algorithm button.

class GreedyButton :public Buttons
{
public:
	GreedyButton() ;
	Algoritem turnOnButton() override;

};

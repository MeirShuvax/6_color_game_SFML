#pragma once
#include "Buttons.h"

//Responsible for the Radnomal Algorithm button

class RandomButton :public Buttons
{
public:
	RandomButton();
	Algoritem turnOnButton() override;
};

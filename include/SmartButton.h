#pragma once
#include "Buttons.h"

//Responsible for the smart algorithm button

class SmartButton :public Buttons
{
public:
	SmartButton();
	Algoritem turnOnButton() override;

};

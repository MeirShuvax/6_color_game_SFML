#pragma once
#include "UserPlayer.h"
#include "Menu.h"
#include "ComputerPlayer.h"
#include "NewGameButton.h"
#include <windows.h>


//Responsible for the actual game, managing the course of the game and more.

class Game
{
public:
	Game();
	~Game() = default;
	void run();
	
private:
	template <typename T>
	void victoryManager(Board<T>& board) const;
	template <typename T>
	void eventsManager(Board<T>& board);
	template <typename T>
	void sleepAndrestart(Board<T>& board) const;

	UserPlayer m_userPlayer;
	ComputerPlayer m_computerPlayer;
	Menu m_menu;
	NewGameButton m_newButton;
};

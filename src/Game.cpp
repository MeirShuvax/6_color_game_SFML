#include "Game.h"
#include "Board.h"

Game::Game() :
	m_userPlayer(), m_menu(), m_computerPlayer()
{}
//===============================================
void Game::run()
{
	Board<HexagonalShape> board;

	m_menu.openMenu(board.getWindow());
	m_computerPlayer.setAlgoritem(m_menu.getAlgoritem());


	//run on the game and make the moves
	while (board.getWindow()->isOpen())
	{
		board.getWindow()->clear();

		eventsManager(board);
		board.blinkBoard(m_userPlayer.getTurnStatus() ? COMPUTER : PLAYER);
		board.printBoard();
		m_newButton.drowButton(board.getWindow());
		m_userPlayer.myTurn(board, m_computerPlayer.getLastColor());
		m_userPlayer.printPrecent(board.getWindow());
		if (m_userPlayer.getTurnStatus())
		{
			m_computerPlayer.myTurn(board, m_userPlayer.getLastColor());
			board.updatForbiddenColor(m_userPlayer.getLastColor(), m_computerPlayer.getLastColor());

		}
		m_computerPlayer.printPrecent(board.getWindow());

		victoryManager(board);

		board.getWindow()->display();
	}


}
//===============================================
template <typename T>
void Game::eventsManager(Board<T>& board)
{
	for (auto event = sf::Event{}; board.getWindow()->pollEvent(event);)
	{
		switch (event.type)
		{

		case sf::Event::Closed:
			board.getWindow()->close();
			break;

		case sf::Event::MouseMoved:
			if (m_newButton.isButtonPressed(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
				m_newButton.highlightsButton();
			else
				m_newButton.resetHighlightsButton();
			break;

		case sf::Event::MouseButtonPressed:
			if (m_newButton.isButtonPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			{
				board.getWindow()->close();
				Game().run();
				break;
			}
		}
	}
}
//===============================================
template <typename T>
void Game::victoryManager(Board<T>& board) const
{
	if (m_computerPlayer.checkVictory())
	{
		m_computerPlayer.printVictory(board.getWindow());
		sleepAndrestart(board);
	}

	if (m_userPlayer.checkVictory())
	{
		m_userPlayer.printVictory(board.getWindow());
		sleepAndrestart(board);
	}
}
//===============================================
template <typename T>
void Game::sleepAndrestart(Board<T>& board) const
{
	board.getWindow()->display();
	Sleep(5000);
	board.getWindow()->close();
	Game().run();
}


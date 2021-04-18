/*
	+-------------------------------+
	|	Player Character Select		|
	+-------------------------------+
	|	\file playerselect.h		|
	|	\defines __PLAYERSELECT__	|
	|	\class PlayerSelect			|
	+-------------------------------+
*/

#ifndef __PLAYERSELECT__
#define __PLAYERSELECT__

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// Includes
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
#include <SFML/Graphics.hpp>
#include <vector>
#include "player.h"

class PlayerSelect
{
private:
	std::unique_ptr<Player> m_pWoodCutter;
	std::unique_ptr<Player> m_pGraveRobber;
	std::unique_ptr<Player> m_pSteamMan;


public:
	PlayerSelect(float, float);

	void draw(sf::RenderWindow&);	
};

#endif
#include "playerselect.h"

PlayerSelect::PlayerSelect(float width, float height)
{
	m_pWoodCutter = std::make_unique<Player>(PLAYER_TYPE_WOODCUTTER);
	m_pWoodCutter->setOrigin(sf::Vector2f(m_pWoodCutter->getTextureRect().width / 2, m_pWoodCutter->getTextureRect().height / 2));

	m_pGraveRobber = std::make_unique<Player>(PLAYER_TYPE_GRAVEROBBER);
	m_pGraveRobber->setOrigin(sf::Vector2f(m_pWoodCutter->getTextureRect().width / 2, m_pWoodCutter->getTextureRect().height / 2));

	m_pSteamMan = std::make_unique<Player>(PLAYER_TYPE_STEAMMAN);
	m_pSteamMan->setOrigin(sf::Vector2f(m_pWoodCutter->getTextureRect().width / 2, m_pWoodCutter->getTextureRect().height / 2));
}

void PlayerSelect::draw(sf::RenderWindow& window)
{

}
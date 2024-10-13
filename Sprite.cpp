#include "Sprite.h"
#include "Graphics.h"

bool mySprite::Create(sf::Texture* texture, const SpriteSettings& settings)
{
	m_settings = settings;
	m_sprite.setTexture(*texture);
	return true;
}

void mySprite::Draw(int x, int y, int frameNumber, sf::RenderWindow& window)
{
 
	window.draw(m_sprite);
}

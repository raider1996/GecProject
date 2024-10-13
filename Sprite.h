#pragma once
# include <string>
#include<SFML/Graphics.hpp>
struct SpriteSettings
	{
		int numFrames{ 1 };
		int frameWidth{ 0 };
		int frameHight{ 0 };
		std::string textureFilename;
		bool vertical{ true };
	};
class mySprite
{
private:
	SpriteSettings m_settings;
	sf::Sprite m_sprite;
public:
	bool Create(sf::Texture* texture, const SpriteSettings& settings);

	void Draw(int x, int y, int frameNumber, sf::RenderWindow& window);
};


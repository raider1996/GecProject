#pragma once

# include <SFML/Graphics.hpp>
# include <unordered_map>
#include "Sprite.h"

class Sprite;
namespace sf {
	class Texture;
}
class Graphics
{
public:
	sf::Texture& getTexture(const std::string& filePath);
	void UnloadTexture(const std::string& filePath);
	void ClearAll();
	bool CreateSprite(const std::string& name, const SpriteSettings& settings);
	void RenderSprite(const std::string& name, int x, int y, int frameNumber, sf::RenderWindow& window);
	mySprite* newSprite = new mySprite;
	//newSprite->Create(texture, settings);
	std::string key = "idle";
	//m_spriteMap[key] = newSprite;
private:
	std::map<std::string, sf::Texture> textureMap;
	std::unordered_map <std::string, mySprite*> m_spriteMap;
	std::unordered_map <std::string, sf::Texture*> m_textureMap;
};


#include "Graphics.h"
#include "Sprite.h"
#include "SFML/Graphics.hpp"
#include <string>
#include <map>
using namespace sf;

    //TextureManager
    sf::Texture& Graphics::getTexture(const std::string& filePath)
    {
        if (textureMap.find(filePath) == textureMap.end())
        {
            sf::Texture tempTexture;
            if (!tempTexture.loadFromFile(filePath))
            {
                //tempTexture did not load
            }
            textureMap[filePath] = tempTexture;
        }
        return textureMap[filePath];
    }//load unloaded textures, return the reference texture

    void Graphics::UnloadTexture(const std::string& filePath)
    {
        auto unwanted = textureMap.find(filePath);
        if (unwanted != textureMap.end())
        {
            textureMap.erase(unwanted);
        }
    }//unload textures to free memory

    void Graphics::ClearAll()
    {
        textureMap.clear();
    }
    bool Graphics::CreateSprite(const std::string& name, const SpriteSettings& settings)
    {
        for (auto p : m_textureMap)
            delete p.second;



        sf::Texture* texture{ nullptr };
        if (m_textureMap.find(settings.textureFilename) == m_textureMap.end())
        {
            Texture* newTexture = new sf::Texture();

            if (!newTexture->loadFromFile(settings.textureFilename))
            {
                //failed to load
                return false;
            }

            m_textureMap[settings.textureFilename] = newTexture;

        }
        texture = m_textureMap[settings.textureFilename];

        //mySprite* newSprite = new mySprite;
        newSprite->Create(texture, settings);
        //std::string key = "idle";
        m_spriteMap[key]=newSprite;

    }
    void Graphics::RenderSprite(const std::string& name, int x, int y, int frameNumber, sf::RenderWindow& window )
    {
        if (m_spriteMap.find(name) == m_spriteMap.end())
        {
            "could not find sprite name";
            return;
        }
        m_spriteMap[name]->Draw(x, y, frameNumber, window);
    }
    
    //clear textureMap. 

